// gcc .\06_area_of_trianble.c -o .\06_area_of_trianble  
// .\06_area_of_trianble.exe                           
// Enter the base of the triangle: 4
// Enter the height of the triangle: 5
// The area of the triangle is: 10.00

#include<stdio.h>

#define AREA_OF_TRIANGLE(base, height) (0.5 * (base) * (height))

int main() {
    float base, height, area;

    printf("Enter the base of the triangle: ");
    scanf("%f", &base);

    printf("Enter the height of the triangle: ");
    scanf("%f", &height);

    area = AREA_OF_TRIANGLE(base, height);

    printf("The area of the triangle is: %.2f\n", area);

    return 0;
}