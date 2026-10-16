#include <stdio.h>

// Function to find the greatest of three numbers using Call by Value
int findGreatest(int a, int b, int c) {
    if (a >= b && a >= c) {
        return a;
    } else if (b >= a && b >= c) {
        return b;
    } else {
        return c;
    }
}

int main() {
    int num1, num2, num3, greatest;

    // Prompt user for three numbers
    printf("Enter three integers separated by spaces: ");
    if (scanf("%d %d %d", &num1, &num2, &num3) != 3) {
        printf("Invalid input! Please enter three numbers.\n");
        return 1;
    }

    // Call the function by passing the values (Call by Value)
    greatest = findGreatest(num1, num2, num3);

    // Print the result
    printf("The greatest among %d, %d, and %d is: %d\n", num1, num2, num3, greatest);

    return 0;
}