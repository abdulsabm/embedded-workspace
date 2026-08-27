// gcc .\01_define_correct_macro.c -E >>01_define_correct_macro.i 
// gcc .\01_define_correct_macro.c  -o 01_define_correct_macro
//  .\01_define_correct_macro.exe 

#include<stdio.h>

#define PI(x) (x*x)

int main(){
    int x = 4;
    printf("squre of number %d is: %d", x, PI(x));
    return 0;
}