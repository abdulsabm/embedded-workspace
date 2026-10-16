#include <stdio.h>

// Function with a 'void' return type (returns nothing)
// - arr: Pointer to the starting address of the array
// - n: Size of the array
// - max: Pointer to store the largest element
// - min: Pointer to store the smallest element
void findMinMax(int *arr, int n, int *max, int *min) {
    if (n <= 0) {
        return;
    }

    // Initialize both max and min with the first element of the array
    *max = *arr;
    *min = *arr;

    // Traverse the array starting from the second element
    for (int i = 1; i < n; i++) {
        // Using pointer arithmetic: *(arr + i) is equivalent to arr[i]
        if (*(arr + i) > *max) {
            *max = *(arr + i); // Update max if a larger element is found
        }
        if (*(arr + i) < *min) {
            *min = *(arr + i); // Update min if a smaller element is found
        }
    }
}

int main() {
    int n;

    // Prompt user for the number of elements
    printf("Enter the size of the array (N): ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid size! Please enter a positive integer.\n");
        return 1;
    }

    int arr[n];
    int largest, smallest;

    // Read array elements from the user
    printf("Enter %d integers separated by spaces: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Call the function by passing:
    // 1. The starting address of the array ('arr')
    // 2. The size of the array ('n')
    // 3. The addresses of 'largest' and 'smallest' variables (&largest, &smallest)
    findMinMax(arr, n, &largest, &smallest);

    // Display the computed results in main()
    printf("\n--- Results Displayed in main() ---\n");
    printf("Array elements: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    printf("Largest element: %d\n", largest);
    printf("Smallest element: %d\n", smallest);

    return 0;
}