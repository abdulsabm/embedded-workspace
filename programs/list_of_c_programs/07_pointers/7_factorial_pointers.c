#include <stdio.h>

int main() {
    int n, i;
    unsigned long long fact = 1;

    int *ptr_n = &n;
    unsigned long long *ptr_fact = &fact;

    printf("Enter a positive integer: ");
    scanf("%d", ptr_n);

    if (*ptr_n < 0) {
        printf("Error: Factorial of a negative number does not exist.\n");
    } else {
        for (i = 1; i <= *ptr_n; i++) {
            *ptr_fact *= i; // Equivalent to: *ptr_fact = *ptr_fact * i
        }
        printf("Factorial of %d = %llu\n", *ptr_n, *ptr_fact);
    }

    return 0;
}