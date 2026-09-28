#include<stdio.h>

int main(){
    int n, even_count = 0, odd_count = 0;
    printf("Enter the number of elements of array (N): ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the array elements:\n");
    for(int i = 0; i < n; i++){
        printf("Enter the %d element: ", i+1);
        scanf("%d", &arr[i]);
    }
    for(int k = 0; k < n; k++) printf("%d ", arr[k]); 

    printf("\nEven and odd number of array.\n");
    for(int j = 0; j < n; j++){
        if(arr[j] % 2 == 0){
            printf("given array %d of index %d is even number\n",arr[j], j);
            even_count += 1;
        }
        else{
            printf("given array %d of index %d is odd number\n",arr[j], j);
            odd_count += 1;
        }
    }
    printf("There are %d even numbers in array.\n", even_count);
    printf("There are %d odd numbers in array.\n", odd_count);
    return 0;
}