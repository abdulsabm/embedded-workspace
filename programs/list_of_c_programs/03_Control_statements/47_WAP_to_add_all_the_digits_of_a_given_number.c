#include<stdio.h>

int main(){
    int number= 0, sum = 0;

    printf("Enter the number to add all numbers of it (n): ");
    scanf("%d", &number);

    while(number > 0){
        sum += number % 10;
        number /= 10;
    }

    printf("Sum of all numbers in a given number is: %d\n", sum);

    return 0;
}