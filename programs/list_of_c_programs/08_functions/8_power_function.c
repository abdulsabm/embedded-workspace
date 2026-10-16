#include <stdio.h>

// Function to calculate x^n using Call by Value and Binary Exponentiation
double calculatePower(double base, int exp) {
    double result = 1.0;
    long long n = exp; // Use long long to safely handle negative edge cases (like INT_MIN)

    // Handle negative exponents (e.g., x^(-n) = 1 / (x^n))
    if (n < 0) {
        base = 1.0 / base;
        n = -n;
    }

    // Efficient Exponentiation by Squaring (O(log n) time complexity)
    while (n > 0) {
        if (n % 2 == 1) { // If n is odd, multiply base to result
            result *= base;
        }
        base *= base; // Square the base
        n /= 2;       // Divide exponent by 2
    }

    return result;
}

int main() {
    double base;
    int exp;

    // Prompt user for input
    printf("Enter the base (x): ");
    if (scanf("%lf", &base) != 1) {
        printf("Invalid input for base!\n");
        return 1;
    }

    printf("Enter the integer exponent (n): ");
    if (scanf("%d", &exp) != 1) {
        printf("Invalid input for exponent!\n");
        return 1;
    }

    // Call the function by passing values (Call by Value)
    double result = calculatePower(base, exp);

    // Print the result with formatting
    printf("%.4f raised to the power of %d is: %.6f\n", base, exp, result);

    return 0;
}