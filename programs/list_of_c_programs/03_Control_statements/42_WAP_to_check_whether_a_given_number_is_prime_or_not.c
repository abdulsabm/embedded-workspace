#include<stdio.h>

bool IsPrime(int number){
    if(number < 2){
        return false;
    }
    else if(number == 2 || number == 3) return true;
    else{
        for(int i = 2; (i*i) <= number; i++){
            if(number % i == 0) return false;
        }
        return true;
    }
}

int main(){
    int num = 0;
    
    printf("Enter the number to check is prime or not (n): ");
    scanf("%d", &num);

    IsPrime(num)? printf("Number is prime\n") : printf("Not a prime number");
    return 0;
}