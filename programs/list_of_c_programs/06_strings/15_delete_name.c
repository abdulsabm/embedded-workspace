#include <stdio.h>
#include <string.h>

int main() {
    int n;

    printf("Enter number of names (N): ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid number of names.\n");
        return 0;
    }

    char names[100][100];
    char target[100];
    char ch;

    // Clear leftover newline from input buffer
    scanf("%c", &ch);

    // Read N names
    printf("Enter %d names:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Name %d: ", i + 1);
        scanf("%[^\n]s", names[i]);
        scanf("%c", &ch); // Clear newline after each string
    }

    // Read target name to delete
    printf("\nEnter the name to delete: ");
    scanf("%[^\n]s", target);

    int found = 0;

    // Search and delete by shifting elements left
    for (int i = 0; i < n; i++) {
        if (strcmp(names[i], target) == 0) {
            found = 1;
            
            // Shift remaining elements one position to the left
            for (int j = i; j < n - 1; j++) {
                strcpy(names[j], names[j + 1]);
            }
            
            n--; // Reduce total count of names
            i--; // Decrement index to check the newly shifted element at position i
        }
    }

    // Display result
    if (found) {
        printf("\nOutput: Name \"%s\" deleted successfully.\n", target);
        printf("\nUpdated list of names (%d total):\n", n);
        for (int i = 0; i < n; i++) {
            printf("%d. %s\n", i + 1, names[i]);
        }
    } else {
        printf("\nOutput: Name \"%s\" not found in the list.\n", target);
    }

    return 0;
}