#include<stdio.h>

int main(){
    char number[20];
    char temp;
    printf("Enter the number to calculate the sum of first and last digit of it: ");
    scanf("%s", number);

    for(int i = 0; number[i] != '\0'; i++){
        printf("ASCII value of %c is: %d\n", number[i], number[i]);
    }
    return 0;
}