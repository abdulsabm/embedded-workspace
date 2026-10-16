#include <stdio.h>

// Function that accepts the starting address of the array (int *arr) and its size (int n)
// It returns the calculated average as a double for floating-point precision.
double calculateAverage(int *arr, int n) {
    if (n <= 0) {
        return 0.0;
    }

    long long sum = 0; // Use long long to prevent sum overflow for large arrays

    for (int i = 0; i < n; i++) {
        // Accessing array elements using pointer arithmetic: *(arr + i)
        // Alternatively, arr[i] works identically in C.
        sum += *(arr + i);
    }

    // Cast sum to double before dividing to ensure accurate floating-point division
    return (double)sum / n;
}

int main() {
    int n;

    // Prompt user for the number of elements
    printf("Enter the number of elements (N): ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid size! Please enter a positive integer.\n");
        return 1;
    }

    // Variable Length Array (VLA) supported in C99 and later standards
    int arr[n];

    // Read array elements from the user
    printf("Enter %d integers separated by spaces: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Call the function by passing:
    // 1. The starting address of the array (passing 'arr' decays to its base address &arr[0])
    // 2. The size of the array 'n'
    double avg = calculateAverage(arr, n);

    // Display the result
    printf("\n--- Results --\n");
    printf("The average of the %d numbers is: %.4f\n", n, avg);

    return 0;
}