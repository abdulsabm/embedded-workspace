#include<stdio.h>

int main(){
    int number= 0;

    printf("Enter the number to check the power of it (n): ");
    scanf("%d", &number);

    (number > 0 && ((number & (number-1)) == 0))? printf("It is power of 2\n"):
    printf("Not a power of 2\n");

    return 0;
}