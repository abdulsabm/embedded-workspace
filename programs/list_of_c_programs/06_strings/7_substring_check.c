#include <stdio.h>

// Function to check if sub_str is present in main_str
int isSubstring(const char *main_str, const char *sub_str) {
    // Empty substring is always present
    if (sub_str[0] == '\0') {
        return 1;
    }

    for (int i = 0; main_str[i] != '\0'; i++) {
        int j = 0;

        // Compare sub_str with main_str starting from index i
        while (main_str[i + j] != '\0' && sub_str[j] != '\0' && main_str[i + j] == sub_str[j]) {
            j++;
        }

        // If we reached the end of sub_str, all characters matched
        if (sub_str[j] == '\0') {
            return 1; // Substring found
        }
    }

    return 0; // Substring not found
}

int main() {
    char main_str[100], sub_str[100];

    printf("Enter the main string: ");
    scanf("%[^\n]s", main_str);

    // Clear the input buffer before reading the second string
    scanf(" %1[\n]", sub_str); // Consumes leftover newline

    printf("Enter the sub string: ");
    scanf("%[^\n]s", sub_str);

    if (isSubstring(main_str, sub_str)) {
        printf("\nOutput: Substring \"%s\" is PRESENT in the main string.\n", sub_str);
    } else {
        printf("\nOutput: Substring \"%s\" is NOT PRESENT in the main string.\n", sub_str);
    }

    return 0;
}