#include <stdio.h>
#include <stdlib.h> // Required for abs() to handle negative numbers safely

// Recursive function to calculate the GCD of two numbers using the Euclidean algorithm
int findGCD(int a, int b) {
    // Base case: if b is 0, GCD is a
    if (b == 0) {
        return a;
    }
    // Recursive step: GCD(a, b) = GCD(b, a % b)
    return findGCD(b, a % b);
}

/*
    while(b != 0){
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
*/

int main() {
    int num1, num2, gcd;

    // Prompt user for input
    printf("Enter two integers separated by a space: ");
    if (scanf("%d %d", &num1, &num2) != 2) {
        printf("Invalid input! Please enter two integers.\n");
        return 1;
    }

    // Call the function by passing the values (Call by Value)
    // Using abs() ensures the GCD is positive even if negative numbers are entered
    gcd = findGCD(abs(num1), abs(num2));

    // Print the result
    printf("The GCD of %d and %d is: %d\n", num1, num2, gcd);

    return 0;
}