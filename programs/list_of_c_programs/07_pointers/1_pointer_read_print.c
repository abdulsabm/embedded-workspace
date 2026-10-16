#include<stdio.h>

int main(){
    int num;
    int *ptr = &num;

    printf("Enter the number: ");
    scanf("%d", ptr);

    printf("Memory location and value of the variable is: Address: 0x%p : %d", (void *)ptr, *ptr);

    return 0;
}