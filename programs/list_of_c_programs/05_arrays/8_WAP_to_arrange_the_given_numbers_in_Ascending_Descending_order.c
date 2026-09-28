#include<stdio.h>

int main(){
    int n, temp;
    printf("Enter the number of elements of array (N): ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the array elements:\n");
    for(int i = 0; i < n; i++){
        printf("Enter the %d element: ", i+1);
        scanf("%d", &arr[i]);
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < (n - i - 1); j++){
            if(arr[j] > arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    printf("Ascending order array: ");
    for(int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\nDescending order array: ");
    for(int j = (n-1); j >= 0; j--) printf("%d ", arr[j]);
    return 0;
}