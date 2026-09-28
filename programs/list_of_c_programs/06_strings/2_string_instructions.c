#include <stdio.h>

// a> Custom strlen: Calculates length of string excluding null terminator
size_t my_strlen(const char *str) {
    size_t len = 0;
    while (str[len] != '\0') {
        len++;
    }
    return len;
}

// b1> Custom strcpy: Copies source string to destination string
char *my_strcpy(char *dest, const char *src) {
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0'; // Append null terminator
    return dest;
}

// b2> Custom strncpy: Copies up to 'n' characters from src to dest
char *my_strncpy(char *dest, const char *src, size_t n) {
    size_t i;
    for (i = 0; i < n && src[i] != '\0'; i++) {
        dest[i] = src[i];
    }
    // Pad remaining space with '\0' if src length < n
    for (; i < n; i++) {
        dest[i] = '\0';
    }
    return dest;
}

// c1> Custom strcmp: Lexicographically compares two strings
int my_strcmp(const char *s1, const char *s2) {
    int i = 0;
    while (s1[i] != '\0' && s1[i] == s2[i]) {
        i++;
    }
    return (unsigned char)s1[i] - (unsigned char)s2[i];
}

// c2> Custom strncmp: Compares up to 'n' characters of two strings
int my_strncmp(const char *s1, const char *s2, size_t n) {
    if (n == 0) return 0;

    size_t i = 0;
    while (i < n - 1 && s1[i] != '\0' && s1[i] == s2[i]) {
        i++;
    }
    return (unsigned char)s1[i] - (unsigned char)s2[i];
}

// d1> Custom strcat: Appends source string to destination string
char *my_strcat(char *dest, const char *src) {
    int dest_len = my_strlen(dest);
    int i = 0;

    while (src[i] != '\0') {
        dest[dest_len + i] = src[i];
        i++;
    }
    dest[dest_len + i] = '\0'; // Append null terminator
    return dest;
}

// d2> Custom strncat: Appends up to 'n' characters from src to dest
char *my_strncat(char *dest, const char *src, size_t n) {
    int dest_len = my_strlen(dest);
    size_t i = 0;

    while (i < n && src[i] != '\0') {
        dest[dest_len + i] = src[i];
        i++;
    }
    dest[dest_len + i] = '\0'; // Always null terminate
    return dest;
}

int main() {
    char str1[100] = "Hello";
    char str2[100] = "World";
    char buffer[100];

    printf("--- Testing String Functions ---\n\n");

    // a> strlen
    printf("1. my_strlen(\"%s\"): %zu\n\n", str1, my_strlen(str1));

    // b> strcpy & strncpy
    my_strcpy(buffer, str1);
    printf("2a. my_strcpy(buffer, \"%s\") -> buffer: \"%s\"\n", str1, buffer);

    my_strncpy(buffer, str2, 3);
    buffer[3] = '\0'; // Ensure printing safety for partial copy
    printf("2b. my_strncpy(buffer, \"%s\", 3) -> buffer: \"%s\"\n\n", str2, buffer);

    // c> strcmp & strncmp
    printf("3a. my_strcmp(\"Hello\", \"Hello\"): %d\n", my_strcmp("Hello", "Hello"));
    printf("3b. my_strcmp(\"Hello\", \"World\"): %d\n", my_strcmp("Hello", "World"));
    printf("3c. my_strncmp(\"Hello\", \"Help\", 2): %d (matching first 2 chars)\n", my_strncmp("Hello", "Help", 2));
    printf("3d. my_strncmp(\"Hello\", \"Help\", 4): %d (comparing first 4 chars)\n\n", my_strncmp("Hello", "Help", 4));

    // d> strcat & strncat
    my_strcpy(buffer, "Hello ");
    my_strcat(buffer, "World");
    printf("4a. my_strcat -> buffer: \"%s\"\n", buffer);

    my_strcpy(buffer, "Hello ");
    my_strncat(buffer, "World", 3);
    printf("4b. my_strncat(..., 3) -> buffer: \"%s\"\n", buffer);

    return 0;
}