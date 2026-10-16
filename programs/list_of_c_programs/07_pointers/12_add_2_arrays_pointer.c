#include <stdio.h>
#include <stdlib.h> // Required for malloc() and free()

int main() {
    int n, i;
    int *arr1, *arr2, *result;

    // Prompt user for the size of the arrays
    printf("Enter the size of the arrays (N): ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Please enter a valid positive integer for N.\n");
        return 1;
    }

    // Dynamically allocate memory for three arrays using pointers
    arr1 = (int *)malloc(n * sizeof(int));
    arr2 = (int *)malloc(n * sizeof(int));
    result = (int *)malloc(n * sizeof(int));

    // Check if memory allocation was successful for all arrays
    if (arr1 == NULL || arr2 == NULL || result == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Reading elements for Array 1 using pointer notation
    printf("Enter %d elements for Array 1:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", arr1 + i); // (arr1 + i) gives the address of the i-th element
    }

    // Reading elements for Array 2 using pointer notation
    printf("Enter %d elements for Array 2:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", arr2 + i); // (arr2 + i) gives the address of the i-th element
    }

    // Adding corresponding elements of Array 1 and Array 2
    for (i = 0; i < n; i++) {
        // *(arr1 + i) and *(arr2 + i) fetch values, stored into result's address
        *(result + i) = *(arr1 + i) + *(arr2 + i);
    }

    // Printing Array 1
    printf("\nArray 1: ");
    for (i = 0; i < n; i++) {
        printf("%d ", *(arr1 + i));
    }

    // Printing Array 2
    printf("\nArray 2: ");
    for (i = 0; i < n; i++) {
        printf("%d ", *(arr2 + i));
    }

    // Printing Resultant Array
    printf("\nResultant Array (Sum): ");
    for (i = 0; i < n; i++) {
        printf("%d ", *(result + i));
    }
    printf("\n");

    // Free the dynamically allocated memory to prevent memory leaks
    free(arr1);
    free(arr2);
    free(result);

    return 0;
}