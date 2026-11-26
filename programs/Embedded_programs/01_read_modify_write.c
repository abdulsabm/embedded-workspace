#include <stdio.h>
#include <stdint.h>

// #define REG (volatile uint32_t *)(0x40001000U)
#define MASK_BITS (0x1FU << 3)

int main() {
    volatile uint32_t *reg;
    volatile uint32_t var = 0x0U;
    volatile uint32_t val = 0x3U;
    reg = &var;
    volatile uint32_t temp = *reg;
    temp &= (~MASK_BITS);
    temp |= ((val & 0x1FU) << 3);
    *reg = temp;
    printf("reg value: 0x%X\n", *reg);
    return 0;
}