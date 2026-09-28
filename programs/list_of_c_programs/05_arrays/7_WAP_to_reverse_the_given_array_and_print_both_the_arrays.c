#include<stdio.h>

int main(){
    int n, temp;
    printf("Enter the number of elements of array (N): ");
    scanf("%d", &n);

    int arr[n], rev_arr[n];
    printf("Enter the array elements:\n");
    for(int i = 0; i < n; i++){
        printf("Enter the %d element: ", i+1);
        scanf("%d", &arr[i]);
    }

    for(int i = 0; i < n; i++){
        rev_arr[n - i -1] = arr[i];
    }
    printf("base arrayelemts are: ");
    for(int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
    printf("reversed arrayelemts are: ");
    for(int j = 0; j < n; j++) printf("%d ", rev_arr[j]);
    printf("\n");

    return 0;
}