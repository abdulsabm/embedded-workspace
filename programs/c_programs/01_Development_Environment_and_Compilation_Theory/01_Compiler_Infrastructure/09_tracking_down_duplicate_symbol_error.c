/*
gcc .\09_tracking_down_duplicate_symbol_error.c .\dummy.c -o .\09_tracking_down_duplicate_symbol_error    
C:/msys64/ucrt64/bin/../lib/gcc/x86_64-w64-mingw32/16.1.0/../../../../x86_64-w64-mingw32/bin/ld.exe: C:\Users\HP\AppData\Local\Temp\ccRVrcaf.o:dummy.c:(.bss+0x0): multiple definition of `global_counter'; C:\Users\HP\AppData\Local\Temp\ccCBOkcs.o:09_tracking_down_duplicate_symbol_error.c:(.bss+0x0): first defined here
collect2.exe: error: ld returned 1 exit status
*/

#include<stdio.h>
#include "global.h"

void main(){

    printf("Hello world 0!!\n");
}