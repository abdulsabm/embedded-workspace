// gcc .\04_generate_assembly_code.c -S 04_generate_assembly_code 
//      gcc.exe: warning: 04_generate_assembly_code: linker input file unused because linking not done
//      gcc.exe: error: 04_generate_assembly_code: linker input file not found: No such file or directory

#include<stdio.h>

void main(){

    int a, b;
    a =34;
    b = 44;
    printf("sum of a and b is: %d", a+b);
}