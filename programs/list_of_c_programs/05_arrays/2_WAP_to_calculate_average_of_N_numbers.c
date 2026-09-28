#include<stdio.h>

int main(){
    int n, sum = 0;
    printf("Enter the number of elements of array (N): ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the array elements:\n");
    for(int i = 0; i < n; i++){
        printf("Enter the %d element: ", i+1);
        scanf("%d", &arr[i]);
    }
    for(int i = 0; i < n; i++) sum += arr[i];
    printf("sum of all array elements is: %d\n", sum);
    return 0;
}