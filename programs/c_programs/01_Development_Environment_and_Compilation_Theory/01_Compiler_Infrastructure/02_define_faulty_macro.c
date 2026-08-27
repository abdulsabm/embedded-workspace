// gcc .\02_define_faulty_macro.c -E >>02_define_faulty_macro.i
// gcc .\02_define_faulty_macro.c -o 02_define_faulty_macro
// .\02_define_faulty_macro.exe

#include<stdio.h>

#define MULTIPLY(a, b) (a*b)

int main(){

    int a, b;
    a = 2+3;
    b = 3+5;
    printf("value of the a and b is: %d\n", MULTIPLY(a, b));
    printf("value of the a and b is: %d\n", MULTIPLY(2+3, 3+5));
    printf("value of the a and b is: %d\n", MULTIPLY(5, 8));
    return 0;
}