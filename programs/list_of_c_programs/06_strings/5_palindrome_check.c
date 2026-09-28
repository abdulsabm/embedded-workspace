#include <stdio.h>
#include <string.h>

// Function to check if a string is palindrome
int isPalindrome(const char *str) {
    int left = 0;
    int right = strlen(str) - 1;

    while (left < right) {
        if (str[left] != str[right]) {
            return 0; // Not a palindrome
        }
        left++;
        right--;
    }
    return 1; // Is a palindrome
}

int main() {
    char str[100];

    printf("Enter a string: ");
    if (fgets(str, sizeof(str), stdin) != NULL) {
        // Strip trailing newline character added by fgets
        str[strcspn(str, "\n")] = '\0';
    }

    if (isPalindrome(str)) {
        printf("\"%s\" is a Palindrome.\n", str);
    } else {
        printf("\"%s\" is NOT a Palindrome.\n", str);
    }

    return 0;
}