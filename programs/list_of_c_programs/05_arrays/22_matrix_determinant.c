#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to calculate determinant using Gaussian Elimination (O(N^3))
double computeDeterminant(int n, double matrix[n][n]) {
    double det = 1.0;

    // Create a working copy to preserve the original matrix
    double mat[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            mat[i][j] = matrix[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        // Find pivot element for numerical stability
        int pivot = i;
        for (int k = i + 1; k < n; k++) {
            if (fabs(mat[k][i]) > fabs(mat[pivot][i])) {
                pivot = k;
            }
        }

        // Swap current row with pivot row
        if (pivot != i) {
            for (int k = 0; k < n; k++) {
                double temp = mat[i][k];
                mat[i][k] = mat[pivot][k];
                mat[pivot][k] = temp;
            }
            det *= -1; // Swapping two rows flips the sign of determinant
        }

        // If diagonal entry is 0, matrix is singular (determinant = 0)
        if (fabs(mat[i][i]) < 1e-9) {
            return 0.0;
        }

        det *= mat[i][i];

        // Perform row reduction below the pivot
        for (int k = i + 1; k < n; k++) {
            double factor = mat[k][i] / mat[i][i];
            for (int j = i + 1; j < n; j++) {
                mat[k][j] -= factor * mat[i][j];
            }
        }
    }

    return det;
}

int main() {
    int m, n;

    printf("Enter number of rows (m): ");
    if (scanf("%d", &m) != 1 || m <= 0) return 1;

    printf("Enter number of columns (n): ");
    if (scanf("%d", &n) != 1 || n <= 0) return 1;

    // Check if the matrix is square
    if (m != n) {
        printf("\nError: Determinant can only be calculated for square matrices (m == n).\n");
        return 1;
    }

    double matrix[n][n];

    printf("\nEnter elements of the %dx%d matrix:\n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("Matrix[%d][%d]: ", i, j);
            scanf("%lf", &matrix[i][j]);
        }
    }

    // Display original matrix
    printf("\nInput Matrix (%dx%d):\n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%.2f\t", matrix[i][j]);
        }
        printf("\n");
    }

    // Calculate and print determinant
    double det = computeDeterminant(n, matrix);
    printf("\nDeterminant of the matrix = %.2f\n", det);

    return 0;
}