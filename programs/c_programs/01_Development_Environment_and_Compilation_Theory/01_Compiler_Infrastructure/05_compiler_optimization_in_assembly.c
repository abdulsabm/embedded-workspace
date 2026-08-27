// gcc .\05_compiler_optimization_in_assembly.c -o 05_compiler_optimization_in_assembly
// .\05_compiler_optimization_in_assembly.exe

// gcc .\05_compiler_optimization_in_assembly.c  -O0 -S 05_compiler_optimization_in_assembly
    // gcc.exe: warning: 05_compiler_optimization_in_assembly: linker input file unused because linking not done
    // gcc.exe: error: 05_compiler_optimization_in_assembly: linker input file not found: No such file or directory

/*
gcc .\05_compiler_optimization_in_assembly.c  -O3 -S 05_compiler_optimization_in_assembly
gcc.exe: warning: 05_compiler_optimization_in_assembly: linker input file unused because linking not done
gcc.exe: error: 05_compiler_optimization_in_assembly: linker input file not found: No such file or directory
*/

/* 
gcc .\05_compiler_optimization_in_assembly.c  -O5 -S 05_compiler_optimization_in_assembly
gcc.exe: warning: 05_compiler_optimization_in_assembly: linker input file unused because linking not done
gcc.exe: error: 05_compiler_optimization_in_assembly: linker input file not found: No such file or directory  
*/
#include<stdio.h>

void main(){
    int sum  = 0;
    for(int i = 1; i <= 100 ; i++){
        sum += i; 
    }
    printf("Sum of all number between 1 to 100 is: %d", sum);
}