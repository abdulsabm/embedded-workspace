#include <stdio.h>

// ==========================================
// CUSTOM STRING FUNCTIONS USING POINTERS
// ==========================================

// a) strlen: Calculates the length of a string (excluding '\0')
size_t my_strlen(const char *str) {
    const char *ptr = str;
    while (*ptr != '\0') {
        ptr++;
    }
    return (size_t)(ptr - str); // Pointer arithmetic to get length
}

// b1) strcpy: Copies source string into destination
char* my_strcpy(char *dest, const char *src) {
    char *ptr = dest;
    while ((*dest++ = *src++) != '\0'); // Copy character and advance pointers
    return ptr;
}

// b2) strncpy: Copies up to 'n' characters from source to destination
char* my_strncpy(char *dest, const char *src, size_t n) {
    size_t i = 0;
    while (i < n && src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    // Pad remaining bytes with '\0' if n is greater than src length
    while (i < n) {
        dest[i] = '\0';
        i++;
    }
    return dest;
}

// c1) strcmp: Compares two strings lexicographically
int my_strcmp(const char *s1, const char *s2) {
    while (*s1 && (*s1 == *s2)) {
        s1++;
        s2++;
    }
    return *(unsigned char *)s1 - *(unsigned char *)s2;
}

// c2) strncmp: Compares up to 'n' characters of two strings
int my_strncmp(const char *s1, const char *s2, size_t n) {
    if (n == 0) return 0;
    while (n-- > 0 && *s1 && (*s1 == *s2)) {
        if (n == 0 || *s1 == '\0') break;
        s1++;
        s2++;
    }
    return *(unsigned char *)s1 - *(unsigned char *)s2;
}

// d1) strcat: Appends source string to the end of destination string
char* my_strcat(char *dest, const char *src) {
    char *ptr = dest;
    // Move pointer to the end of destination string (null terminator)
    while (*ptr != '\0') {
        ptr++;
    }
    // Copy src characters to the end of dest
    while ((*ptr++ = *src++) != '\0');
    return dest;
}

// d2) strncat: Appends up to 'n' characters from source to destination string
char* my_strncat(char *dest, const char *src, size_t n) {
    char *ptr = dest;
    // Find the end of destination string
    while (*ptr != '\0') {
        ptr++;
    }
    size_t i = 0;
    while (i < n && src[i] != '\0') {
        *ptr++ = src[i++];
    }
    *ptr = '\0'; // Always ensure null-termination
    return dest;
}

// ==========================================
// MAIN FUNCTION (TESTING ALL FUNCTIONS)
// ==========================================
int main() {
    // 1. Testing strlen
    char str1[] = "Hello, C!";
    printf("--- a) strlen ---\n");
    printf("Length of \"%s\" is: %zu\n\n", str1, my_strlen(str1));

    // 2. Testing strcpy & strncpy
    char dest1[50];
    char dest2[50];
    my_strcpy(dest1, "Programming");
    my_strncpy(dest2, "Algorithms", 4);
    dest2[4] = '\0'; // Explicit null termination for safety with strncpy output
    printf("--- b) strcpy & strncpy ---\n");
    printf("strcpy result: %s\n", dest1);
    printf("strncpy (4 chars) result: %s\n\n", dest2);

    // 3. Testing strcmp & strncmp
    char sA[] = "Apple";
    char sB[] = "Appetizer";
    printf("--- c) strcmp & strncmp ---\n");
    printf("strcmp(\"%s\", \"%s\") = %d\n", sA, sB, my_strcmp(sA, sB));
    printf("strncmp(\"%s\", \"%s\", 3) = %d\n\n", sA, sB, my_strncmp(sA, sB, 3));

    // 4. Testing strcat & strncat
    char baseStr[50] = "Data ";
    char appendStr[] = "Structures & Pointers";
    my_strcat(baseStr, appendStr);
    printf("--- d) strcat & strncat ---\n");
    printf("strcat result: %s\n", baseStr);

    char baseStr2[50] = "Code ";
    my_strncat(baseStr2, "Generation Engine", 6);
    printf("strncat result: %s\n", baseStr2);

    return 0;
}