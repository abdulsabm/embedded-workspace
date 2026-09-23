#include "reg51.h"
#include "../include.h"
#include "lcd.h"

#define LCD_DATA_16x2 P1  // Data port for the LCD

sbit LCD_RS_16x2 = P0^0;  // Register select pin
sbit LCD_RW_16x2 = P0^1;  // Read/Write pin
sbit LCD_EN_16x2 = P0^2;  // Enable pin

void lcd_cmd(unsigned char cmd) {
    LCD_RS_16x2 = 0;  // Select command register
    LCD_RW_16x2 = 0;  // Set to write mode
    LCD_DATA_16x2 = cmd;  // Send command byte
    
    // Enable Pulse (Falling Edge Latches Data)
    LCD_EN_16x2 = 1;
    delay(5);
    LCD_EN_16x2 = 0;
    delay(5);
}

void display_value(unsigned char value) {
    LCD_RS_16x2 = 1;  // Select data register
    LCD_RW_16x2 = 0;  // Set to write mode
    LCD_DATA_16x2 = value;  // Send character byte
    
    // Enable Pulse (Falling Edge Latches Data)
    LCD_EN_16x2 = 1;
    delay(5);
    LCD_EN_16x2 = 0;
    delay(5);
}

void main() {
    delay(5);  // Power-on delay (Wait for LCD internal controller to boot)

    // 1. Mandatory 8-bit, 2-line initialization
    lcd_cmd(FUNCTION_SET_2_LINE_5X7);  
    
    // 2. Turn on Display
    lcd_cmd(DISPLAY_ON_CURSOR_ON_BLINK_OFF);
    
    // 3. Clear Screen
    lcd_cmd(CLEAR_DISPLAY);
    
    // 4. Send Character
    display_value('h');
		delay(500);
		lcd_cmd(CLEAR_DISPLAY);
		lcd_cmd(DISPLAY_ON_CURSOR_ON_BLINK_ON);
		display_value('z');
		delay(500);

    while(1) {
        // Keep MCU alive without constantly resetting the LCD
    }
}