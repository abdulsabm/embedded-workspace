#include "lcd.h"
#include "../include.h"

void set_lcd_command(unsigned char command){
    RS = ENABLE; // Set RS to 0 for command mode enable
    RW = ENABLE; // Set RW to 0 for write mode enable
    LCD_PORT = command; // Set the command pins to the specified command
    delay(1);
    EN = ENABLE;
    delay(1);
    EN = DISABLE;
}

void send_character_to_lcd(const signed char dat){
    RS = DISABLE; // Set RS to 1 for command mode disable
    RW = ENABLE; // Set RW to 1 for write mode disable
    LCD_PORT = dat; // Set the data pins to the specified data
    delay(1);
    EN = ENABLE;
    delay(1);
    EN = DISABLE;
}

void send_string_to_lcd(const char* str){
    while(*str){
        send_character_to_lcd(*str); // Send each character in the string to the LCD
        str++; // Move to the next character in the string
    }
}

void set_lcd_cursor(unsigned char line, unsigned char position){
    unsigned char command = (line == 1)? 0x80:0xC0; // Base command for setting cursor position
    set_lcd_command((command|position)); // Set the cursor position on the LCD
}

void send_number_to_lcd(unsigned int value){
    unsigned int digit = 0, count = 0;
    int arr_cnt = 4;
    unsigned int arr[5] = {0}; // Array to hold the digits of the number
    while(value > 0){
        arr[count] = value % 10; // Get the last digit of the number
        value /= 10; // Remove the last digit from the number
        count++;
    }
    while((arr_cnt>=0)){
        send_character_to_lcd(arr[arr_cnt] + '0'); // Convert digit to character and send to LCD
        arr_cnt--;
    }
}

void clear_display(){
    set_lcd_command(CLEAR_DISPLAY); // Clear the LCD display
} 