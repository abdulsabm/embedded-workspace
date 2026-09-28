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

    char names[100][100]; // Can hold up to 100 names
    char temp[100];
    char new_name[100];
    char ch;

    // Clear leftover newline from buffer
    scanf("%c", &ch);

    // Read N names
    printf("Enter %d names:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Name %d: ", i + 1);
        scanf("%[^\n]s", names[i]);
        scanf("%c", &ch); // Consume newline
    }

    // Step 1: Sort the initial N names in ascending order (Bubble Sort)
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (strcmp(names[j], names[j + 1]) > 0) {
                strcpy(temp, names[j]);
                strcpy(names[j], names[j + 1]);
                strcpy(names[j + 1], temp);
            }
        }
    }

    printf("\nSorted list before insertion:\n");
    for (int i = 0; i < n; i++) {
        printf("%d. %s\n", i + 1, names[i]);
    }

    // Step 2: Read the new name to insert
    printf("\nEnter a new name to insert: ");
    scanf("%[^\n]s", new_name);

    // Step 3: Find the correct position and shift elements to the right
    int position = n; // Default position is at the end

    for (int i = 0; i < n; i++) {
        // If new_name comes before names[i] in dictionary order
        if (strcmp(new_name, names[i]) < 0) {
            position = i;
            break;
        }
    }

    // Shift elements right starting from the end down to 'position'
    for (int j = n; j > position; j--) {
        strcpy(names[j], names[j - 1]);
    }

    // Insert new_name at the correct spot
    strcpy(names[position], new_name);
    n++; // Increase list count

    // Step 4: Display the final updated list
    printf("\nUpdated list after inserting \"%s\":\n", new_name);
    for (int i = 0; i < n; i++) {
        printf("%d. %s\n", i + 1, names[i]);
    }

    return 0;
}