#include <stdio.h>
#include <stdlib.h> // Required for abs()

// Function with a 'void' return type (returns nothing)
// It takes pointers to the two input numbers and pointers to store the GCD and LCM results.
void computeGcdAndLcm(int *n1, int *n2, int *gcd, int *lcm) {
    // Use local copies of absolute values to protect original inputs during Euclidean algorithm
    int a = abs(*n1);
    int b = abs(*n2);
    int original_a = a;
    int original_b = b;

    // Euclidean algorithm to compute GCD
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    *gcd = a; // Store result directly into main's 'gcd' variable via pointer

    // Compute LCM using the formula: LCM(a, b) = (|a * b|) / GCD(a, b)
    if (*gcd == 0) {
        *lcm = 0;
    } else {
        // Use long long for the product to prevent intermediate integer overflow
        long long product = (long long)original_a * original_b;
        *lcm = (int)(product / *gcd); // Store result directly into main's 'lcm' variable via pointer
    }
}

int main() {
    int n1, n2, gcd, lcm;

    // Prompt user for input
    printf("Enter two integers separated by a space: ");
    if (scanf("%d %d", &n1, &n2) != 2) {
        printf("Invalid input! Please enter two integers.\n");
        return 1;
    }

    // Call the function by passing the addresses of all four variables (Call by Reference)
    computeGcdAndLcm(&n1, &n2, &gcd, &lcm);

    // Display the computed results in main()
    printf("\n--- Results Displayed in main() ---\n");
    printf("Number 1 (n1): %d\n", n1);
    printf("Number 2 (n2): %d\n", n2);
    printf("GCD: %d\n", gcd);
    printf("LCM: %d\n", lcm);

    return 0;
}