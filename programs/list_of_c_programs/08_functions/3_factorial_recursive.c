#include <stdio.h>

// Recursive function to calculate factorial
long long findFactorialRecursive(int n) {
    // Base case: 0! is 1 and 1! is 1
    if (n == 0 || n == 1) {
        return 1;
    }
    
    // Recursive step: n! = n * (n - 1)!
    return n * findFactorialRecursive(n - 1);
}

int main() {
    int n;

    // Prompt user for input
    printf("Enter a non-negative integer (N): ");
    if (scanf("%d", &n) != 1 || n < 0) {
        printf("Invalid input! Please enter a non-negative integer.\n");
        return 1;
    }

    // Guard against integer overflow
    if (n > 20) {
        printf("Warning: N is too large. Factorials above 20 will exceed standard numeric limits.\n");
        return 1;
    }

    // Call the recursive function
    long long result = findFactorialRecursive(n);

    // Print the result
    printf("The factorial of %d is: %lld\n", n, result);

    return 0;
}