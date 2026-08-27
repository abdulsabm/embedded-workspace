// gcc .\03_sum_of_2_integer_numbe.c -o .\03_sum_of_2_integer_number
// .\03_sum_of_2_integer_number.exe 

#include<stdio.h>

#define SUM(a, b)  (a+b)

int  main(){
    int num1, num2;

    printf("Enter the two number: ");
    scanf("%d %d", &num1, &num2);
    printf("Sum of two number %d and %d is %d\n", num1, num2, SUM(num1, num2));
    return 0;
}