#include<stdio.h>

int main(){
    int num = 0, count = 0;

    printf("Enter the number to count the number of binary once in it (num): ");
    scanf("%d", &num);

    while(num > 0){
        num &= (num-1);
        count++;
    }

    printf("Number of binary once in a given number: %d\n", count);
    return 0;
}