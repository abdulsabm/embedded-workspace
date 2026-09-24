#include<stdio.h>

int main(){
    int number, count = 0, temp, sum = 0;
    printf("Enter the number to calculate the sum of first and last digit of it: ");
    scanf("%d", &number);
    temp = number;
    while(temp>0){
        count ++;
        temp /= 10;
    }
    printf("Number of digits are : %d\n", count);
    temp = 0;
    while(number>0){
        if(temp == 0 || temp == count-1){
            sum += number % 10;
        }
        number /= 10;
        temp ++;
    }
    printf("sum of first and last digits are : %d\n", sum);

    return 0;
}