#include <stdio.h>
#include <stdint.h>
// #define ADDR ((volatile uint32_t *)0x40001000)

int main() {
    volatile uint32_t *reg = NULL;
    volatile uint32_t ADDR = 0xFFFFFU;
    reg = &ADDR;
    int zero_count = 0;
    int one_count = 0;
    
    uint32_t val = *reg;
    while(val > 0){
        (val & 1U)? (++one_count):(++zero_count);
        val &= (val-1);
    }
    printf("0: %d\n1: %d", zero_count, one_count);
    return 0;
}