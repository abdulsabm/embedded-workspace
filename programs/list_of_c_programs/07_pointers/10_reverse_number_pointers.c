#include <stdio.h>

int main() {
    int num, original, rev = 0, rem;

    int *p_num = &num;
    int *p_orig = &original;
    int *p_rev = &rev;

    printf("Enter a number: ");
    scanf("%d", p_num);

    // Store original number before modifying num
    *p_orig = *p_num;

    // Logic to reverse the number using pointers
    while (*p_num != 0) {
        rem = *p_num % 10;          // Extract the last digit
        *p_rev = (*p_rev * 10) + rem; // Build the reversed number
        *p_num /= 10;               // Remove the last digit
    }

    printf("\n--- Results ---\n");
    printf("Original Number : %d\n", *p_orig);
    printf("Reversed Number : %d\n", *p_rev);

    return 0;
}