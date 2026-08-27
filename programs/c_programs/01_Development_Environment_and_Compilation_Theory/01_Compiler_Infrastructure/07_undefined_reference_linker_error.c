/*
gcc .\07_undefined_reference_linker_error.c -o 07_undefined_reference_linker_error    
C:/msys64/ucrt64/bin/../lib/gcc/x86_64-w64-mingw32/16.1.0/../../../../x86_64-w64-mingw32/bin/ld.exe: C:\Users\HP\AppData\Local\Temp\cccXOOVV.o:07_undefined_reference_linker_error.c:(.text+0xe): undefined reference to `computeStuff'
collect2.exe: error: ld returned 1 exit status
*/

#include<stdio.h>

void computeStuff(void);

void main(){

    computeStuff();
}