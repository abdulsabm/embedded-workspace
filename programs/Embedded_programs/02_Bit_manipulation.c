#include <stdio.h>
#include <stdint.h>
// #define REG ((volatile uint32_t *)(0x40001000U))

#define SET_BIT(REG, BIT) ((REG) |= (1U << (BIT)))
#define CLEAR_BIT(REG, BIT) ((REG) &= ~(1U << (BIT)))
#define TOGGLE_BIT(REG, BIT) ((REG) ^= (1U << (BIT)))
#define CHECK_BIT(REG, BIT) (((REG)>>(BIT)) & 1U)

int main() {
    volatile uint32_t *reg;
    uint32_t var = 0xE;
    uint32_t temp = var;
    reg = &var;
    printf("Set bit: initial bit: 0x%X after set bit: 0x%X \n", temp, SET_BIT(*reg, 0));
    temp = *reg;
    printf("Clear bit: initial bit: 0x%X after clear bit: 0x%X \n", temp, CLEAR_BIT(*reg, 1));
    temp = *reg;
    printf("Toggle bit: initial bit: 0x%X after toggle bit: 0x%X \n", temp, TOGGLE_BIT(*reg, 1));
    temp = *reg;
    printf("Check bit: initial bit: 0x%X after check bit: 0x%X \n", temp, CHECK_BIT(*reg, 1));
    return 0;
}