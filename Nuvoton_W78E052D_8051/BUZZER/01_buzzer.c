#include "reg51.h"
#include "../include.h"

sbit PORT_P00 = P0^0;

void buzzer_toggle(int buzzer_delay){
    PORT_P00 = 0x0;
    delay(buzzer_delay);
    PORT_P00 = 0x1;
    delay(buzzer_delay);
}

void main(){
    int i = 50;
    while(1){
        buzzer_toggle(i);
        i += 50;
    }
}
