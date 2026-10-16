#include <stdio.h>
#include <ctype.h>

int main() {
    char str[100];
    char occurance[26] = {0}; // Array to store the occurrence of each character (assuming only lowercase letters)
    char *ptr;

    // Prompt user for a string
    printf("Enter a string: ");
    // fgets is used safely to read a line of text including spaces
    fgets(str, sizeof(str), stdin);

    // Initialize pointer to the base address of the string
    ptr = str;

    // Traverse the string using the pointer until the null terminator ('\0') or newline ('\n') is reached
    while (*ptr != '\0' && *ptr != '\n') {
        if(isalpha(*ptr)) { // Check if the character is an alphabet
            if(islower(*ptr)) { // Check if the character is lowercase
                occurance[*ptr - 'a']++; // Increment the occurrence count for the lowercase letter
            } else if (isupper(*ptr)) { // Check if the character is uppercase
                occurance[*ptr - 'A']++; // Increment the occurrence count for the uppercase letter
            }   
        }
        ptr++; // Move the pointer to the next character address
    }

    // Print the occurrence of each character
    printf("Occurrence of each character:\n");
    for(int i = 0; i < 26; i++) {
        if(occurance[i] > 0) {
            printf("Character '%c': %d\n", 'a' + i, occurance[i]);
        }
    }

    return 0;
}