#include <stdio.h>

int main() {
    int m1, n1, m2, n2;

    // Dimensions for First Matrix
    printf("Enter rows (m1) and columns (n1) for First Matrix: ");
    if (scanf("%d %d", &m1, &n1) != 2 || m1 <= 0 || n1 <= 0) return 1;

    // Dimensions for Second Matrix
    printf("Enter rows (m2) and columns (n2) for Second Matrix: ");
    if (scanf("%d %d", &m2, &n2) != 2 || m2 <= 0 || n2 <= 0) return 1;

    // Matrix Multiplication Condition: Columns of Matrix 1 == Rows of Matrix 2
    if (n1 != m2) {
        printf("\nError: Matrix multiplication not possible!\n");
        printf("Columns of First Matrix (%d) must equal Rows of Second Matrix (%d).\n", n1, m2);
        return 1;
    }

    int mat1[m1][n1], mat2[m2][n2], prod[m1][n2];

    // Input First Matrix
    printf("\nEnter elements of First Matrix (%dx%d):\n", m1, n1);
    for (int i = 0; i < m1; i++) {
        for (int j = 0; j < n1; j++) {
            printf("Mat1[%d][%d]: ", i, j);
            scanf("%d", &mat1[i][j]);
        }
    }

    // Input Second Matrix
    printf("\nEnter elements of Second Matrix (%dx%d):\n", m2, n2);
    for (int i = 0; i < m2; i++) {
        for (int j = 0; j < n2; j++) {
            printf("Mat2[%d][%d]: ", i, j);
            scanf("%d", &mat2[i][j]);
        }
    }

    // Initialize Product Matrix elements to 0 and compute product
    for (int i = 0; i < m1; i++) {
        for (int j = 0; j < n2; j++) {
            prod[i][j] = 0;
            for (int k = 0; k < n1; k++) {
                prod[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }

    // Display First Matrix
    printf("\n--- First Matrix (%dx%d) ---\n", m1, n1);
    for (int i = 0; i < m1; i++) {
        for (int j = 0; j < n1; j++) {
            printf("%d\t", mat1[i][j]);
        }
        printf("\n");
    }

    // Display Second Matrix
    printf("\n--- Second Matrix (%dx%d) ---\n", m2, n2);
    for (int i = 0; i < m2; i++) {
        for (int j = 0; j < n2; j++) {
            printf("%d\t", mat2[i][j]);
        }
        printf("\n");
    }

    // Display Resultant Product Matrix
    printf("\n--- Resultant Product Matrix (%dx%d) ---\n", m1, n2);
    for (int i = 0; i < m1; i++) {
        for (int j = 0; j < n2; j++) {
            printf("%d\t", prod[i][j]);
        }
        printf("\n");
    }

    return 0;
}