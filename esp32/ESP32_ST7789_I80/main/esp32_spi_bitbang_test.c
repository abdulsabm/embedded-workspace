#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "esp_log.h"

// _________________________________________________________
// along with the displya connection, short the pin 19 and 23 
// for accurate data transfer in loop ba ck.
// _________________________________________________________
// Define GPIO Pins (Adjust these to match your wiring)
#define PIN_SPI_SCLK    18  // Serial Clock
#define PIN_SPI_MOSI    23  // Master Out Slave In
#define PIN_SPI_MISO    19  // Master In Slave Out
#define PIN_SPI_CS      5   // Chip Select

// Timing delay in microseconds for SPI clock speed control
#define SPI_CLOCK_DELAY_US  1 

// SPI Mode 0 Helper Macro (Delay)
static inline void spi_delay(void) {
    esp_rom_delay_us(SPI_CLOCK_DELAY_US);
}

// Initialize GPIO pins for Bit-Banging SPI
void bb_spi_init(void) {
    gpio_config_t io_conf = {
        .pin_bit_mask = (1ULL << PIN_SPI_SCLK) | (1ULL << PIN_SPI_MOSI) | (1ULL << PIN_SPI_CS),
        .mode = GPIO_MODE_OUTPUT,
        .pull_up_en = GPIO_PULLUP_DISABLE,
        .pull_down_en = GPIO_PULLDOWN_DISABLE,
        .intr_type = GPIO_INTR_DISABLE,
    };
    gpio_config(&io_conf);

    gpio_config_t miso_conf = {
        .pin_bit_mask = (1ULL << PIN_SPI_MISO),
        .mode = GPIO_MODE_INPUT,
        .pull_up_en = GPIO_PULLUP_ENABLE, // Pull up MISO line
        .pull_down_en = GPIO_PULLDOWN_DISABLE,
        .intr_type = GPIO_INTR_DISABLE,
    };
    gpio_config(&miso_conf);

    // Set Default Idle States (SPI Mode 0: CPOL=0, CPHA=0)
    gpio_set_level(PIN_SPI_CS, 1);   // CS High (Idle/Deselected)
    gpio_set_level(PIN_SPI_SCLK, 0); // Clock Low (Idle)
    gpio_set_level(PIN_SPI_MOSI, 0); // Data Low
}

// Bit-Bang Transfer: Sends 1 byte while reading 1 byte (SPI Mode 0, MSB First)
uint8_t bb_spi_transfer_byte(uint8_t data_out) {
    uint8_t data_in = 0;

    for (int bit = 7; bit >= 0; bit--) {
        // 1. Setup MOSI (MSB First)
        gpio_set_level(PIN_SPI_MOSI, (data_out >> bit) & 0x01);
        spi_delay();

        // 2. Rising Edge on Clock (Slave samples MOSI)
        gpio_set_level(PIN_SPI_SCLK, 1);
        spi_delay();

        // 3. Read MISO sample bit on clock high
        data_in <<= 1;
        if (gpio_get_level(PIN_SPI_MISO)) {
            data_in |= 0x01;
        }

        // 4. Falling Edge on Clock
        gpio_set_level(PIN_SPI_SCLK, 0);
        spi_delay();
    }

    return data_in;
}

// High-level wrapper to write a block of data
void bb_spi_write_bytes(const uint8_t *data, size_t len) {
    gpio_set_level(PIN_SPI_CS, 0); // Select Slave
    spi_delay();

    for (size_t i = 0; i < len; i++) {
        bb_spi_transfer_byte(data[i]);
    }

    spi_delay();
    gpio_set_level(PIN_SPI_CS, 1); // Deselect Slave
}

// Main Application
void app_main(void) {
    ESP_LOGI("SPI_BB", "Initializing Bit-Bang SPI...");
    bb_spi_init();

    uint8_t test_payload[] = {0xAA, 0x55, 0xF0, 0x0F};

    while (1) {
        ESP_LOGI("SPI_BB", "Sending test frame...");

        gpio_set_level(PIN_SPI_CS, 0); // Select Slave
        for (int i = 0; i < sizeof(test_payload); i++) {
            uint8_t received = bb_spi_transfer_byte(test_payload[i]);
            ESP_LOGI("SPI_BB", "Sent: 0x%02X | Received: 0x%02X", test_payload[i], received);
        }
        gpio_set_level(PIN_SPI_CS, 1); // Deselect Slave

        vTaskDelay(pdMS_TO_TICKS(2000));
    }
}