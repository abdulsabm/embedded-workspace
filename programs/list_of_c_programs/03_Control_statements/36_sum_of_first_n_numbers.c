#include<stdio.h>

int main(){
    int first_n_numbers=0, sum = 0;

    printf("Enter the number to print sum of first n numbers (n): ");
    scanf("%d", &first_n_numbers);

    for(int i = 1; i <= first_n_numbers; i++){
        sum  += i;
    }
    printf("sum of first n numbers: %d\n", sum);
    return 0;
}