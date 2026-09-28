#include<stdio.h>

void sort_array_in_ascending_order(int *arr, int size){
    int temp = 0;
    for(int i = 0; i < size; i++){
        for(int j = 0; j < (size - i - 1); j++){
            if(arr[j] > arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int Binary_search_of_key(int *arr, int size, int key){
    int low = 0, high = (size-1);
    while(low <= high){
        int mid = low + (high - low)/2;
        if(key == arr[mid]) return mid;
        if(arr[mid] < key) (low = mid + 1);
        else (high = mid - 1);
    }
    return -1;
}

int main(){
    int n, key_element, index = -1;
    printf("Enter the number of elements of array (N): ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the array elements:\n");
    for(int i = 0; i < n; i++){
        printf("Enter the %d element: ", i+1);
        scanf("%d", &arr[i]);
    }
    sort_array_in_ascending_order(arr, n);
    printf("Ascending order array: ");
    for(int i = 0; i < n; i++) printf("%d ", arr[i]);

    printf("\nEnter the key element to search in the given array: ");
    scanf("%d", &key_element);
    index = Binary_search_of_key(arr, n, key_element);
    if(index != -1) printf("The given key %d is found at index: %d\n",key_element, index);
    else printf("The given key %d is not found in array list.\n", key_element);
    return 0;
}