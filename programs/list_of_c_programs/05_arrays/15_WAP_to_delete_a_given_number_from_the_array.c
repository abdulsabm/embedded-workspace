#include<stdio.h>

int main(){
    int n,number, index = 0, found;
    printf("Enter the number of elements for both array (N): ");
    scanf("%d", &n);

    int arr1[n];
    printf("Enter the array 1 elements:\n");
    for(int i = 0; i < n; i++){
        printf("Enter the %d element: ", i+1);
        scanf("%d", &arr1[i]);
    }

    printf("Enter the number to delet from array: ");
    scanf("%d", &number);

    index = n;
    for(int i = 0; i < n; i++){
        if(arr1[i] == number){
            for(int j = i; j < (n-1); j++) arr1[j] = arr1[j+1];
            index -= 1;
            found += 1;
        }
    }
    if(found == 0){
        for(int i = 0; i != (index); i++) printf("%d ", arr1[i]);
    }
    else printf("given element is not found in array");
}