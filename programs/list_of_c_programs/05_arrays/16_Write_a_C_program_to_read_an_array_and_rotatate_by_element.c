#include <stdio.h>

// Function to rotate array clockwise by N positions
void rotateClockwise(int arr[], int size, int N) {
    // Handle N larger than array size
    N = N % size;
    
    if (N == 0) return;
    for(int i = 0; i <(N-1); i++){
        int temp = arr[0];
        for(int j = 0; j < (size-1); j++){
                arr[j] = arr[j+1];
        }
        arr[size-1] = temp;
    }
}

int main() {
    int arr[100];
    int size = 0, num, N;

    // Read sequence of positive integers (stop when non-positive number is entered)
    printf("Enter positive integers (enter 0 or negative number to stop):\n");
    while (1) {
        scanf("%d", &num);
        if (num <= 0) break;
        arr[size] = num;
        size++;
    }

    if (size == 0) {
        printf("Array is empty!\n");
        return 0;
    }

    // Read rotation count N
    printf("Enter number of clockwise rotations (N): ");
    scanf("%d", &N);

    // Perform clockwise rotation
    rotateClockwise(arr, size, N);

    // Output resultant array
    printf("Resultant array:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}