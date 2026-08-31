#include<stdio.h>

#define FAHRENHEIT_TO_CELSIUS(fahrenheit) ((fahrenheit-32) * (5.0/9.0))

int main(){
    float fahrenheit;

    printf("Enter the temperature in Fahrenheit: ");
    scanf("%f", &fahrenheit);

    printf("The temperature in celsius is: %.2f\n", FAHRENHEIT_TO_CELSIUS(fahrenheit));
    return 0;
}