#include<stdio.h>

int main(){
    int num1, num2, temp;
    int *ptr1 = &num1, *ptr2 = &num2, *ptr_temp = &temp;

    printf("Enter the number 1: ");
    scanf("%d", ptr1);

    printf("Enter the number 2: ");
    scanf("%d", ptr2);

    printf("Two numbers before swap: %d and %d\n", *ptr1, *ptr2);
    ptr_temp = ptr1;
    ptr1 = ptr2;
    ptr2 = ptr_temp;
    printf("Two numbers after swap: %d and %d\n", *ptr1, *ptr2);

    return 0;
}