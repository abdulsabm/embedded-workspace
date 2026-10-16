#include <stdio.h>

int main() {
    char str[200];
    char *src, *dst;

    // Prompt user for a string
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    // Initialize two pointers to the start of the string
    src = str; // Reader pointer
    dst = str; // Writer pointer

    // Traverse the string until the null terminator is reached
    while (*src != '\0') {
        // Check if the current character is NOT a whitespace (space, tab, or newline)
        if (*src != ' ' && *src != '\t' && *src != '\n' && *src != '\r') {
            *dst = *src; // Copy valid character to the writer position
            dst++;       // Advance the destination pointer
        }
        src++; // Always advance the source pointer
    }

    // Null-terminate the modified string at the new destination pointer position
    *dst = '\0';

    // Print the result
    printf("String after removing white spaces: %s\n", str);

    return 0;
}