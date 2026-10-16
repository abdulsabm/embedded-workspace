#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int main() {
    int n;
    volatile uint32_t *array = NULL;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // Allocate memory for n integers
    array = (volatile uint32_t *)malloc(n * sizeof(uint32_t));
    if (array == NULL && n > 0) {
        printf("Memory allocation failed!\n");
        return 1;
    }
    else{
        printf("Enter the %d number of digits: ", n);
        for(int i = 0; i<n; i++) scanf("%d", (array + i));

        printf("Entered the %d number of digits are: ", n);
        for(int i = 0; i<n; i++) printf("%d ", *(array + i));
        // for(int i = 0; i<n; i++) printf("%d ", array[i]);
    }

    return 0;
}