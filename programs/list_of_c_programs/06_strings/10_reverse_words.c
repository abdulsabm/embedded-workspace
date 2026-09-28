#include <stdio.h>
#include <string.h>

int main() {
    char str[200];

    printf("Enter a string: ");
    scanf("%[^\n]s", str);

    int len = strlen(str);
    printf("len: %d", len);
    int end = len - 1;

    printf("Output: ");

    // Traverse the string backwards from the last character
    for (int i = len - 1; i >= 0; i--) {
        // When a space is found or we reach the start of the string
        if (str[i] == ' ' || i == 0) {
            int start;
            
            if (i == 0) {
                start = i;       // At index 0, start printing from character 0
            } else {
                start = i + 1;   // After a space, start printing from the next index
            }

            // Print the current word character by character
            for (int j = start; j <= end; j++) {
                printf("%c", str[j]);
            }

            // Print a space between words (except after the last word printed)
            if (i > 0) {
                printf(" ");
            }

            // Move the end pointer to the character before the space
            end = i - 1;
        }
    }

    printf("\n");

    return 0;
}