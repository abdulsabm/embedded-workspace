#include<stdio.h>

#define CELSIUS_TO_FAHRENHEIT(celsius) (((celsius) * (9.0/5.0)) + 32)

int main(){
    float celsius;

    printf("Enter the temperature in Celsius: ");
    scanf("%f", &celsius);

    printf("The temperature in Fahrenheit is: %.2f\n", CELSIUS_TO_FAHRENHEIT(celsius));
    return 0;
}