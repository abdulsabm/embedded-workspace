#include<stdio.h>

int main(){
    int first_n_numbers=0;

    printf("Enter the number to print first n even and odd numbers (n): ");
    scanf("%d", &first_n_numbers);

    printf("Even numbers: ");
    for(int i = 1; i <= first_n_numbers; i++){
        printf("%d ", (i*2));
    }

    printf("\nOdd numbers: ");
    for(int i = 1; i <= first_n_numbers; i++){
        printf("%d ", ((i*2) - 1));
    }
    return 0;
}