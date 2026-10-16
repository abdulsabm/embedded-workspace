#include <stdio.h>

// Function with a 'void' return type (returns nothing)
// It accepts pointers to the three input numbers and a pointer to store the greatest result.
void findGreatest(int *a, int *b, int *c, int *greatest) {
    // Dereference input pointers to compare their values,
    // and dereference the 'greatest' pointer to update its value directly in main().
    if (*a >= *b && *a >= *c) {
        *greatest = *a;
    } else if (*b >= *a && *b >= *c) {
        *greatest = *b;
    } else {
        *greatest = *c;
    }
}

int main() {
    int num1, num2, num3, greatest;

    // Prompt user for input
    printf("Enter three integers separated by spaces: ");
    if (scanf("%d %d %d", &num1, &num2, &num3) != 3) {
        printf("Invalid input! Please enter three integers.\n");
        return 1;
    }

    // Call the function by passing the addresses of all four variables (Call by Reference)
    findGreatest(&num1, &num2, &num3, &greatest);

    // Display the result in main()
    printf("\n--- Results Displayed in main() ---\n");
    printf("The numbers entered are: %d, %d, and %d\n", num1, num2, num3);
    printf("The greatest number is: %d\n", greatest);

    return 0;
}