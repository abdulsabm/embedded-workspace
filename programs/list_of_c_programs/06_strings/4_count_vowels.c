#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to check if a character is a vowel
int isVowel(char ch) {
    ch = tolower(ch); // Convert to lowercase for uniform comparison
    return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
}

// Function to count total vowels in a string
int countVowels(const char *str) {
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (isVowel(str[i])) {
            count++;
        }
    }
    return count;
}

int main() {
    char str[100];

    printf("Enter a string: ");
    if (fgets(str, sizeof(str), stdin) != NULL) {
        // Strip trailing newline character added by fgets
        str[strcspn(str, "\n")] = '\0';
    }

    int total_vowels = countVowels(str);

    printf("Total number of vowels in \"%s\": %d\n", str, total_vowels);

    return 0;
}