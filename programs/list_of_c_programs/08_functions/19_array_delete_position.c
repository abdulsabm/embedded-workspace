#include <stdio.h>

// Function to delete an element from the Nth position.
// - arr: Pointer to the starting address of the array
// - n: Pointer to the size variable (passed by reference so we can update/decrement it)
// - pos: The 1-based position of the element to delete (e.g., pos=3 means the 3rd element)
void deleteElement(int *arr, int *n, int pos) {
    // Validate the position
    if (pos < 1 || pos > *n) {
        printf("Error: Invalid position! Position must be between 1 and %d.\n", *n);
        return;
    }

    // Convert 1-based position to 0-based index
    int index = pos - 1;

    // Shift elements to the left starting from the deletion index
    for (int i = index; i < *n - 1; i++) {
        // Using pointer arithmetic: *(arr + i) is equivalent to arr[i]
        *(arr + i) = *(arr + i + 1);
    }

    // Decrement the size of the array via pointer since one element was removed
    (*n)--;
}

int main() {
    int n, pos;

    // Prompt user for the number of elements
    printf("Enter the size of the array (N): ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid size! Please enter a positive integer.\n");
        return 1;
    }

    // Variable Length Array (VLA)
    int arr[n];

    // Read array elements from the user
    printf("Enter %d integers separated by spaces: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Prompt user for the position to delete
    printf("Enter the position (1-based) of the element to delete: ");
    if (scanf("%d", &pos) != 1) {
        printf("Invalid position input!\n");
        return 1;
    }

    // Call the function by passing:
    // 1. The base address of the array ('arr')
    // 2. The address of the size variable ('&n') so the function can update it
    // 3. The position value ('pos')
    deleteElement(arr, &n, pos);

    // Display the resultant array in main()
    printf("\n--- Resultant Array ---\n");
    printf("Resultant array elements: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\nNew size of array: %d\n", n);

    return 0;
}