#include "lcd.h"
#include "../include.h"

void main(){
    const signed char ch = 'H';
    unsigned int count = 0;

    set_lcd_command(FUNCTION_SET_2_LINE_5X7);
    clear_display();
    set_lcd_cursor(1,2); // Move cursor to line 1, position 7
    send_character_to_lcd(ch);
    set_lcd_cursor(2,3); // Move cursor to line 2, position 3
    send_string_to_lcd("Hello, World!");
    set_lcd_cursor(1,10); // Move cursor to line 1, position 2
    send_number_to_lcd(8765);

    while(1){
        delay(25);
        set_lcd_cursor(1,10); // Move cursor to line 1, position 2
        send_number_to_lcd(count++);
    }
}