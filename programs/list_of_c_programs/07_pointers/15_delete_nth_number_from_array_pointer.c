#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int main() {
    int n, position;
    volatile uint32_t *array = NULL;

    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter the position to delete from array: ");
    scanf("%d", &position);


    // Allocate memory for n integers
    array = (volatile uint32_t *)malloc(n * sizeof(uint32_t));
    if (array == NULL && n > 0 && position >= 0 && position < n) {
        printf("Memory allocation failed! or Invalid position!\n");
        return 1;
    }
    else{
        printf("Enter the %d number of digits: ", n);
        for(int i = 0; i<n; i++) scanf("%d", (array + i));

        printf("Entered the %d number of digits are: ", n);
        for(int i = 0; i<n; i++) printf("%d ", *(array + i));

        for(int i = 0; i<(n-1); i++){
            if(i >= position){
                *(array + i) = *(array + i + 1);
            }
        }
        printf("\nAfter deleting the element at position %d, the array is: ", position);
        for(int i = 0; i<(n-1); i++) printf("%d ", *(array + i));
    }

    return 0;
}