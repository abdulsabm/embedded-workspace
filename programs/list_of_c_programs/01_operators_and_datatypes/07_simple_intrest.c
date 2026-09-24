
/*
gcc .\07_simple_intrest.c -o .\07_simple_intrest
.\07_simple_intrest.exe                         
Enter the Principle amount: 10000
Enter the Time period: 2
Enter the Rate of interest: 12
*/
#include<stdio.h>

int main(){

    float SI, P, T, R;
    printf("Enter the Principle amount: ");
    scanf("%f", &P);
    printf("Enter the Time period: ");
    scanf("%f", &T);
    printf("Enter the Rate of interest: ");
    scanf("%f", &R);
    SI = (P*T*R)/100;
    printf("The Simple Interest is: %f\n", SI);

    return 0;
}