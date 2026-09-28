#include <stdio.h>

int main() {
    int m, n;

    printf("Enter the size of first array (M): ");
    if (scanf("%d", &m) != 1 || m <= 0) return 1;

    int arr1[m];
    printf("Enter elements of first array:\n");
    for (int i = 0; i < m; i++) {
        scanf("%d", &arr1[i]);
    }

    printf("Enter the size of second array (N): ");
    if (scanf("%d", &n) != 1 || n <= 0) return 1;

    int arr2[n];
    printf("Enter elements of second array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr2[i]);
    }

    // Maximum possible size of intersection is min(M, N)
    int max_intersection = (m < n) ? m : n;
    int intersection[max_intersection];
    int k = 0; // Counter for intersection array size

    // Find intersection elements
    for (int i = 0; i < m; i++) {
        // Check if arr1[i] exists in arr2
        int found_in_arr2 = 0;
        for (int j = 0; j < n; j++) {
            if (arr1[i] == arr2[j]) {
                found_in_arr2 = 1;
                break;
            }
        }

        if (found_in_arr2) {
            // Check if arr1[i] is already added to intersection array to avoid duplicates
            int already_added = 0;
            for (int j = 0; j < k; j++) {
                if (intersection[j] == arr1[i]) {
                    already_added = 1;
                    break;
                }
            }

            if (!already_added) {
                intersection[k++] = arr1[i];
            }
        }
    }

    // Print Input Arrays
    printf("\nFirst array (Size %d): ", m);
    for (int i = 0; i < m; i++) printf("%d ", arr1[i]);
    printf("\n");

    printf("Second array (Size %d): ", n);
    for (int i = 0; i < n; i++) printf("%d ", arr2[i]);
    printf("\n");

    // Print Resultant Intersection Array
    printf("Intersection array: ");
    if (k == 0) {
        printf("No common elements found.");
    } else {
        for (int i = 0; i < k; i++) {
            printf("%d ", intersection[i]);
        }
    }
    printf("\n");

    return 0;
}