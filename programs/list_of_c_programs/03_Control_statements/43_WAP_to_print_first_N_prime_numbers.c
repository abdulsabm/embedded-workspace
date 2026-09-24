#include<stdio.h>

int IsPrime(int number){
    if(number < 2){
        return false;
    }
    else if(number == 2 || number == 3) return number;
    else{
        for(int i = 2; (i*i) <= number; i++){
            if(number % i == 0) return false;
        }
        return true;
    }
}

int main(){
    int num = 0;

    printf("Enter the number to print first n prime numbers (num): ");
    scanf("%d", &num);

    printf("First n prime numbers are: ");
    for(int i = 0; i <= num; i++){
        if(IsPrime(i)) printf("%d ", i);
    }

    return 0;
}