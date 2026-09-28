#include <stdio.h>

int main() {
    int m, n;

    // Read dimensions of the 2D array
    printf("Enter number of rows (m): ");
    if (scanf("%d", &m) != 1 || m <= 0) return 1;

    printf("Enter number of columns (n): ");
    if (scanf("%d", &n) != 1 || n <= 0) return 1;

    int arr[m][n];

    // Read elements of the 2D array
    printf("\nEnter elements of the %dx%d array:\n", m, n);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }

    // Print the array in m rows and n columns
    printf("\nThe 2D Array (%dx%d Matrix):\n", m, n);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d\t", arr[i][j]); // Tab space for clean column alignment
        }
        printf("\n"); // Move to the next line after completing each row
    }

    return 0;
}