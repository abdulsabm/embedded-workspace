#include <stdio.h>

void divide_shift_add(unsigned int n1, unsigned int n2, unsigned int *quotient, unsigned int *remainder) {
    *quotient = 0;
    *remainder = 0;

    // Process each bit from Most Significant Bit (MSB) to Least Significant Bit (LSB)
    for (int i = 31; i >= 0; i--) {
        // Shift remainder left by 1 bit and pull down the i-th bit of dividend (n1)
        *remainder = (*remainder << 1) | ((n1 >> i) & 1);

        // If current remainder is greater than or equal to divisor (n2)
        if (*remainder >= n2) {
            *remainder -= n2;         // Subtract divisor
            *quotient |= (1U << i);   // Set the i-th bit of quotient to 1
        }
    }
}

int main() {
    unsigned int n1, n2;
    unsigned int quotient = 0, remainder = 0;

    printf("Enter the first number (n1 - Dividend): ");
    scanf("%u", &n1);
    
    printf("Enter the second number (n2 - Divisor): ");
    scanf("%u", &n2);

    // Division by zero check
    if (n2 == 0) {
        printf("Error: Division by zero is undefined.\n");
        return 1;
    }

    divide_shift_add(n1, n2, &quotient, &remainder);

    printf("\n--- Result ---\n");
    printf("Dividend (n1)  : %u\n", n1);
    printf("Divisor  (n2)  : %u\n", n2);
    printf("Quotient       : %u\n", quotient);
    printf("Remainder      : %u\n", remainder);

    // Verification check
    printf("\nVerification: (%u * %u) + %u = %u\n", n2, quotient, remainder, (n2 * quotient) + remainder);

    return 0;
}