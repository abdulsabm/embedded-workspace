#include<stdio.h>
int main(){
    int fact = 1,  fact_num=0;

    printf("Enter the number to print the factorial of it: ");
    scanf("%d", &fact_num);

    for(int i= 1; i<=fact_num;i++) fact *= i;
        
    printf("Factorial of a given number is: %d\n", fact);
    return 0;
}