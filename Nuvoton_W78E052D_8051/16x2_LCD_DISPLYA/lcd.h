#ifndef _LCD_H_
#define _LCD_H_

#include "reg51.h"
#include "../include.h"

#define LCD_PORT P1  // Data port for the LCD

sbit RS = P0^0;  // Register select pin
sbit RW = P0^1;  // Register select pin
sbit EN = P0^2;  // Enable pin

#define CLEAR_DISPLAY                     0x01
#define RETURN_HOME                       0x02
#define ENTRY_MODE_DEC_CURSOR_LEFT        0x04
#define ENTRY_MODE_INC_CURSOR_RIGHT       0x06
#define ENTRY_MODE_SHIFT_DISPLAY_RIGHT    0x05
#define ENTRY_MODE_SHIFT_DISPLAY_LEFT     0x07

#define DISPLAY_OFF_CURSOR_OFF             0x08
#define DISPLAY_OFF_CURSOR_ON              0x0A
#define DISPLAY_ON_CURSOR_OFF              0x0C
#define DISPLAY_ON_CURSOR_ON_BLINK_OFF     0x0E  // Fixed: Formerly duplicated
#define DISPLAY_ON_CURSOR_ON_BLINK_ON      0x0F  // Fixed: True blink on

#define SHIFT_CURSOR_LEFT                  0x10
#define SHIFT_CURSOR_RIGHT                 0x14
#define SHIFT_DISPLAY_LEFT                 0x18
#define SHIFT_DISPLAY_RIGHT                0x1C

#define FORCE_CURSOR_LINE_1                0x80
#define FORCE_CURSOR_LINE_2                0xC0
#define FUNCTION_SET_2_LINE_5X7            0x38

void set_lcd_command(unsigned char command);
void send_character_to_lcd(const signed char dat);
void send_string_to_lcd(const char* str);
void set_lcd_cursor(unsigned char line, unsigned char position);
void send_number_to_lcd(unsigned int value);
void clear_display();