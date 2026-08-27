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
    bool led_state = 0; // Initialize the LED state to OFF
    while (1) {        
        // Example usage: Turn ON LED (High)
        led_state ^= 1; // Toggle the LED state using XOR
        gpio_set_level(PIN_LED, led_state);
        vTaskDelay(pdMS_TO_TICKS(100));
    }
}