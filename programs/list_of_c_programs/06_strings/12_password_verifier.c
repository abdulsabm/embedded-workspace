#include <stdio.h>

// Custom string comparison function
int isPasswordCorrect(const char *input, const char *predefined) {
    int i = 0;
    while (input[i] != '\0' && predefined[i] != '\0') {
        if (input[i] != predefined[i]) {
            return 0; // Characters mismatch
        }
        i++;
    }
    // Both must reach null-terminator at the same time to be identical
    return (input[i] == '\0' && predefined[i] == '\0');
}

int main() {
    // Predefined secret password
    const char SECRET_PASSWORD[] = "Admin@123";
    char user_input[100];

    printf("Enter Password: ");
    // Reads input string without spaces up to newline
    scanf("%s", user_input);

    if (isPasswordCorrect(user_input, SECRET_PASSWORD)) {
        printf("\nOutput: Access Granted! Welcome.\n");
    } else {
        printf("\nOutput: Access Denied! Incorrect Password.\n");
    }

    return 0;
}