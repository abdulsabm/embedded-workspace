#include <stdio.h>
#include <string.h>

int main() {
    int n;
    char current_str[100];
    char greatest_str[100];

    printf("Enter total number of strings (N): ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid number of strings.\n");
        return 0;
    }

    // Clear leftover newline from input buffer
    char temp;
    scanf("%c", &temp);

    // Read the first string and set it as the initial greatest
    printf("Enter string 1: ");
    scanf("%[^\n]s", current_str);
    strcpy(greatest_str, current_str);

    // Read remaining N - 1 strings and compare
    for (int i = 2; i <= n; i++) {
        // Clear newline buffer before reading next line
        scanf("%c", &temp);

        printf("Enter string %d: ", i);
        scanf("%[^\n]s", current_str);

        // If current_str is greater than greatest_str in dictionary order
        if (strcmp(current_str, greatest_str) > 0) {
            strcpy(greatest_str, current_str);
        }
    }

    printf("\nOutput: The greatest string is \"%s\"\n", greatest_str);

    return 0;
}