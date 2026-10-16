#include <stdio.h>

int main() {
    char original[200], modified[200];
    char *src_ptr, *dest_ptr, *print_ptr;

    // Prompt user for a string
    printf("Enter a string: ");
    fgets(original, sizeof(original), stdin);

    // Remove the trailing newline character added by fgets, if present
    print_ptr = original;
    while (*print_ptr != '\0') {
        if (*print_ptr == '\n') {
            *print_ptr = '\0';
            break;
        }
        print_ptr++;
    }

    // Step 1: Copy 'original' string to 'modified' string using pointers
    src_ptr = original;
    dest_ptr = modified;
    while (*src_ptr != '\0') {
        *dest_ptr = *src_ptr;
        src_ptr++;
        dest_ptr++;
    }
    *dest_ptr = '\0'; // Null-terminate the copied string

    // Step 2: Toggle case in the 'modified' string using pointers
    dest_ptr = modified; // Reset pointer to the start of modified string
    while (*dest_ptr != '\0') {
        // If character is lowercase, convert to uppercase (subtract 32 in ASCII)
        if (*dest_ptr >= 'a' && *dest_ptr <= 'z') {
            *dest_ptr = *dest_ptr - 32;
        }
        // If character is uppercase, convert to lowercase (add 32 in ASCII)
        else if (*dest_ptr >= 'A' && *dest_ptr <= 'Z') {
            *dest_ptr = *dest_ptr + 32;
        }
        dest_ptr++; // Move to the next character
    }

    // Step 3: Print the Original String using pointers
    printf("\nOriginal String: ");
    print_ptr = original;
    while (*print_ptr != '\0') {
        printf("%c", *print_ptr);
        print_ptr++;
    }

    // Step 4: Print the Modified (Toggled) String using pointers
    printf("\nToggled Case String: ");
    print_ptr = modified;
    while (*print_ptr != '\0') {
        printf("%c", *print_ptr);
        print_ptr++;
    }
    printf("\n");

    return 0;
}