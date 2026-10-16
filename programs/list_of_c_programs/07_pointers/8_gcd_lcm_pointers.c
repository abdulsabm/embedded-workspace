#include <stdio.h>

int main() {
    int num1, num2, a, b, temp;
    int gcd, lcm;

    int *p1 = &num1, *p2 = &num2;
    int *p_gcd = &gcd, *p_lcm = &lcm;

    printf("Enter two positive integers: ");
    scanf("%d %d", p1, p2);

    // Save initial values to temporary variables for LCM calculation
    a = *p1;
    b = *p2;

    // Euclidean Algorithm for GCD using pointers
    while (b != 0) {
        temp = b;
        b = a % b;
        a = temp;
    }
    *p_gcd = a;

    // LCM formula: (num1 * num2) / GCD
    if (*p_gcd != 0) {
        *p_lcm = (*p1 * *p2) / *p_gcd;
        
        printf("\n--- Results ---\n");
        printf("GCD of %d and %d = %d\n", *p1, *p2, *p_gcd);
        printf("LCM of %d and %d = %d\n", *p1, *p2, *p_lcm);
    } else {
        printf("Invalid input.\n");
    }

    return 0;
}