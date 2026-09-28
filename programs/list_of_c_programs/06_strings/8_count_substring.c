#include <stdio.h>

int main() {
    char main_str[200], sub_str[100];
    int count = 0;

    printf("Enter the main string: ");
    scanf("%[^\n]s", main_str);

    // Read newline to clear input buffer
    char temp;
    scanf("%c", &temp);

    printf("Enter the sub string: ");
    scanf("%[^\n]s", sub_str);

    // Loop through each character of the main string
    for (int i = 0; main_str[i] != '\0'; i++) {
        int j = 0;

        // Check if characters match one by one
        while (sub_str[j] != '\0' && main_str[i + j] == sub_str[j]) {
            j++;
        }

        // If we reached the end of sub_str, we found a match!
        if (sub_str[j] == '\0') {
            count++;
        }
    }

    printf("\nOutput: count=%d\n", count);

    return 0;
}