#include<stdio.h>

int main(){
    int first_n_numbers=0;

    printf("Enter the number to print first n numbers (n): ");
    scanf("%d", &first_n_numbers);

    for(int i = 1; i <= first_n_numbers; i++){
        printf("%d ", i);
    }
    return 0;
}