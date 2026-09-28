#include<stdio.h>

int main(){
    int n;
    printf("Enter the number of elements for both array (N): ");
    scanf("%d", &n);

    int arr1[n], arr2[n], arr_sum[n];
    printf("Enter the array 1 elements:\n");
    for(int i = 0; i < n; i++){
        printf("Enter the %d element: ", i+1);
        scanf("%d", &arr1[i]);
    }
    printf("Enter the array 2 elements:\n");
    for(int i = 0; i < n; i++){
        printf("Enter the %d element: ", i+1);
        scanf("%d", &arr2[i]);
    }

    for(int i = 0; i < n; i++) arr_sum[i] = (arr1[i] + arr2[i]);

    printf("Sum of two array are: ");
    for(int i = 0; i < n; i++){
        printf("%d ", arr_sum[i]);
    }
    return 0;
}