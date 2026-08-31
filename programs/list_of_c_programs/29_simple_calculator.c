#include<stdio.h>

int main(){
    char operator;
    float num1, num2, final_value;

    printf("Enter the two number and operator (num1 num2 operator): ");
    scanf("%f %f %c", &num1, &num2, &operator);

    switch (operator){
        case '+': final_value = num1 + num2; break;
        case '-': final_value = num1 - num2; break;
        case '*': final_value = num1 * num2; break;
        case '/': final_value = num1 / num2; break;
        default : printf("You have entered the wrong input, please check."); break;
    }
    printf("Final value after operation is %f\n", final_value);
    return 0;
}