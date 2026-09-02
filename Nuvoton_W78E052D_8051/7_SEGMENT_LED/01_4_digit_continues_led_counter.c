#include "reg51.h"
#include "../include.h"
#include "01_4_digit_led_counter.h"

#define LED_P1 P1 // 7th(Port* of 7) bit should be zero if decimal point is required.
#define LED_P0 P0

void main(){
    int sg1 = 0, sg2 = 1, sg3 = 1, sg4 = 1;
    while(1){
        LED_P0 = (LED_4); // Enable all 4 digits of 7 segment led display.
        LED_P1 = (DIGIT_MAP[sg1] | (~Decimal_Point)); //if we want decimal point the remove ~ and replcae | with &.
        if(sg1 == 10){
            sg1 = 0;
            LED_P0 = (LED_3); // Enable all 4 digits of 7 segment led display.
            LED_P1 = (DIGIT_MAP[sg2] | (~Decimal_Point)); //if we want decimal point the remove ~ and replcae | with &.
            sg2++;
        }
        sg1++;
        if(sg2 == 11){
            sg2 = 1;
            LED_P0 = (LED_2); // Enable all 4 digits of 7 segment led display.
            LED_P1 = (DIGIT_MAP[sg3] | (~Decimal_Point)); //if we want decimal point the remove ~ and replcae | with &.
            sg3++;
        }
        if(sg3 == 11){
            sg3 = 1;
            LED_P0 = (LED_1); // Enable all 4 digits of 7 segment led display.
            LED_P1 = (DIGIT_MAP[sg4] | (~Decimal_Point)); //if we want decimal point the remove ~ and replcae | with &.
            sg4++;
        }
        delay(100);
    }
}