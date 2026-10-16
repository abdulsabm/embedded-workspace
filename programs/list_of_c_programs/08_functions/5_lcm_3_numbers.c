#include <stdio.h>
#include <stdlib.h> // Required for abs()

// Function to find the GCD of two numbers using the Euclidean algorithm
long long findGCD(long long a, long long b) {
    if (b == 0) {
        return a;
    }
    return findGCD(b, a % b);
}

// Function to find the LCM of two numbers
// Formula: LCM(a, b) = (a * b) / GCD(a, b)
long long findLCM(long long a, long long b) {
    if (a == 0 || b == 0) {
        return 0; // LCM with zero is conventionally 0
    }
    // Multiply first, then divide by GCD to prevent intermediate integer overflow where possible
    return (abs(a * b)) / findGCD(a, b);
}

// Function to find the LCM of three numbers
long long findLCMOfThree(long long a, long long b, long long c) {
    long long lcm_ab = findLCM(a, b);
    return findLCM(lcm_ab, c); // LCM(A, B, C) = LCM(LCM(A, B), C)
}

int main() {
    long long num1, num2, num3;

    // Prompt user for input
    printf("Enter three integers separated by spaces: ");
    if (scanf("%lld %lld %lld", &num1, &num2, &num3) != 3) {
        printf("Invalid input! Please enter three integers.\n");
        return 1;
    }

    // Call the function to find the LCM of the three numbers
    long long result = findLCMOfThree(num1, num2, num3);

    // Print the result
    printf("The LCM of %lld, %lld, and %lld is: %lld\n", num1, num2, num3, result);

    return 0;
}