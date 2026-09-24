#include<stdio.h>

int main(){
    int year;

    printf("Enter the year: ");
    scanf("%d", &year);

    if(year % 4){
        if((year%100) || (year % 400)) printf("Not a leap year\n");
        else printf("It is a leap yaer\n");
    }
    else printf("It is a leap yaer\n");
    return 0;
}