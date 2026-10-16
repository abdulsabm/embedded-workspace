#include <stdio.h>

// Function that accepts the starting addresses of both arrays and the size.
// It reverses elements from array 'a' and stores them into array 'rev'.
// The function returns nothing (void) because changes happen directly via pointers.
void reverseArray(int *a, int *rev, int n) {
    for (int i = 0; i < n; i++) {
        // Copy elements from the end of array 'a' into the beginning of array 'rev'
        // Using pointer arithmetic: 
        // *(a + (n - 1 - i)) points to the element from the back of 'a'
        // *(rev + i) points to the current position in 'rev'
        *(rev + i) = *(a + (n - 1 - i));
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

    int a[n];
    int rev[n]; // Second array to store the reversed elements

    // Read array elements from the user
    printf("Enter %d integers separated by spaces: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    // Call the function by passing the base addresses of both arrays and the size
    // Note: Passing array names 'a' and 'rev' automatically passes their starting addresses.
    reverseArray(a, rev, n);

    // Display both arrays in main()
    printf("\n--- Results ---\n");
    
    printf("Original Array (a): ");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    printf("Reversed Array (rev): ");
    for (int i = 0; i < n; i++) {
        printf("%d ", rev[i]);
    }
    printf("\n");

    return 0;
}