#include<stdio.h>

int main(){
    int number, reverse = 0;

    printf("Enter the number to reverse: ");
    scanf("%d", &number);
    while(number > 0){
        reverse = (reverse * 10) + (number%10);
        number /= 10;
    }
    printf("Reverse of the given number is: %d", reverse);
    return 0;
}