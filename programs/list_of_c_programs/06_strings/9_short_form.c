#include <stdio.h>

int main() {
    char name[100];

    printf("Enter full name: ");
    scanf("%[^\n]s", name);

    printf("Output: ");

    // Print the first character of the first name
    if (name[0] != ' ' && name[0] != '\0') {
        printf("%c ", name[0]);
    }

    // Find space locations to print middle initials
    int last_space_index = -1;
    for (int i = 0; name[i] != '\0'; i++) {
        if (name[i] == ' ') {
            last_space_index = i;
        }
    }

    // Print initials for all middle names (if any)
    for (int i = 0; i < last_space_index; i++) {
        if (name[i] == ' ' && name[i + 1] != ' ' && name[i + 1] != '\0') {
            printf("%c ", name[i + 1]);
        }
    }

    // Print the last name completely
    if (last_space_index != -1) {
        for (int i = last_space_index + 1; name[i] != '\0'; i++) {
            printf("%c", name[i]);
        }
    }

    printf("\n");

    return 0;
}