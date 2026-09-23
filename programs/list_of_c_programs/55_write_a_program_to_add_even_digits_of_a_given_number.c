#include<stdio.h>


int main(){
    int number = 0, reminder = 0, sum = 0;

    printf("Enter the add even digits of a given number: ");
    scanf("%d", &number);

    while(number > 0){
        reminder = number%10;
        if(reminder%2 == 0) (sum +=reminder);
        number /= 10;
    }
    printf("sum of all even digits in a given number is: %d", sum);
    return 0;
}