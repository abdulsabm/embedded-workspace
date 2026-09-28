#include <stdio.h>
#include <string.h>

int main() {
    char name[100];

    printf("Enter your name: ");
    
    // Note: gets() is unsafe and removed in C11 standard
    gets(name);

    printf("Your name is: ");
    puts(name);

    return 0;
}
/*

int main() {
    char name[100];

    printf("Enter your name: ");
    
    // Reads up to sizeof(name) - 1 characters safely
    if (fgets(name, sizeof(name), stdin) != NULL) {
        // Strip trailing newline character added by fgets if present
        name[strcspn(name, "\n")] = '\0';
    }

    printf("Your name is: ");
    puts(name);

    return 0;
}
*/