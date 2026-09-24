#include <stdio.h>

int main() {
    int len;
    printf("Enter the histogram length: ");
    if (scanf("%d", &len) != 1) return 1;

    // Convert even length to odd length for symmetry
    if (len % 2 == 0) {
        len++;
    }

    for (int i = 0; i < len; i++) {
        int max_val = i + 1;

        // Print leading spaces (3 spaces per step to match %2d + 1 space)
        for (int k = 0; k < (len - i - 1); k++) {
            printf("   ");
        }

        // Descending sequence: max_val down to 1
        for (int val = max_val; val >= 1; val--) {
            printf("%2d ", val);
        }

        // Ascending sequence: 2 up to max_val
        for (int val = 2; val <= max_val; val++) {
            printf("%2d ", val);
        }

        printf("\n");
    }

    return 0;
}