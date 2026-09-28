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

    char names[100][100]; // Array to store up to 100 names of max length 99
    char temp[100];       // Temporary array used for swapping

    // Clear leftover newline character after reading N
    char ch;
    scanf("%c", &ch);

    // Read N names
    printf("Enter %d names:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Name %d: ", i + 1);
        scanf("%[^\n]s", names[i]);

        // Consume newline character after each string input
        scanf("%c", &ch);
    }

    // Sort names in ascending order using Bubble Sort
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            // Compare adjacent strings
            if (strcmp(names[j], names[j + 1]) > 0) {
                // Swap names[j] and names[j + 1]
                strcpy(temp, names[j]);
                strcpy(names[j], names[j + 1]);
                strcpy(names[j + 1], temp);
            }
        }
    }

    // Print the sorted names
    printf("\nNames in Ascending Order:\n");
    for (int i = 0; i < n; i++) {
        printf("%d. %s\n", i + 1, names[i]);
    }

    return 0;
}