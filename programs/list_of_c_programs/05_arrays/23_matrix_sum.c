#include <stdio.h>

int main() {
    int m, n;

    // Read dimensions of the matrices
    printf("Enter number of rows (m): ");
    if (scanf("%d", &m) != 1 || m <= 0) return 1;

    printf("Enter number of columns (n): ");
    if (scanf("%d", &n) != 1 || n <= 0) return 1;

    int matrix1[m][n], matrix2[m][n], sumMatrix[m][n];

    // Read First Matrix
    printf("\nEnter elements of First Matrix (%dx%d):\n", m, n);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("Matrix1[%d][%d]: ", i, j);
            scanf("%d", &matrix1[i][j]);
        }
    }

    // Read Second Matrix
    printf("\nEnter elements of Second Matrix (%dx%d):\n", m, n);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("Matrix2[%d][%d]: ", i, j);
            scanf("%d", &matrix2[i][j]);
        }
    }

    // Calculate Sum of Matrices
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            sumMatrix[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }

    // Display First Matrix
    printf("\n--- First Matrix ---\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d\t", matrix1[i][j]);
        }
        printf("\n");
    }

    // Display Second Matrix
    printf("\n--- Second Matrix ---\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d\t", matrix2[i][j]);
        }
        printf("\n");
    }

    // Display Resultant Sum Matrix
    printf("\n--- Resultant Sum Matrix ---\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d\t", sumMatrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}