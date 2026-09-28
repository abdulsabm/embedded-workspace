#include<stdio.h>

int main(){
    int n, target_num = 0, count = 0;
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

    printf("\nEnter the number to check occurnce in array: ");
    scanf("%d", &target_num);

    for(int i = 0; i < n; i++){
        (target_num == arr[i])? (count += 1): count;
    }
    printf("Entered number %d is occurnced %d times in array\n",target_num, count);
    return 0;
}