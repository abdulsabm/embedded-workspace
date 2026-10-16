#include <stdio.h>

// Function to reverse the digits of a given number using Call by Value
long long reverseNumber(long long n) {
    long long reversed = 0;
    int isNegative = 0;

    // Handle negative numbers gracefully
    if (n < 0) {
        isNegative = 1;
        n = -n;
    }

    // Extract digits and build the reversed number
    while (n > 0) {
        long long digit = n % 10;
        reversed = reversed * 10 + digit;
        n /= 10;
    }

    return isNegative ? -reversed : reversed;
}

int main() {
    long long original, reversed;

    // Prompt user for input
    printf("Enter an integer: ");
    if (scanf("%lld", &original) != 1) {
        printf("Invalid input!\n");
        return 1;
    }

    // Call the function by passing the value (Call by Value)
    reversed = reverseNumber(original);

    // Print both numbers
    printf("\nOriginal Number: %lld\n", original);
    printf("Reversed Number: %lld\n", reversed);

    return 0;
}