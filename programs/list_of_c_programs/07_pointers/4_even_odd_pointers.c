#include<stdio.h>

int main(){
    int num;
    int *ptr = &num;

    printf("Enter the number: ");
    scanf("%d", ptr);

    (*ptr%2 == 0)? printf("Number is even."): printf("Number is odd.");

    return 0;
}