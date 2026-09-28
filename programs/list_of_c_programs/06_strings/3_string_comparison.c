#include <stdio.h>
#include <string.h>

// Custom function to compare strings lexicographically
int compare_strings(const char *s1, const char *s2) {
    int i = 0;
    while (s1[i] != '\0' && s1[i] == s2[i]) {
        i++;
    }
    return (unsigned char)s1[i] - (unsigned char)s2[i];
}

int main() {
    char str1[100], str2[100];

    printf("Enter the first string: ");
    if (fgets(str1, sizeof(str1), stdin) != NULL) {
        str1[strcspn(str1, "\n")] = '\0'; // Remove trailing newline
    }

    printf("Enter the second string: ");
    if (fgets(str2, sizeof(str2), stdin) != NULL) {
        str2[strcspn(str2, "\n")] = '\0'; // Remove trailing newline
    }

    int result = compare_strings(str1, str2);

    printf("\n--- Comparison Result ---\n");
    if (result == 0) {
        printf("First string (\"%s\") is EQUAL to Second string (\"%s\").\n", str1, str2);
    } else if (result > 0) {
        printf("First string (\"%s\") is GREATER than Second string (\"%s\").\n", str1, str2);
    } else {
        printf("First string (\"%s\") is LESSER than Second string (\"%s\").\n", str1, str2);
    }

    return 0;
}