#include <stdio.h>

// Function to multiply using Shift and Add method
unsigned int multiply_shift_add(unsigned int multiplicand, unsigned int multiplier) {
    unsigned int result = 0;

    // printf("\n--- Step-by-Step Binary Shift & Add ---\n");
    // printf("%-12s | %-12s | %-12s\n", "Multiplicand", "Multiplier", "Accumulator");
    // printf("-----------------------------------------\n");

    while (multiplier > 0) {
        // printf("%-12u | %-12u | %-12u\n", multiplicand, multiplier, result);

        // If the least significant bit (LSB) of multiplier is 1, add multiplicand to result
        if (multiplier & 1) {
            result += multiplicand;
        }

        // Shift multiplicand left by 1 (multiply by 2)
        multiplicand <<= 1;

        // Shift multiplier right by 1 (divide by 2)
        multiplier >>= 1;
    }

    return result;
}

int main() {
    unsigned int num1, num2;

    printf("Enter two 2-digit numbers (10 to 99): ");
    if (scanf("%u %u", &num1, &num2) != 2 || num1 < 10 || num1 > 99 || num2 < 10 || num2 > 99) {
        printf("Error: Please enter valid 2-digit numbers (10-99).\n");
        return 1;
    }

    unsigned int product = multiply_shift_add(num1, num2);

    printf("-----------------------------------------\n");
    printf("Final Product of %u * %u = %u\n", num1, num2, product);

    return 0;
}