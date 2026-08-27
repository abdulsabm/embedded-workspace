#include <stdio.h>
#include <string.h>
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

// Common RGB565 Color Definitions
#define COLOR_BLACK   0x0000
#define COLOR_WHITE   0xFFFF
#define COLOR_RED     0x00F8
#define COLOR_GREEN   0xE007
#define COLOR_BLUE    0x1F00
#define COLOR_YELLOW  0xE0FF
#define COLOR_CYAN    0xFF07

// Basic 8x16 ASCII Font Array (Characters 32 to 127)
static const uint8_t font8x16[96][16] = {
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},             // ' '
    {0,0,24,60,60,60,24,24,0,24,24,0,0,0,0,0},     // '!'
    {0,0,102,102,102,0,0,0,0,0,0,0,0,0,0,0},       // '"'
    {0,0,102,102,255,102,102,255,102,102,0,0,0,0}, // '#'
    {0,0,24,60,102,70,60,28,102,60,24,0,0,0,0,0},  // '$'
    {0,0,99,99,6,12,24,48,96,198,198,0,0,0,0,0},   // '%'
    {0,0,60,102,102,60,62,108,102,118,0,0,0,0,0},  // '&'
    {0,0,24,24,24,0,0,0,0,0,0,0,0,0,0,0},          // '\''
    {0,0,12,24,48,48,48,48,48,24,12,0,0,0,0,0},    // '('
    {0,0,48,24,12,12,12,12,12,24,48,0,0,0,0,0},    // ')'
    {0,0,0,102,60,255,60,102,0,0,0,0,0,0,0,0},     // '*'
    {0,0,0,24,24,126,24,24,0,0,0,0,0,0,0,0},       // '+'
    {0,0,0,0,0,0,0,0,24,24,24,48,0,0,0,0},         // ','
    {0,0,0,0,0,126,0,0,0,0,0,0,0,0,0,0},           // '-'
    {0,0,0,0,0,0,0,0,24,24,0,0,0,0,0,0},           // '.'
    {0,0,3,6,12,24,48,96,192,0,0,0,0,0,0,0},       // '/'
    {0,0,60,102,110,118,118,102,60,0,0,0,0,0,0,0}, // '0'
    {0,0,24,56,24,24,24,24,126,0,0,0,0,0,0,0},     // '1'
    {0,0,60,102,6,12,24,48,126,0,0,0,0,0,0,0},     // '2'
    {0,0,60,102,6,28,6,102,60,0,0,0,0,0,0,0},      // '3'
    {0,0,12,28,60,108,126,12,12,0,0,0,0,0,0,0},    // '4'
    {0,0,126,96,124,6,6,102,60,0,0,0,0,0,0,0},     // '5'
    {0,0,60,102,96,124,102,102,60,0,0,0,0,0,0,0},  // '6'
    {0,0,126,6,12,24,48,48,48,0,0,0,0,0,0,0},      // '7'
    {0,0,60,102,102,60,102,102,60,0,0,0,0,0,0,0},  // '8'
    {0,0,60,102,102,62,6,102,60,0,0,0,0,0,0,0},    // '9'
    {0,0,0,24,24,0,0,24,24,0,0,0,0,0,0,0},         // ':'
    {0,0,0,24,24,0,0,24,24,48,0,0,0,0,0,0},        // ';'
    {0,0,12,24,48,96,48,24,12,0,0,0,0,0,0,0},      // '<'
    {0,0,0,0,126,0,126,0,0,0,0,0,0,0,0,0},         // '='
    {0,0,48,24,12,6,12,24,48,0,0,0,0,0,0,0},       // '>'
    {0,0,60,102,6,12,24,0,24,0,0,0,0,0,0,0},       // '?'
    {0,0,60,102,110,110,108,96,62,0,0,0,0,0,0,0},  // '@'
    {0,0,24,60,102,102,126,102,102,0,0,0,0,0,0,0}, // 'A'
    {0,0,124,102,102,124,102,102,124,0,0,0,0,0,0,0},// 'B'
    {0,0,60,102,96,96,96,102,60,0,0,0,0,0,0,0},    // 'C'
    {0,0,120,108,102,102,102,108,120,0,0,0,0,0,0,0},// 'D'
    {0,0,126,96,96,120,96,96,126,0,0,0,0,0,0,0},   // 'E'
    {0,0,126,96,96,120,96,96,96,0,0,0,0,0,0,0},    // 'F'
    {0,0,60,102,96,110,102,102,62,0,0,0,0,0,0,0},  // 'G'
    {0,0,102,102,102,126,102,102,102,0,0,0,0,0,0,0},// 'H'
    {0,0,60,24,24,24,24,24,60,0,0,0,0,0,0,0},      // 'I'
    {0,0,30,12,12,12,12,108,56,0,0,0,0,0,0,0},     // 'J'
    {0,0,102,108,120,112,120,108,102,0,0,0,0,0,0,0},// 'K'
    {0,0,96,96,96,96,96,96,126,0,0,0,0,0,0,0},     // 'L'
    {0,0,102,119,127,107,102,102,102,0,0,0,0,0,0,0},// 'M'
    {0,0,102,118,126,126,110,102,102,0,0,0,0,0,0,0},// 'N'
    {0,0,60,102,102,102,102,102,60,0,0,0,0,0,0,0}, // 'O'
    {0,0,124,102,102,124,96,96,96,0,0,0,0,0,0,0},  // 'P'
    {0,0,60,102,102,102,102,106,60,14,0,0,0,0,0,0},// 'Q'
    {0,0,124,102,102,124,120,108,102,0,0,0,0,0,0,0},// 'R'
    {0,0,60,102,96,60,6,102,60,0,0,0,0,0,0,0},     // 'S'
    {0,0,126,24,24,24,24,24,24,0,0,0,0,0,0,0},     // 'T'
    {0,0,102,102,102,102,102,102,60,0,0,0,0,0,0,0},// 'U'
    {0,0,102,102,102,102,102,60,24,0,0,0,0,0,0,0}, // 'V'
    {0,0,102,102,102,107,127,119,102,0,0,0,0,0,0,0},// 'W'
    {0,0,102,102,60,24,60,102,102,0,0,0,0,0,0,0},  // 'X'
    {0,0,102,102,102,60,24,24,24,0,0,0,0,0,0,0},   // 'Y'
    {0,0,126,6,12,24,48,96,126,0,0,0,0,0,0,0},     // 'Z'
    {0,0,60,48,48,48,48,48,60,0,0,0,0,0,0,0},      // '['
    {0,0,192,96,48,24,12,6,3,0,0,0,0,0,0,0},       // '\'
    {0,0,60,12,12,12,12,12,60,0,0,0,0,0,0,0},      // ']'
    {0,0,24,60,102,0,0,0,0,0,0,0,0,0,0,0},         // '^'
    {0,0,0,0,0,0,0,0,0,255,0,0,0,0,0,0},           // '_'
    {0,0,48,24,12,0,0,0,0,0,0,0,0,0,0,0},          // '`'
    {0,0,0,0,60,6,62,102,62,0,0,0,0,0,0,0},        // 'a'
    {0,0,96,96,124,102,102,102,124,0,0,0,0,0,0,0}, // 'b'
    {0,0,0,0,60,102,96,102,60,0,0,0,0,0,0,0},      // 'c'
    {0,0,6,6,62,102,102,102,62,0,0,0,0,0,0,0},     // 'd'
    {0,0,0,0,60,102,126,96,60,0,0,0,0,0,0,0},      // 'e'
    {0,0,28,56,48,120,48,48,48,0,0,0,0,0,0,0},     // 'f'
    {0,0,0,0,62,102,102,62,6,60,0,0,0,0,0,0},      // 'g'
    {0,0,96,96,124,102,102,102,102,0,0,0,0,0,0,0}, // 'h'
    {0,0,24,0,56,24,24,24,60,0,0,0,0,0,0,0},       // 'i'
    {0,0,12,0,28,12,12,12,12,108,56,0,0,0,0,0,0},  // 'j'
    {0,0,96,96,102,108,120,108,102,0,0,0,0,0,0,0}, // 'k'
    {0,0,56,24,24,24,24,24,60,0,0,0,0,0,0,0},      // 'l'
    {0,0,0,0,108,127,127,107,102,0,0,0,0,0,0,0},   // 'm'
    {0,0,0,0,124,102,102,102,102,0,0,0,0,0,0,0},   // 'n'
    {0,0,0,0,60,102,102,102,60,0,0,0,0,0,0,0},     // 'o'
    {0,0,0,0,124,102,102,124,96,96,0,0,0,0,0,0},   // 'p'
    {0,0,0,0,62,102,102,62,6,6,0,0,0,0,0,0},       // 'q'
    {0,0,0,0,124,102,96,96,96,0,0,0,0,0,0,0},      // 'r'
    {0,0,0,0,62,96,60,6,124,0,0,0,0,0,0,0},        // 's'
    {0,0,48,48,120,48,48,52,24,0,0,0,0,0,0,0},     // 't'
    {0,0,0,0,102,102,102,102,62,0,0,0,0,0,0,0},    // 'u'
    {0,0,0,0,102,102,102,60,24,0,0,0,0,0,0,0},     // 'v'
    {0,0,0,0,102,102,107,127,119,0,0,0,0,0,0,0},   // 'w'
    {0,0,0,0,102,60,24,60,102,0,0,0,0,0,0,0},      // 'x'
    {0,0,0,0,102,102,102,62,6,60,0,0,0,0,0,0},     // 'y'
    {0,0,0,0,126,12,24,48,126,0,0,0,0,0,0,0},      // 'z'
    {0,0,14,24,24,112,24,24,14,0,0,0,0,0,0,0},     // '{'
    {0,0,24,24,24,0,24,24,24,0,0,0,0,0,0,0},       // '|'
    {0,0,112,24,24,14,24,24,112,0,0,0,0,0,0,0},    // '}'
    {0,0,110,155,0,0,0,0,0,0,0,0,0,0,0,0}          // '~'
};

// Function to draw a scaled character at (x, y)
void lcd_draw_char_scaled(esp_lcd_panel_handle_t panel_handle, uint16_t x, uint16_t y, char c, uint16_t color, uint16_t bg_color, uint8_t scale) {
    if (scale < 1) scale = 1;
    if (c < 32 || c > 127) c = '?';
    uint8_t c_idx = c - 32;

    uint16_t char_w = 8 * scale;
    uint16_t char_h = 16 * scale;

    // Allocate buffer dynamically for scaled character size
    uint16_t *char_buf = malloc(char_w * char_h * sizeof(uint16_t));
    if (!char_buf) return;

    for (int row = 0; row < 16; row++) {
        uint8_t bitmask = font8x16[c_idx][row];
        for (int col = 0; col < 8; col++) {
            uint16_t px_color = (bitmask & (1 << (7 - col))) ? color : bg_color;

            // Duplicate pixel blocks based on scale multiplier
            for (int sy = 0; sy < scale; sy++) {
                for (int sx = 0; sx < scale; sx++) {
                    int buf_x = col * scale + sx;
                    int buf_y = row * scale + sy;
                    char_buf[buf_y * char_w + buf_x] = px_color;
                }
            }
        }
    }

    esp_lcd_panel_draw_bitmap(panel_handle, x, y, x + char_w, y + char_h, char_buf);
    free(char_buf);
}

// Function to draw a scaled string at (x, y)
void lcd_draw_string_scaled(esp_lcd_panel_handle_t panel_handle, uint16_t x, uint16_t y, const char *str, uint16_t color, uint16_t bg_color, uint8_t scale) {
    uint16_t cur_x = x;
    uint16_t cur_y = y;

    while (*str) {
        if (*str == '\n') {
            cur_x = x;
            cur_y += (16 * scale);
        } else {
            lcd_draw_char_scaled(panel_handle, cur_x, cur_y, *str, color, bg_color, scale);
            cur_x += (8 * scale);
        }
        str++;
    }
}

// Function to clear the whole screen to a solid background color
void lcd_clear_screen(esp_lcd_panel_handle_t panel_handle, uint16_t color) {
    uint16_t *buffer = heap_caps_malloc(320 * 20 * sizeof(uint16_t), MALLOC_CAP_DMA);
    if (!buffer) return;

    for (int i = 0; i < 320 * 20; i++) {
        buffer[i] = color;
    }

    for (int y = 0; y < 240; y += 20) {
        esp_lcd_panel_draw_bitmap(panel_handle, 0, y, 320, y + 20, buffer);
    }

    free(buffer);
}

void app_main(void)
{
    // Hardware Reset Pulse
    gpio_config_t rst_gpio_config = {
        .mode = GPIO_MODE_OUTPUT,
        .pin_bit_mask = (1ULL << PIN_NUM_RST) | (1ULL << PIN_NUM_RD)
    };
    gpio_config(&rst_gpio_config);
    gpio_set_level(PIN_NUM_RD, 1);
    
    gpio_set_level(PIN_NUM_RST, 0);
    vTaskDelay(pdMS_TO_TICKS(100));
    gpio_set_level(PIN_NUM_RST, 1);
    vTaskDelay(pdMS_TO_TICKS(100));

    // Bus configuration
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

    // Panel IO configuration
    esp_lcd_panel_io_handle_t io_handle = NULL;
    esp_lcd_panel_io_i80_config_t io_config = {
        .cs_gpio_num = PIN_NUM_CS,
        .pclk_hz = 2 * 1000 * 1000,
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

    // Driver initialization
    esp_lcd_panel_handle_t panel_handle = NULL;
    esp_lcd_panel_dev_config_t panel_config = {
        .reset_gpio_num = PIN_NUM_RST,
        .rgb_endian = LCD_RGB_ENDIAN_BGR,
        .bits_per_pixel = 16,
    };

    ESP_ERROR_CHECK(esp_lcd_new_panel_st7789(io_handle, &panel_config, &panel_handle));
    ESP_ERROR_CHECK(esp_lcd_panel_reset(panel_handle));
    ESP_ERROR_CHECK(esp_lcd_panel_init(panel_handle));
    ESP_ERROR_CHECK(esp_lcd_panel_swap_xy(panel_handle, true));
    ESP_ERROR_CHECK(esp_lcd_panel_mirror(panel_handle, true, true));
    ESP_ERROR_CHECK(esp_lcd_panel_invert_color(panel_handle, true));
    ESP_ERROR_CHECK(esp_lcd_panel_disp_on_off(panel_handle, true));

    // Clear Screen to Black
    lcd_clear_screen(panel_handle, COLOR_BLACK);

    // Print static headers
    lcd_draw_string_scaled(panel_handle, 40, 20, "ESP32 DISPLAY TEST", COLOR_YELLOW, COLOR_BLACK, 1);
    lcd_draw_string_scaled(panel_handle, 40, 40, "--------------------", COLOR_WHITE, COLOR_BLACK, 1);

    int count = 0;
    char text_buf[32];

    while (1) {
        // Render dynamic text updates
        snprintf(text_buf, sizeof(text_buf), "Counter: %d  ", count);
        lcd_draw_string_scaled(panel_handle, 40, 80, text_buf, COLOR_GREEN, COLOR_BLACK, 1);

        snprintf(text_buf, sizeof(text_buf), "Uptime: %d sec  ", count * 2);
        lcd_draw_string_scaled(panel_handle, 40, 110, text_buf, COLOR_CYAN, COLOR_BLACK, 1);

        lcd_draw_string_scaled(panel_handle, 40, 150, "Status: SYSTEM OK", COLOR_WHITE, COLOR_RED, 1);

        count++;
        vTaskDelay(pdMS_TO_TICKS(2000)); // Update every 2 seconds
    }
}