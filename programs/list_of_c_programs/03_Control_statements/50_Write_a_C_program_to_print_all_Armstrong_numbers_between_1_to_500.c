#include<stdio.h>

bool IsAmstrong(int num){
    int temp, sum_of_all_num = 0, number_of_digits = 0, number_of_digits_1 = 0, reminder, temp_num = 1;
    temp = num;
    while(temp>0){
        number_of_digits++;
        temp /= 10;
    }

    temp = num;
    number_of_digits_1 =number_of_digits;
    while(temp>0){
        reminder = temp % 10;
        while((number_of_digits_1--) > 0){
            temp_num *= reminder;
        }
        temp /= 10;
        sum_of_all_num += temp_num;
        temp_num = 1;
        number_of_digits_1 = number_of_digits;
    }
    if (num == sum_of_all_num) return true;
    else return false;
}

int main(){
    int num, num1, number; 
    
    printf("Enter the two numbers to print the amstrong numers inbetween them: ");
    scanf("%d %d", &num, &num1);

    number = num;

    while(number <= num1 ){
        if(IsAmstrong(number)) printf("%d, ", number);
        number += 1;
    }

    return 0;
}