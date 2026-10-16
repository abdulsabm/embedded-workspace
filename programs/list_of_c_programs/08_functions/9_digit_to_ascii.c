#include <stdio.h>

// Function to extract each digit of a 4-digit number from left to right 
// and print its ASCII value
void printDigitAscii(int n) {
    // Extract digits from left to right using division and modulo
    int thousands = (n / 1000) % 10;
    int hundreds  = (n / 100) % 10;
    int tens      = (n / 10) % 10;
    int units     = n % 10;

    // In C, adding '0' (ASCII 48) to an integer digit yields its character ASCII value.
    // For example: 1 + 48 = 49 (ASCII value for character '1').
    printf("%d %d %d %d\n", 
           thousands + '0', 
           hundreds + '0', 
           tens + '0', 
           units + '0');
}

int main() {
    int num;

    // Prompt user for a 4-digit number
    printf("Enter a 4-digit integer: ");
    if (scanf("%d", &num) != 1 || num < 1000 || num > 9999) {
        printf("Invalid input! Please enter a valid 4-digit number (1000 to 9999).\n");
        return 1;
    }

    // Call the function by passing the value (Call by Value)
    printDigitAscii(num);

    return 0;
}