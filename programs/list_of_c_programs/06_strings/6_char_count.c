#include <stdio.h>

int main() {
    char str[100];
    int freq[256] = {0}; // Array to store frequency of ASCII characters

    printf("Enter a string: ");
    // Reads input string including spaces until enter key is pressed
    scanf("%[^\n]s", str);

    // Count frequency of each character
    for (int i = 0; str[i] != '\0'; i++) {
        unsigned char ch = str[i];
        if (ch != ' ') { // Ignore spaces
            freq[ch]++;
        }
    }

    // Print character frequencies in order of appearance
    printf("Output: ");
    for (int i = 0; str[i] != '\0'; i++) {
        unsigned char ch = str[i];
        if (ch != ' ' && freq[ch] > 0) {
            printf("%c=%d ", ch, freq[ch]);
            freq[ch] = 0; // Clear count so it doesn't print duplicates
        }
    }
    printf("\n");

    return 0;
}