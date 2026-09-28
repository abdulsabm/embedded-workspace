#include <stdio.h>

int main() {
    char str[200];

    printf("Enter a string: ");
    scanf("%[^\n]s", str);

    int i = 0, j = 0;

    // Loop through the string
    while (str[i] != '\0') {
        // If current character is a space AND next character is also a space, skip it
        if (str[i] == ' ' && str[i + 1] == ' ') {
            i++;
        } else {
            // Copy character to new position
            str[j] = str[i];
            i++;
            j++;
        }
    }

    str[j] = '\0'; // Null-terminate the modified string

    printf("Output: %s\n", str);

    return 0;
}