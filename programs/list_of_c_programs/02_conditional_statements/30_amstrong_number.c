#include<stdio.h>

int main(){
    int num, temp, sum_of_all_num = 0, number_of_digits = 0, number_of_digits_1 = 0, reminder, temp_num = 1;

    printf("Enter the number: ");
    scanf("%d", &num);

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
    (num == sum_of_all_num)? printf("Number is amstrong\n"):printf("Number is not a amstrong\n");
    return 0;
}