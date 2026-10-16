#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    char *ptr;
    int length = 0;

    // Prompt user for a string
    printf("Enter a string: ");
    // fgets is used safely to read a line of text including spaces
    fgets(str, sizeof(str), stdin);

    // Initialize pointer to the base address of the string
    ptr = str;

    // Traverse the string using the pointer until the null terminator ('\0') or newline ('\n') is reached
    while (*ptr != '\0' && *ptr != '\n') {
        length++;
        ptr++; // Move the pointer to the next character address
    }

    // Alternatively, you can find the length using pointer subtraction:
    // ptr = str;
    // while (*ptr != '\0' && *ptr != '\n') { ptr++; }
    // int length = ptr - str; // Difference between final and initial memory addresses

    // Print the result
    printf("The length of the string is: %d\n", length);

    return 0;
}