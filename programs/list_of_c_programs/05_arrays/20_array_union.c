#include <stdio.h>

int main() {
    int m, n;

    // Read first array size and elements
    printf("Enter the size of first array (M): ");
    if (scanf("%d", &m) != 1 || m <= 0) return 1;

    int arr1[m];
    printf("Enter elements of first array:\n");
    for (int i = 0; i < m; i++) {
        scanf("%d", &arr1[i]);
    }

    // Read second array size and elements
    printf("Enter the size of second array (N): ");
    if (scanf("%d", &n) != 1 || n <= 0) return 1;

    int arr2[n];
    printf("Enter elements of second array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr2[i]);
    }

    // Maximum possible size of union is (M + N)
    int union_arr[m + n];
    int k = 0; // Counter for union array size

    // 1. Add unique elements from arr1 to union_arr
    for (int i = 0; i < m; i++) {
        int already_added = 0;
        for (int j = 0; j < k; j++) {
            if (union_arr[j] == arr1[i]) {
                already_added = 1;
                break;
            }
        }
        if (!already_added) {
            union_arr[k++] = arr1[i];
        }
    }

    // 2. Add unique elements from arr2 to union_arr
    for (int i = 0; i < n; i++) {
        int already_added = 0;
        for (int j = 0; j < k; j++) {
            if (union_arr[j] == arr2[i]) {
                already_added = 1;
                break;
            }
        }
        if (!already_added) {
            union_arr[k++] = arr2[i];
        }
    }

    // Output Input Arrays
    printf("\nFirst array (Size %d): ", m);
    for (int i = 0; i < m; i++) printf("%d ", arr1[i]);
    printf("\n");

    printf("Second array (Size %d): ", n);
    for (int i = 0; i < n; i++) printf("%d ", arr2[i]);
    printf("\n");

    // Output Resultant Union Array
    printf("Union array (Size %d): ", k);
    for (int i = 0; i < k; i++) {
        printf("%d ", union_arr[i]);
    }
    printf("\n");

    return 0;
}