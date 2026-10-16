#include <stdio.h>

// Function to count the number of binary ones (set bits) using Brian Kernighan's Algorithm
int countBinaryOnes(unsigned int n) {
    int count = 0;
    
    // Loop runs until all bits are 0
    while (n > 0) {
        // n & (n - 1) clears the least significant bit set to 1
        n = n & (n - 1);
        count++;
    }
    
    return count;
}

int main() {
    int original;
    
    // Prompt user for input
    printf("Enter a non-negative integer: ");
    if (scanf("%d", &original) != 1 || original < 0) {
        printf("Invalid input! Please enter a non-negative integer.\n");
        return 1;
    }

    // Call the function by passing the value (Call by Value)
    int onesCount = countBinaryOnes(original);

    // Print the result
    printf("The number of binary ones in %d is: %d\n", original, onesCount);

    return 0;
}