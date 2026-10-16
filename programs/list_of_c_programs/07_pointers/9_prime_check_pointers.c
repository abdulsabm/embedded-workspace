#include <stdio.h>

int main() {
    int num, i, is_prime = 1;

    int *ptr_num = &num;
    int *ptr_is_prime = &is_prime;

    printf("Enter a positive integer: ");
    scanf("%d", ptr_num);

    // 0 and 1 are not prime numbers
    if (*ptr_num <= 1) {
        *ptr_is_prime = 0;
    } else {
        // Check divisibility from 2 up to num / 2
        for (i = 2; (i*i) <= *ptr_num; i++) {
            if (*ptr_num % i == 0) {
                *ptr_is_prime = 0; // Found a factor, not prime
                break;             // Exit loop early
            }
        }
    }

    if (*ptr_is_prime == 1) {
        printf("\nOutput: %d is a PRIME number.\n", *ptr_num);
    } else {
        printf("\nOutput: %d is NOT a prime number.\n", *ptr_num);
    }

    return 0;
}