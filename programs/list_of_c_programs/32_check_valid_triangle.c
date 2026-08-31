#include<stdio.h>

int main(){
    float a, b, c;

    printf("Enter the three sides of the triangle(a b c): ");
    scanf("%f %f %f", &a, &b, &c);

    if((a == 0) ||  (b == 0) || (c == 0)){
        printf("size should be positive number.\n");
        return 0;
    }

    ((a+b > c) && (b+c > a) && (c+a > b))? printf("It is a valid triangle.\n") : printf("It is not a triangle.\n");
    return 0;
}