#include<stdio.h>

int main(){

    int num1, num2, num3;

    printf("Enter the three numbers: ");
    scanf("%d %d %d", &num1, &num2, &num3);

    (num1 > num2)? ((num1>num3)? printf("from three number %d is the highest.\n", num1)\
    :printf("from three number %d is the highest.\n", num3)) 
    :((num2>num3)? printf("from three number %d is the highest.\n", num2)\
    :printf("from three number %d is the highest.\n", num3));

    return 0;
}