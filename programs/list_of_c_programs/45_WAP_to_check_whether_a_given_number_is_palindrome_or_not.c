#include<stdio.h>

int reverse(int num){
    int reverse = 0, rem = 0;
    
    while(num > 0){
        rem = num % 10;
        reverse = (reverse*10)+(rem);
        num /= 10;
    }
    return reverse;
}

int main(){
    int num=0;

    printf("Enter the number to check the is palindrome or not (num): ");
    scanf("%d", &num);

    (reverse(num) == num)? printf("Is palindrome\n"): printf("Not a palindrome\n");
    return 0;
}