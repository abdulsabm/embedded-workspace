#include<stdio.h>

int main(){
    int n, index = 0;
    printf("Enter the number of elements for both array (N): ");
    scanf("%d", &n);

    int arr1[n];
    printf("Enter the array 1 elements:\n");
    for(int i = 0; i < n; i++){
        printf("Enter the %d element: ", i+1);
        scanf("%d", &arr1[i]);
    }

    printf("Enter the index number to delet from the array (index): ");
    scanf("%d", &index);
    for(int i = (index-1); i < n; i++) arr1[i] = arr1[i+1];

    printf("Array after deleting %d index is: ", index);
    for(int i = 0; i < (n-1); i++) printf("%d ", arr1[i]);
    return 0;
}