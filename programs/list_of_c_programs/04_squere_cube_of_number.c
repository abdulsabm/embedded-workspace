// gcc .\04_squere_cube_of_number.c -o .\04_squere_cube_of_number
// .\04_squere_cube_of_number.exe

#include<stdio.h>

#define SQRT(a) (a*a)
#define CUBE(a) (a*a*a)

void main(){

    int num;

    printf("Enter the number to print thr sueroot an dcube of it: ");
    scanf("%d", &num);

    printf("Squeroot and cube of number %d is: %d and %d\n", num, SQRT(num), CUBE(num));
}