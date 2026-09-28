#include<stdio.h>

int main(){
    int n,number, index = 0;
    printf("Enter the number of elements for both array (N): ");
    scanf("%d", &n);

    int arr1[n];
    printf("Enter the array 1 elements:\n");
    for(int i = 0; i < n; i++){
        printf("Enter the %d element: ", i+1);
        scanf("%d", &arr1[i]);
    }

    printf("Enter the index and elemet number to add in the array (index): ");
    scanf("%d %d", &index, &number);
    for(int i = n; i >= index; i--){
        arr1[i] = arr1[i-1];
        if(i == index) (arr1[i-1] = number);
    }

    printf("Array after adding new elenemt at %d index is: ", index);
    for(int i = 0; i <= (n); i++) printf("%d ", arr1[i]);
    return 0;
}