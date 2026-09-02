#include "reg51.h"
#include "../include.h"
#include "01_4_digit_led_counter.h"

#define LED_P1 P1 // 7th(Port* of 7) bit should be zero if decimal point is required.
#define LED_P0 P0 

void main(){
    LED_P0 = (LED_4|LED_3|LED_2|LED_1); // Enable all 4 digits of 7 segment led display.
    while(1){
        int i;
        for(i = 0;i <10;i++){
            LED_P1 = (DIGIT_MAP[i] | (~Decimal_Point)); //if we want decimal point the remove ~ and replcae | with &.
            delay(500);
        }
    }
}