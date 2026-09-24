//  gcc .\05_area_of_circle.c -o .\05_area_of_circle.exe
//  .\05_area_of_circle.exe 

#include<stdio.h>

#define AREA_OF_CIRCLE(radius) (3.142 * ((radius) * (radius)))

void main(){

    int rad;
    // int pi = 3.142;

    printf("Enter the radius of the circle in meter: ");
    scanf("%d", &rad);

    printf("Area of circle in meter is: %.3f\n", AREA_OF_CIRCLE(rad));
}   

