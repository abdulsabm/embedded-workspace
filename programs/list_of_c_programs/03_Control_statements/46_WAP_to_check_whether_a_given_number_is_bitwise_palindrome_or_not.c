#include<stdio.h>
#include<stdint.h>

uint32_t IsReverse(uint32_t number){
    uint32_t reverse = 0, temp = 0;
    temp = number;

    while(temp > 0){
        reverse <<= 1;
        reverse |= (temp & 1);
        temp >>= 1;
    }
    return reverse;
}

int main(){
    uint32_t num = 0;

    printf("Enter the number to check the bitwise palindrome (num): ");
    scanf("%u", &num);

    (IsReverse(num) == num)? printf("Is palindrome\n"): printf("Not a palindrome\n");

    return 0;
} 