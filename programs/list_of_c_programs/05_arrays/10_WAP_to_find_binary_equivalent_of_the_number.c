#include<stdio.h>

int main(){
    int digit, arr[31] = {0}, number, i = 0;
    printf("Enter the number to find the binary equivalent of it: ");
    scanf("%d", &number);
    while(number> 0){
        arr[i] = (number % 2);
        number /= 2;
        i += 1;
    }
    printf("i : %d\n", i);
    printf("0b");
    for(int j = (i-1); j >= 0; j--){
        printf("%d", arr[j]);
    }
    return 0;
}