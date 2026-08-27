// Control Pins (5 Wires)
// •	LCD_CS (Chip Select) $\rightarrow$ GPIO 15
// •	LCD_RS / DC (Data / Command) $\rightarrow$ GPIO 2
// •	LCD_WR (Write Strobe) $\rightarrow$ GPIO 4
// •	LCD_RD (Read Strobe) $\rightarrow$ GPIO 32
// •	LCD_RST (Reset) $\rightarrow$ GPIO 33
// Data Pins (8 Wires)
// •	LCD_D0 $\rightarrow$ GPIO 12
// •	LCD_D1 $\rightarrow$ GPIO 13
// •	LCD_D2 $\rightarrow$ GPIO 26
// •	LCD_D3 $\rightarrow$ GPIO 25
// •	LCD_D4 $\rightarrow$ GPIO 17 (Labeled TX2 on board)
// •	LCD_D5 $\rightarrow$ GPIO 16 (Labeled RX2 on board)
// •	LCD_D6 $\rightarrow$ GPIO 27
// •	LCD_D7 $\rightarrow$ GPIO 14
// Power Pins (3 Wires)
// •	VCC / 5V $\rightarrow$ VIN / 5V on ESP32
// •	GND $\rightarrow$ GND on ESP32
// •	LED / BL (Backlight) $\rightarrow$ 3.3V or 5V

#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_heap_caps.h"
#include "esp_lcd_panel_io.h"
#include "esp_lcd_panel_vendor.h"
#include "esp_lcd_panel_ops.h"
#include "driver/gpio.h"
#include "esp_err.h"
#include "esp_log.h"

// Pin Definitions
#define PIN_NUM_DATA0          12
#define PIN_NUM_DATA1          13
#define PIN_NUM_DATA2          26
#define PIN_NUM_DATA3          25
#define PIN_NUM_DATA4          17
#define PIN_NUM_DATA5          16
#define PIN_NUM_DATA6          27
#define PIN_NUM_DATA7          14

#define PIN_NUM_PCLK           4   // LCD_WR
#define PIN_NUM_CS             15  // LCD_CS
#define PIN_NUM_DC             2   // LCD_RS / DC
#define PIN_NUM_RST            33  // LCD_RST
#define PIN_NUM_RD             32  // LCD_RD

void app_main(void)
{
    // Force a manual hardware reset pulse to clear display RAM static
    gpio_config_t rst_gpio_config = {
        .mode = GPIO_MODE_OUTPUT,
        .pin_bit_mask = (1ULL << PIN_NUM_RST) | (1ULL << PIN_NUM_RD)
    };
    gpio_config(&rst_gpio_config);
    
    // Hold RD High permanently
    gpio_set_level(PIN_NUM_RD, 1);
    
    // Hardware Reset Pulse
    gpio_set_level(PIN_NUM_RST, 0);
    vTaskDelay(pdMS_TO_TICKS(100));
    gpio_set_level(PIN_NUM_RST, 1);
    vTaskDelay(pdMS_TO_TICKS(100));

    ESP_LOGI("LCD", "Initializing Intel 8080 bus...");
    esp_lcd_i80_bus_handle_t i80_bus = NULL;
    esp_lcd_i80_bus_config_t bus_config = {
        .clk_src = LCD_CLK_SRC_DEFAULT,
        .dc_gpio_num = PIN_NUM_DC,
        .wr_gpio_num = PIN_NUM_PCLK,
        .data_gpio_nums = {
            PIN_NUM_DATA0, PIN_NUM_DATA1, PIN_NUM_DATA2, PIN_NUM_DATA3,
            PIN_NUM_DATA4, PIN_NUM_DATA5, PIN_NUM_DATA6, PIN_NUM_DATA7,
        },
        .bus_width = 8,
        .max_transfer_bytes = 320 * 20 * sizeof(uint16_t),
    };
    ESP_ERROR_CHECK(esp_lcd_new_i80_bus(&bus_config, &i80_bus));

    ESP_LOGI("LCD", "Installing panel IO...");
    esp_lcd_panel_io_handle_t io_handle = NULL;
    esp_lcd_panel_io_i80_config_t io_config = {
        .cs_gpio_num = PIN_NUM_CS,
        .pclk_hz = 2 * 1000 * 1000, // 2MHz clock speed
        .trans_queue_depth = 10,
        .dc_levels = {
            .dc_idle_level = 0,
            .dc_cmd_level = 0,
            .dc_dummy_level = 0,
            .dc_data_level = 1,
        },
        .lcd_cmd_bits = 8,
        .lcd_param_bits = 8,
    };
    ESP_ERROR_CHECK(esp_lcd_new_panel_io_i80(i80_bus, &io_config, &io_handle));

    ESP_LOGI("LCD", "Installing display driver...");
    esp_lcd_panel_handle_t panel_handle = NULL;
    esp_lcd_panel_dev_config_t panel_config = {
        .reset_gpio_num = PIN_NUM_RST,
        .rgb_endian = LCD_RGB_ENDIAN_BGR,
        .bits_per_pixel = 16,
    };

    // Built-in ST7789 driver
    ESP_ERROR_CHECK(esp_lcd_new_panel_st7789(io_handle, &panel_config, &panel_handle));

    // Reset and initialize screen
    ESP_ERROR_CHECK(esp_lcd_panel_reset(panel_handle));
    ESP_ERROR_CHECK(esp_lcd_panel_init(panel_handle));

    // 1. Swap axis/rotation to match full 320x240 screen area
    ESP_ERROR_CHECK(esp_lcd_panel_swap_xy(panel_handle, true));
    ESP_ERROR_CHECK(esp_lcd_panel_mirror(panel_handle, false, true));

    // 2. Fix inverted colors (Pink/Yellow/Cyan -> Red/Green/Blue)
    ESP_ERROR_CHECK(esp_lcd_panel_invert_color(panel_handle, true)); 

    ESP_ERROR_CHECK(esp_lcd_panel_disp_on_off(panel_handle, true));

    ESP_LOGI("LCD", "Display initialized! Filling screen...");

    // Allocate DMA buffer for 20 rows
    uint16_t *buffer = heap_caps_malloc(320 * 20 * sizeof(uint16_t), MALLOC_CAP_DMA);
    assert(buffer != NULL);

    uint16_t colors[] = {0xF800, 0x07E0, 0x001F}; // Red, Green, Blue
    int color_idx = 0;

    while (1) {
        for (int i = 0; i < 320 * 20; i++) {
            buffer[i] = colors[color_idx];
        }

        for (int y = 0; y < 240; y += 20) {
            esp_lcd_panel_draw_bitmap(panel_handle, 0, y, 320, y + 20, buffer);
        }

        color_idx = (color_idx + 1) % 3;
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}