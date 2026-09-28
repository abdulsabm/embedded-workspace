#include<stdio.h>
#include<math.h>

int main(){
    int sum = 0, number, i = 0, temp;
    printf("Enter the number to find the decimal equivalent of it: ");
    scanf("%d", &number);
    temp = number;
    while(temp> 0){
        int num = 2*(temp % 10);
        if( num != 0) (sum += (int)pow((num), i));
        temp /= 10;
        i += 1;
    }
    printf("sum of given number %d is %d", number, sum);
    return 0;
}