#include<stdio.h>

int main(){
    int number = 0;
    printf("Enter the number to find the factors of it: ");
    scanf("%d", &number);

    for(int i = 2; i <= (number-1); i++) if(number%i == 0) printf("%d, ", i);
    return 0;
}