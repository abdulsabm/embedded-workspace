#include<stdio.h>

int main(){
    int n;
    printf("Enter the number of elements of array (N): ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the array elements:\n");
    for(int i = 0; i < n; i++){
        printf("Enter the %d element: ", i+1);
        scanf("%d", &arr[i]);
    }
    printf("Array elements are: ");
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}