#include<stdio.h>

int main(){
    int num1, num2, num3;
    int *ptr1 = &num1, *ptr2 = &num2, *ptr3 = &num3;

    printf("Enter the number 1: ");
    scanf("%d", ptr1);

    printf("Enter the number 2: ");
    scanf("%d", ptr2);

    printf("Enter the number 3: ");
    scanf("%d", ptr3);

    (*ptr1 > *ptr2)? ((*ptr1 > *ptr3)?
                        printf("Frist number %d is the largest number.\n", *ptr1):
                        printf("Third number %d is the largest number.\n", *ptr3)):
                     ((*ptr2 > *ptr3)?
                        printf("Second number %d is the largest number.\n", *ptr2):
                        printf("Third number %d is the largest number.\n", *ptr3));
    return 0;
}