#include <stdio.h>

// Function that accepts the starting address of the string (const char *str) 
// and the key character to search for (char key). It returns the total count.
int countOccurrence(const char *str, char key) {
    int count = 0;

    // Traverse the string using pointer traversal until the null terminator is reached
    while (*str != '\0') {
        if (*str == key) {
            count++; // Increment count if character matches the key
        }
        str++; // Advance the pointer to the next memory address
    }

    return count;
}

int main() {
    char str[100];
    char key;

    // Prompt user for string input
    printf("Enter a string: ");
    // Using fgets safely to read a line of text (including spaces)
    if (fgets(str, sizeof(str), stdin) != NULL) {
        // Remove the trailing newline character left by fgets if present
        int i = 0;
        while (str[i] != '\0') {
            if (str[i] == '\n') {
                str[i] = '\0';
                break;
            }
            i++;
        }
    }

    // Prompt user for the key character to search for
    printf("Enter the character to count (key): ");
    // Note: The space before %c is crucial to skip any leftover whitespace/newline in the input buffer
    scanf(" %c", &key);

    // Call the function by passing:
    // 1. The starting address of the string ('str' decays to &str[0])
    // 2. The key character itself
    int total_count = countOccurrence(str, key);

    // Display the result in main()
    printf("\n--- Results Displayed in main() ---\n");
    printf("String: \"%s\"\n", str);
    printf("Character to search for: '%c'\n", key);
    printf("Occurrence count: %d\n", total_count);

    return 0;
}