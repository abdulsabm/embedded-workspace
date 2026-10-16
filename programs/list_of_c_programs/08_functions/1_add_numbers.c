#include <stdio.h>

// Function declaration (Call by Value)
// It accepts two integer copies and returns their sum
int addNumbers(int a, int b) {
    return a + b;
}

int main() {
    int num1, num2, sum;

    // Prompt user for input
    printf("Enter the first number: ");
    if (scanf("%d", &num1) != 1) {
        printf("Invalid input!\n");
        return 1;
    }

    printf("Enter the second number: ");
    if (scanf("%d", &num2) != 1) {
        printf("Invalid input!\n");
        return 1;
    }

    // Call the function by passing the values
    sum = addNumbers(num1, num2);

    // Print the result
    printf("The sum of %d and %d is: %d\n", num1, num2, sum);

    return 0;
}