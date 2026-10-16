#include <stdio.h>

// Function with a 'void' return type (returns nothing)
// It takes pointers to the input numbers and pointers to store the results.
void calculateSumAndDifference(int *a, int *b, int *sum, int *diff) {
    // Dereference input pointers to perform arithmetic, 
    // and dereference output pointers to store the results directly into main's variables.
    *sum = *a + *b;
    *diff = *a - *b;
}

int main() {
    int num1, num2, sum, diff;

    // Prompt user for input
    printf("Enter two integers separated by a space: ");
    if (scanf("%d %d", &num1, &num2) != 2) {
        printf("Invalid input! Please enter two integers.\n");
        return 1;
    }

    // Call the function by passing the addresses of all required variables (Call by Reference)
    calculateSumAndDifference(&num1, &num2, &sum, &diff);

    // Display the computed results in main()
    printf("\n--- Results Displayed in main() ---\n");
    printf("First Number: %d\n", num1);
    printf("Second Number: %d\n", num2);
    printf("Sum: %d\n", sum);
    printf("Difference: %d\n", diff);

    return 0;
}