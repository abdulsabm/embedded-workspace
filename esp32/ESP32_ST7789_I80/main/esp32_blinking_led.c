#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_heap_caps.h"
#include "driver/gpio.h"
#include "esp_err.h"
#include "esp_log.h"

// Pin Definitions
#define PIN_LED             2   // LCD_RS / DC

void app_main(void)
{
    // Configure GPIO 2 for the built-in LED
    gpio_reset_pin(PIN_LED);
    gpio_set_direction(PIN_LED, GPIO_MODE_OUTPUT);

    while (1) {        
        // Example usage: Turn ON LED (High)
        for (int i = 0; i < 10; i++) {
            gpio_set_level(PIN_LED, 1);
            vTaskDelay(pdMS_TO_TICKS(100));
            gpio_set_level(PIN_LED, 0);
            vTaskDelay(pdMS_TO_TICKS(100));
        }
        for (int i = 0; i < 10; i++) {
            gpio_set_level(PIN_LED, 1);
            vTaskDelay(pdMS_TO_TICKS(200));
            gpio_set_level(PIN_LED, 0);
            vTaskDelay(pdMS_TO_TICKS(200));
        }
        for (int i = 0; i < 10; i++) {
            gpio_set_level(PIN_LED, 1);
            vTaskDelay(pdMS_TO_TICKS(300));
            gpio_set_level(PIN_LED, 0);
            vTaskDelay(pdMS_TO_TICKS(300));
        }
        for (int i = 0; i < 10; i++) {
            gpio_set_level(PIN_LED, 1);
            vTaskDelay(pdMS_TO_TICKS(400));
            gpio_set_level(PIN_LED, 0);
            vTaskDelay(pdMS_TO_TICKS(400));
        }
        for (int i = 0; i < 10; i++) {
            gpio_set_level(PIN_LED, 1);
            vTaskDelay(pdMS_TO_TICKS(500));
            gpio_set_level(PIN_LED, 0);
            vTaskDelay(pdMS_TO_TICKS(500));
        }
    }
}