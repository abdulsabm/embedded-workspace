#include <stdio.h>

// Function with a 'void' return type (returns nothing)
// - arr: Pointer to the starting address of the array
// - n: Size of the array
// - evenCount: Pointer to store the count of even numbers
// - oddCount: Pointer to store the count of odd numbers
void countEvenOdd(int *arr, int n, int *evenCount, int *oddCount) {
    // Initialize counts to zero via dereferenced pointers
    *evenCount = 0;
    *oddCount = 0;

    for (int i = 0; i < n; i++) {
        // Using pointer arithmetic: *(arr + i) accesses each element
        if (*(arr + i) % 2 == 0) {
            (*evenCount)++; // Increment the even count in main()
        } else {
            (*oddCount)++;  // Increment the odd count in main()
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
    int even_count = 0, odd_count = 0;

    // Read array elements from the user
    printf("Enter %d integers separated by spaces: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Call the function by passing:
    // 1. The starting address of the array ('arr')
    // 2. The size of the array ('n')
    // 3. The addresses of both count variables (&even_count, &odd_count)
    countEvenOdd(arr, n, &even_count, &odd_count);

    // Display the computed results in main()
    printf("\n--- Results Displayed in main() ---\n");
    printf("Array elements: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    printf("Total Even numbers: %d\n", even_count);
    printf("Total Odd numbers: %d\n", odd_count);

    return 0;
}