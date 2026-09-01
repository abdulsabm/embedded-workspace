#include "reg51.h"
#include "include.h"

#define LED P1 // change the port to which the LED is connected

void led_on_off(){
    LED = 0xFF; // Turn on all LEDs
    delay(500);
    LED = 0x00; // Turn off all LEDs
    delay(500);
}

void main(){
    unsigned int i;
    while(1){
        led_on_off();

        for(i = 0; i < 8; i++){
            LED = (0x1 << i); // Turn on one LED at a time
            delay(500);
        }

        led_on_off();

        for(i = 0; i < 8; i++){
            LED = (0x80 >> i); // Turn on one LED at a time
            delay(500);
        }
    }
}