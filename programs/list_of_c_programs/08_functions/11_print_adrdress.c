#include <stdio.h>

// Function that accepts a pointer to an integer (Call by Reference)
// 'ptr' stores the memory address of the variable passed to it.
void printValueAndAddress(int *ptr) {
    printf("\n--- Inside the Function (Call by Reference) ---\n");
    // *ptr (dereferencing) accesses the value stored at that memory address
    printf("Value at address: %d\n", *ptr);
    
    // ptr prints the memory address itself
    // (void *) is used for type casting to safely print addresses using %p
    printf("Memory address received: %p\n", (void *)ptr);
}

int main() {
    int num;

    // Prompt user for input
    printf("Enter an integer: ");
    if (scanf("%d", &num) != 1) {
        printf("Invalid input!\n");
        return 1;
    }

    printf("\n--- Inside main() before function call ---\n");
    printf("Value of num: %d\n", num);
    printf("Address of num (&num): %p\n", (void *)&num);

    // Call the function by passing the ADDRESS of 'num' using the '&' (address-of) operator
    printValueAndAddress(&num);

    return 0;
}