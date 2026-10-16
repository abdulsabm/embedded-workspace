#include<stdio.h>

int main(){
    int num1, num2;
    int *ptr1 = &num1, *ptr2 = &num2;

    printf("Enter the number 1: ");
    scanf("%d", ptr1);

    printf("Enter the number 2: ");
    scanf("%d", ptr2);

    printf("\nSum of two number is: %d\n", ((*ptr1) + (*ptr2)));
    printf("sub of two number is: %d\n", ((*ptr1) - (*ptr2)));
    printf("product of two number is: %d\n", ((*ptr1) * (*ptr2)));
    printf("division of two number is: %d\n", ((*ptr1) / (*ptr2)));


    return 0;
}