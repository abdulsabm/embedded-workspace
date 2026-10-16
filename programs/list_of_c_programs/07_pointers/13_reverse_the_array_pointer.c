#include <stdio.h>
#include <stdlib.h> // Required for malloc() and free()

int main() {
    int n, i;
    int *arr, *rev_arr;

    // Prompt user for the size of the array
    printf("Enter the size of the array (N): ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Please enter a valid positive integer for N.\n");
        return 1;
    }

    // Dynamically allocate memory for original and reversed arrays
    arr = (int *)malloc(n * sizeof(int));
    rev_arr = (int *)malloc(n * sizeof(int));

    // Check if memory allocation was successful
    if (arr == NULL || rev_arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Reading elements into the original array using pointers
    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", arr + i); // arr + i gives the address of the i-th element
    }

    // Copy elements from 'arr' to 'rev_arr' using pointers
    for (i = 0; i < n; i++) {
        *(rev_arr + i) = *(arr + i);
    }

    // Reversing 'rev_arr' in-place using two pointer variables (start and end)
    for (i = 0; i < n; i++) {
        for(int j = 0; j< (n-i-1); j++){
            int temp = rev_arr[j];
            rev_arr[j] = rev_arr[j+1];
            rev_arr[j+1] = temp;
        }
    }

    // Printing the Original Array using pointers
    printf("\nOriginal Array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", *(arr + i));
    }

    // Printing the Reversed Array using pointers
    printf("\nReversed Array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", *(rev_arr + i));
    }
    printf("\n");

    // Free the dynamically allocated memory to prevent memory leaks
    free(arr);
    free(rev_arr);

    return 0;
}