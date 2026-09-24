#include<stdio.h>
const char *once[] = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

const char *teens[] = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
const char *tens[] = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};

int main(){

    int number = 0, first_digit = 0, second_digit = 0, temp = 0;
    printf("Enter the 2 digit number to convert it into word: ");
    scanf("%d", &number);
    if(number < 10 || number > 100){
        printf("please enter the two digt number\n");
        return 0;
    }
    temp = number;
    first_digit = temp%10;
    temp /= 10;
    second_digit = temp%10;
    if(number >= 10 && number <= 19){
        printf("%s\n", teens[number%10]);
    }
    else{
        printf("%s %s\n",tens[second_digit], once[first_digit]);
    }
    return 0;
}