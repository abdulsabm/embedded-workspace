#include <stdio.h>

// Function that accepts a pointer to 'n' (Call by Reference for input) 
// and returns the calculated factorial as a long long.
long long calculateFactorial(int *n) {
    // Factorial is not defined for negative numbers
    if (*n < 0) {
        printf("Error: Factorial is not defined for negative numbers.\n");
        return -1; // Error indicator
    }

    long long fact = 1; // Use long long to prevent overflow for larger factorials

    // Iterative calculation using the dereferenced value (*n)
    for (int i = 1; i <= *n; i++) {
        fact *= i;
    }

    return fact;
}

int main() {
    int n;

    // Prompt user for input
    printf("Enter a non-negative integer: ");
    if (scanf("%d", &n) != 1) {
        printf("Invalid input!\n");
        return 1;
    }

    // Call the function by passing the ADDRESS of 'n' (&n) using Call by Reference
    long long result = calculateFactorial(&n);

    // Print the result if valid
    if (result != -1) {
        printf("The factorial of %d is: %lld\n", n, result);
    }

    return 0;
}