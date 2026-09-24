#include<stdio.h>

#define EVEN_ODD(number) (number%2 == 0? true:false)

int main(){
    int number;
    bool even_odd;

    printf("Enter the number to check whether the number is even or odd?:");
    scanf("%d", &number);

     EVEN_ODD(number) ? printf("The number is even\n") : printf("The number is odd\n");

    return 0;
}