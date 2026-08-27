#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "esp_err.h"
#include "esp_log.h"
#include "esp_rom_sys.h"
#include "esp_spiffs.h"

#define PIN_SPI_SCLK           18
#define PIN_SPI_MOSI           23
#define PIN_SPI_MISO           19
#define PIN_SPI_CS             5

#define MAX_SAMPLES   500

typedef struct {
    uint8_t cs[MAX_SAMPLES];
    uint8_t sclk[MAX_SAMPLES];
    uint8_t mosi[MAX_SAMPLES];
    uint8_t miso[MAX_SAMPLES];
    uint16_t sample_count;
} spi_trace_t;

static spi_trace_t trace;

uint8_t bb_spi_transfer_byte(uint8_t data_out);
void bb_spi_transfer_string(const char *str);

static inline void record_sample(void) {
    if (trace.sample_count < MAX_SAMPLES) {
        trace.cs[trace.sample_count]   = gpio_get_level(PIN_SPI_CS);
        trace.sclk[trace.sample_count] = gpio_get_level(PIN_SPI_SCLK);
        trace.mosi[trace.sample_count] = gpio_get_level(PIN_SPI_MOSI);
        trace.miso[trace.sample_count] = gpio_get_level(PIN_SPI_MISO);
        trace.sample_count++;
    }
}

uint8_t bb_spi_transfer_byte(uint8_t data_out) {
    uint8_t data_in = 0;
    for (int bit = 7; bit >= 0; bit--) {
        gpio_set_level(PIN_SPI_MOSI, (data_out >> bit) & 0x01);
        record_sample();
        esp_rom_delay_us(2);

        gpio_set_level(PIN_SPI_SCLK, 1);
        record_sample();
        esp_rom_delay_us(2);

        data_in <<= 1;
        if (gpio_get_level(PIN_SPI_MISO)) {
            data_in |= 0x01;
        }

        gpio_set_level(PIN_SPI_SCLK, 0);
        record_sample();
        esp_rom_delay_us(2);
    }
    return data_in;
}

void bb_spi_transfer_string(const char *str) {
    while (*str) {
        bb_spi_transfer_byte((uint8_t)(*str));
        str++;
    }
}

esp_err_t init_spiffs(void) {
    esp_vfs_spiffs_conf_t conf = {
        .base_path = "/spiffs",
        .partition_label = NULL,
        .max_files = 2,
        .format_if_mount_failed = true
    };
    
    esp_err_t ret = esp_vfs_spiffs_register(&conf);
    if (ret != ESP_OK) {
        ESP_LOGE("SPIFFS", "Failed to mount SPIFFS (%s)", esp_err_to_name(ret));
        return ret;
    }
    ESP_LOGI("SPIFFS", "SPIFFS Mounted Successfully");
    return ESP_OK;
}

void dump_trace_to_file(const char *filepath) {
    FILE *f = fopen(filepath, "w");
    if (f == NULL) {
        ESP_LOGE("FILE", "Failed to open file for writing! Check partition scheme.");
        return;
    }

    fprintf(f, "Sample,CS,SCLK,MOSI,MISO\n");
    for (int i = 0; i < trace.sample_count; i++) {
        fprintf(f, "%d,%d,%d,%d,%d\n", i, trace.cs[i], trace.sclk[i], trace.mosi[i], trace.miso[i]);
    }

    fclose(f);
    ESP_LOGI("FILE", "Dump complete!");
}

void main_task(void *pvParameters) {
    if (init_spiffs() != ESP_OK) {
        vTaskDelete(NULL);
        return;
    }

    gpio_reset_pin(PIN_SPI_SCLK);
    gpio_reset_pin(PIN_SPI_MOSI);
    gpio_reset_pin(PIN_SPI_CS);
    gpio_reset_pin(PIN_SPI_MISO);

    gpio_config_t out_conf = {
        .pin_bit_mask = (1ULL << PIN_SPI_SCLK) | (1ULL << PIN_SPI_MOSI) | (1ULL << PIN_SPI_CS),
        .mode = GPIO_MODE_INPUT_OUTPUT,
    };
    gpio_config(&out_conf);

    gpio_config_t in_conf = {
        .pin_bit_mask = (1ULL << PIN_SPI_MISO),
        .mode = GPIO_MODE_INPUT,
        .pull_up_en = GPIO_PULLUP_ENABLE,
    };
    gpio_config(&in_conf);

    gpio_set_level(PIN_SPI_CS, 1);
    gpio_set_level(PIN_SPI_SCLK, 0);

    const char *test_str = "ABDUL";

    while (1) {
        trace.sample_count = 0;

        gpio_set_level(PIN_SPI_CS, 0);
        record_sample();

        bb_spi_transfer_string(test_str);

        gpio_set_level(PIN_SPI_CS, 1);
        gpio_set_level(PIN_SPI_MOSI, 0);
        record_sample();

        dump_trace_to_file("D:/ESP32/ESP32_ST7789_I80/main/trace.csv");

        vTaskDelay(pdMS_TO_TICKS(5000));
    }
}

void app_main(void) {
    // Run inside a dedicated task with 8KB stack space to avoid stack overflow crashes
    xTaskCreate(main_task, "main_task", 8192, NULL, 5, NULL);
}