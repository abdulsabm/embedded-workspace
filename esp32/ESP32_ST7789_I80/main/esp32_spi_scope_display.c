//  With default esp and dispcly hardware connection.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_heap_caps.h"
#include "esp_lcd_panel_io.h"
#include "esp_lcd_panel_vendor.h"
#include "esp_lcd_panel_ops.h"
#include "driver/gpio.h"
#include "esp_err.h"
#include "esp_log.h"
#include "esp_rom_sys.h"

// Forward declarations
uint8_t bb_spi_transfer_byte(uint8_t data_out);
void bb_spi_transfer_string(const char *str);

// Helper function for single-byte transmission
static inline void bb_spi_send_byte(uint8_t val) {
    bb_spi_transfer_byte(val);
}

// C11 Generic Macro to handle both uint8_t and string types automatically
#define bb_spi_send(X) _Generic((X), \
    char*: bb_spi_transfer_string, \
    const char*: bb_spi_transfer_string, \
    default: bb_spi_send_byte \
)(X)

// Display Pins (8-bit Parallel ST7789)
#define PIN_NUM_DATA0          12
#define PIN_NUM_DATA1          13
#define PIN_NUM_DATA2          26
#define PIN_NUM_DATA3          25
#define PIN_NUM_DATA4          17
#define PIN_NUM_DATA5          16
#define PIN_NUM_DATA6          27
#define PIN_NUM_DATA7          14
#define PIN_NUM_PCLK           4
#define PIN_NUM_CS             15
#define PIN_NUM_DC             2
#define PIN_NUM_RST            33
#define PIN_NUM_RD             32

// Bit-Banging SPI Pins
#define PIN_SPI_SCLK           18
#define PIN_SPI_MOSI           23
#define PIN_SPI_MISO           19
#define PIN_SPI_CS             5

// Color Definitions (Byte-Swapped for LCD)
#define COLOR_BLACK   0x0000
#define COLOR_WHITE   0xFFFF
#define COLOR_RED     0x00F8
#define COLOR_GREEN   0xE007
#define COLOR_BLUE    0x1F00
#define COLOR_YELLOW  0xE0FF
#define COLOR_CYAN    0xFF07

// Fits perfectly inside the 320x240 LCD boundary (320 - 70 offset = 250 pixels maximum display area)
#define MAX_SAMPLES   250

typedef struct {
    uint8_t cs[MAX_SAMPLES];
    uint8_t sclk[MAX_SAMPLES];
    uint8_t mosi[MAX_SAMPLES];
    uint8_t miso[MAX_SAMPLES];
    uint16_t sample_count;
} spi_trace_t;

static spi_trace_t trace;

// Standard 8x16 ASCII Font Array (ASCII 32 to 126)
static const uint8_t font8x16[95][16] = {
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},             // 32 ' '
    {0,0,24,60,60,60,24,24,0,24,24,0,0,0,0,0},     // 33 '!'
    {0,0,102,102,102,0,0,0,0,0,0,0,0,0,0,0},       // 34 '"'
    {0,0,102,102,255,102,102,255,102,102,0,0,0,0}, // 35 '#'
    {0,0,24,60,102,96,60,6,102,60,24,0,0,0,0,0},   // 36 '$'
    {0,0,98,102,12,24,48,96,102,70,0,0,0,0,0,0},   // 37 '%'
    {0,0,60,102,102,60,114,102,102,62,0,0,0,0,0,0},// 38 '&'
    {0,0,24,24,48,0,0,0,0,0,0,0,0,0,0,0},          // 39 '\''
    {0,0,12,24,48,48,48,48,24,12,0,0,0,0,0,0},     // 40 '('
    {0,0,48,24,12,12,12,12,24,48,0,0,0,0,0,0},     // 41 ')'
    {0,0,0,102,60,255,60,102,0,0,0,0,0,0,0,0},     // 42 '*'
    {0,0,0,24,24,126,24,24,0,0,0,0,0,0,0,0},       // 43 '+'
    {0,0,0,0,0,0,0,24,24,48,0,0,0,0,0,0},          // 44 ','
    {0,0,0,0,0,126,0,0,0,0,0,0,0,0,0,0},           // 45 '-'
    {0,0,0,0,0,0,0,24,24,0,0,0,0,0,0,0},           // 46 '.'
    {0,0,6,12,24,48,96,192,0,0,0,0,0,0,0,0},       // 47 '/'
    {0,0,60,102,110,118,118,102,60,0,0,0,0,0,0,0}, // 48 '0'
    {0,0,24,56,24,24,24,24,126,0,0,0,0,0,0,0},     // 49 '1'
    {0,0,60,102,6,12,24,48,126,0,0,0,0,0,0,0},     // 50 '2'
    {0,0,60,102,6,28,6,102,60,0,0,0,0,0,0,0},      // 51 '3'
    {0,0,12,28,60,108,126,12,12,0,0,0,0,0,0,0},    // 52 '4'
    {0,0,126,96,124,6,6,102,60,0,0,0,0,0,0,0},     // 53 '5'
    {0,0,60,96,124,102,102,102,60,0,0,0,0,0,0,0},  // 54 '6'
    {0,0,126,6,12,24,48,48,48,0,0,0,0,0,0,0},      // 55 '7'
    {0,0,60,102,102,60,102,102,60,0,0,0,0,0,0,0},  // 56 '8'
    {0,0,60,102,102,62,6,12,56,0,0,0,0,0,0,0},     // 57 '9'
    {0,0,0,24,24,0,0,24,24,0,0,0,0,0,0,0},         // 58 ':'
    {0,0,0,24,24,0,0,24,24,48,0,0,0,0,0,0},        // 59 ';'
    {0,0,12,24,48,96,48,24,12,0,0,0,0,0,0,0},      // 60 '<'
    {0,0,0,0,126,0,126,0,0,0,0,0,0,0,0,0},         // 61 '='
    {0,0,48,24,12,6,12,24,48,0,0,0,0,0,0,0},       // 62 '>'
    {0,0,60,102,6,12,24,0,24,0,0,0,0,0,0,0},       // 63 '?'
    {0,0,60,102,110,118,110,96,60,0,0,0,0,0,0,0},  // 64 '@'
    {0,0,24,60,102,102,126,102,102,0,0,0,0,0,0,0}, // 65 'A'
    {0,0,124,102,102,124,102,102,124,0,0,0,0,0,0,0},// 66 'B'
    {0,0,60,102,96,96,96,102,60,0,0,0,0,0,0,0},    // 67 'C'
    {0,0,120,108,102,102,102,108,120,0,0,0,0,0,0,0},// 68 'D'
    {0,0,126,96,96,120,96,96,126,0,0,0,0,0,0,0},   // 69 'E'
    {0,0,126,96,96,120,96,96,96,0,0,0,0,0,0,0},    // 70 'F'
    {0,0,60,102,96,110,102,102,62,0,0,0,0,0,0,0},  // 71 'G'
    {0,0,102,102,102,126,102,102,102,0,0,0,0,0,0,0},// 72 'H'
    {0,0,60,24,24,24,24,24,60,0,0,0,0,0,0,0},      // 73 'I'
    {0,0,30,12,12,12,12,102,60,0,0,0,0,0,0,0},     // 74 'J'
    {0,0,102,108,120,112,120,108,102,0,0,0,0,0,0,0},// 75 'K'
    {0,0,96,96,96,96,96,96,126,0,0,0,0,0,0,0},     // 76 'L'
    {0,0,102,119,127,107,102,102,102,0,0,0,0,0,0,0},// 77 'M'
    {0,0,102,118,126,126,110,102,102,0,0,0,0,0,0,0},// 78 'N'
    {0,0,60,102,102,102,102,102,60,0,0,0,0,0,0,0}, // 79 'O'
    {0,0,124,102,102,124,96,96,96,0,0,0,0,0,0,0},  // 80 'P'
    {0,0,60,102,102,102,102,110,60,14,0,0,0,0,0,0},// 81 'Q'
    {0,0,124,102,102,124,120,108,102,0,0,0,0,0,0,0},// 82 'R'
    {0,0,60,102,96,60,6,102,60,0,0,0,0,0,0,0},     // 83 'S'
    {0,0,126,24,24,24,24,24,24,0,0,0,0,0,0,0},     // 84 'T'
    {0,0,102,102,102,102,102,102,60,0,0,0,0,0,0,0},// 85 'U'
    {0,0,102,102,102,102,102,60,24,0,0,0,0,0,0,0}, // 86 'V'
    {0,0,102,102,102,107,127,119,102,0,0,0,0,0,0,0},// 87 'W'
    {0,0,102,102,60,24,60,102,102,0,0,0,0,0,0,0},  // 88 'X'
    {0,0,102,102,102,60,24,24,24,0,0,0,0,0,0,0},   // 89 'Y'
    {0,0,126,6,12,24,48,96,126,0,0,0,0,0,0,0}      // 90 'Z'
};

void lcd_draw_char_scaled(esp_lcd_panel_handle_t panel, uint16_t x, uint16_t y, char c, uint16_t color, uint16_t bg, uint8_t scale) {
    if (scale < 1) scale = 1;
    if (c < 32 || c > 90) c = ' ';
    uint8_t c_idx = c - 32;

    uint16_t char_w = 8 * scale;
    uint16_t char_h = 16 * scale;

    uint16_t *char_buf = malloc(char_w * char_h * sizeof(uint16_t));
    if (!char_buf) return;

    for (int r = 0; r < 16; r++) {
        uint8_t bits = font8x16[c_idx][r];
        for (int col = 0; col < 8; col++) {
            uint16_t px_color = (bits & (1 << (7 - col))) ? color : bg;
            for (int sy = 0; sy < scale; sy++) {
                for (int sx = 0; sx < scale; sx++) {
                    int bx = col * scale + sx;
                    int by = r * scale + sy;
                    char_buf[by * char_w + bx] = px_color;
                }
            }
        }
    }
    esp_lcd_panel_draw_bitmap(panel, x, y, x + char_w, y + char_h, char_buf);
    free(char_buf);
}

void lcd_draw_string_scaled(esp_lcd_panel_handle_t panel, uint16_t x, uint16_t y, const char *str, uint16_t color, uint16_t bg, uint8_t scale) {
    while (*str) {
        lcd_draw_char_scaled(panel, x, y, *str, color, bg, scale);
        x += (8 * scale);
        str++;
    }
}

void lcd_clear_screen(esp_lcd_panel_handle_t panel, uint16_t color) {
    uint16_t *buffer = heap_caps_malloc(320 * 20 * sizeof(uint16_t), MALLOC_CAP_DMA);
    if (!buffer) return;
    for (int i = 0; i < 320 * 20; i++) buffer[i] = color;
    for (int y = 0; y < 240; y += 20) {
        esp_lcd_panel_draw_bitmap(panel, 0, y, 320, y + 20, buffer);
    }
    free(buffer);
}

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
        // Step 1: Drive MOSI pin & record sample
        gpio_set_level(PIN_SPI_MOSI, (data_out >> bit) & 0x01);
        record_sample();
        esp_rom_delay_us(2);

        // Step 2: Drive Clock High & record sample
        gpio_set_level(PIN_SPI_SCLK, 1);
        record_sample();
        esp_rom_delay_us(2);

        // Step 3: Read MISO pin state
        data_in <<= 1;
        if (gpio_get_level(PIN_SPI_MISO)) {
            data_in |= 0x01;
        }

        // Step 4: Drive Clock Low & record sample
        gpio_set_level(PIN_SPI_SCLK, 0);
        record_sample();
        esp_rom_delay_us(2);
    }
    return data_in;
}

// Function to transmit string over SPI bit-banging
void bb_spi_transfer_string(const char *str) {
    while (*str) {
        bb_spi_transfer_byte((uint8_t)(*str));
        str++;
    }
}

// Continuous Waveform Renderer
void render_spi_signals(esp_lcd_panel_handle_t panel) {
    uint16_t *row_buf = heap_caps_malloc(320 * sizeof(uint16_t), MALLOC_CAP_DMA);
    if (!row_buf) return;

    for (int y = 45; y < 235; y++) {
        for (int x = 0; x < 320; x++) row_buf[x] = COLOR_BLACK;

        for (int s = 0; s < trace.sample_count && s < MAX_SAMPLES; s++) {
            int px = s + 70; // Wave starts drawing right after signal labels

            int cs_hi = 55, cs_lo = 70;
            int clk_hi = 100, clk_lo = 115;
            int mosi_hi = 145, mosi_lo = 160;
            int miso_hi = 190, miso_lo = 205;

            // 1. CS Signal Line
            int cur_cs = trace.cs[s] ? cs_hi : cs_lo;
            int prev_cs = (s > 0) ? (trace.cs[s-1] ? cs_hi : cs_lo) : cur_cs;
            int min_cs = cur_cs < prev_cs ? cur_cs : prev_cs;
            int max_cs = cur_cs > prev_cs ? cur_cs : prev_cs;
            if (y >= min_cs && y <= max_cs) row_buf[px] = COLOR_RED;

            // 2. SCLK Signal Line
            int cur_clk = trace.sclk[s] ? clk_hi : clk_lo;
            int prev_clk = (s > 0) ? (trace.sclk[s-1] ? clk_hi : clk_lo) : cur_clk;
            int min_clk = cur_clk < prev_clk ? cur_clk : prev_clk;
            int max_clk = cur_clk > prev_clk ? cur_clk : prev_clk;
            if (y >= min_clk && y <= max_clk) row_buf[px] = COLOR_YELLOW;

            // 3. MOSI Signal Line
            int cur_m = trace.mosi[s] ? mosi_hi : mosi_lo;
            int prev_m = (s > 0) ? (trace.mosi[s-1] ? mosi_hi : mosi_lo) : cur_m;
            int min_m = cur_m < prev_m ? cur_m : prev_m;
            int max_m = cur_m > prev_m ? cur_m : prev_m;
            if (y >= min_m && y <= max_m) row_buf[px] = COLOR_GREEN;

            // 4. MISO Signal Line
            int cur_mi = trace.miso[s] ? miso_hi : miso_lo;
            int prev_mi = (s > 0) ? (trace.miso[s-1] ? miso_hi : miso_lo) : cur_mi;
            int min_mi = cur_mi < prev_mi ? cur_mi : prev_mi;
            int max_mi = cur_mi > prev_mi ? cur_mi : prev_mi;
            if (y >= min_mi && y <= max_mi) row_buf[px] = COLOR_CYAN;
        }

        esp_lcd_panel_draw_bitmap(panel, 0, y, 320, y + 1, row_buf);
    }
    free(row_buf);

    // Render Side Channel Labels
    lcd_draw_string_scaled(panel, 5, 55,  "CS",   COLOR_RED,    COLOR_BLACK, 2);
    lcd_draw_string_scaled(panel, 5, 100, "CLK",  COLOR_YELLOW, COLOR_BLACK, 2);
    lcd_draw_string_scaled(panel, 5, 145, "MOSI", COLOR_GREEN,  COLOR_BLACK, 1);
    lcd_draw_string_scaled(panel, 5, 190, "MISO", COLOR_CYAN,   COLOR_BLACK, 1);
}

void app_main(void) {
    // 1. Reset pins to clear any leftover hardware peripheral assignments
    gpio_reset_pin(PIN_SPI_SCLK);
    gpio_reset_pin(PIN_SPI_MOSI);
    gpio_reset_pin(PIN_SPI_CS);
    gpio_reset_pin(PIN_SPI_MISO);

    // 2. Set outputs to INPUT_OUTPUT mode so gpio_get_level() can read output states
    gpio_config_t out_conf = {
        .pin_bit_mask = (1ULL << PIN_SPI_SCLK) | (1ULL << PIN_SPI_MOSI) | (1ULL << PIN_SPI_CS),
        .mode = GPIO_MODE_INPUT_OUTPUT,  // Changed from GPIO_MODE_OUTPUT
        .pull_down_en = GPIO_PULLDOWN_DISABLE,
        .pull_up_en = GPIO_PULLUP_DISABLE,
        .intr_type = GPIO_INTR_DISABLE,
    };
    gpio_config(&out_conf);

    // 3. Configure MISO Input
    gpio_config_t in_conf = {
        .pin_bit_mask = (1ULL << PIN_SPI_MISO),
        .mode = GPIO_MODE_INPUT,
        .pull_up_en = GPIO_PULLUP_ENABLE,
        .pull_down_en = GPIO_PULLDOWN_DISABLE,
        .intr_type = GPIO_INTR_DISABLE,
    };
    gpio_config(&in_conf);

    // Default Idle States
    gpio_set_level(PIN_SPI_CS, 1);
    gpio_set_level(PIN_SPI_SCLK, 0);

    // Hardware Reset Display
    gpio_config_t rst_conf = { .mode = GPIO_MODE_OUTPUT, .pin_bit_mask = (1ULL << PIN_NUM_RST) | (1ULL << PIN_NUM_RD) };
    gpio_config(&rst_conf);
    gpio_set_level(PIN_NUM_RD, 1);
    gpio_set_level(PIN_NUM_RST, 0);
    vTaskDelay(pdMS_TO_TICKS(50));
    gpio_set_level(PIN_NUM_RST, 1);
    vTaskDelay(pdMS_TO_TICKS(50));

    esp_lcd_i80_bus_handle_t i80_bus = NULL;
    esp_lcd_i80_bus_config_t bus_config = {
        .clk_src = LCD_CLK_SRC_DEFAULT,
        .dc_gpio_num = PIN_NUM_DC,
        .wr_gpio_num = PIN_NUM_PCLK,
        .data_gpio_nums = { PIN_NUM_DATA0, PIN_NUM_DATA1, PIN_NUM_DATA2, PIN_NUM_DATA3,
                            PIN_NUM_DATA4, PIN_NUM_DATA5, PIN_NUM_DATA6, PIN_NUM_DATA7 },
        .bus_width = 8,
        .max_transfer_bytes = 320 * 20 * sizeof(uint16_t),
    };
    esp_lcd_new_i80_bus(&bus_config, &i80_bus);

    esp_lcd_panel_io_handle_t io_handle = NULL;
    esp_lcd_panel_io_i80_config_t io_config = {
        .cs_gpio_num = PIN_NUM_CS,
        .pclk_hz = 2 * 1000 * 1000,
        .trans_queue_depth = 10,
        .dc_levels = { .dc_idle_level = 0, .dc_cmd_level = 0, .dc_dummy_level = 0, .dc_data_level = 1 },
        .lcd_cmd_bits = 8, .lcd_param_bits = 8,
    };
    esp_lcd_new_panel_io_i80(i80_bus, &io_config, &io_handle);

    esp_lcd_panel_handle_t panel_handle = NULL;
    esp_lcd_panel_dev_config_t panel_config = { .reset_gpio_num = PIN_NUM_RST, .rgb_endian = LCD_RGB_ENDIAN_BGR, .bits_per_pixel = 16 };
    esp_lcd_new_panel_st7789(io_handle, &panel_config, &panel_handle);
    esp_lcd_panel_reset(panel_handle);
    esp_lcd_panel_init(panel_handle);
    esp_lcd_panel_swap_xy(panel_handle, true);
    esp_lcd_panel_mirror(panel_handle, true, true);
    esp_lcd_panel_invert_color(panel_handle, true);
    esp_lcd_panel_disp_on_off(panel_handle, true);

    lcd_clear_screen(panel_handle, COLOR_BLACK);
    lcd_draw_string_scaled(panel_handle, 10, 10, "SPI LOGIC ANALYZER", COLOR_WHITE, COLOR_BLACK, 1);

    const char *test_variable = "ABDUL";

    while (1) {
        trace.sample_count = 0;

        // Drive CS low and sample initial CS state
        gpio_set_level(PIN_SPI_CS, 0);
        record_sample();

        // Send character array or integer using macro
        bb_spi_send(test_variable); 

        // Drive CS high and sample final CS state
        gpio_set_level(PIN_SPI_CS, 1);
        record_sample();

        render_spi_signals(panel_handle);
        vTaskDelay(pdMS_TO_TICKS(1500));
    }
}