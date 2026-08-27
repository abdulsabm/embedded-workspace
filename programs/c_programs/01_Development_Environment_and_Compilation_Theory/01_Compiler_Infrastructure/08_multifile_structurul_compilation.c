/*
gcc .\08_multifile_structurul_compilation.c .\dummy.c -o 08_and_dummy__multifile_structurul_compilation
.\08_and_dummy__multifile_structurul_compilation.exe
Cube of given number is: 27
*/

/*
gcc .\08_multifile_structurul_compilation.c -c .\08_and_dummy__multifile_structurul_compilation.obj    
gcc.exe: warning: .\08_and_dummy__multifile_structurul_compilation.obj: linker input file unused because linking not done
gcc.exe: error: .\08_and_dummy__multifile_structurul_compilation.obj: linker input file not found: No such file or directory

gcc .\dummy.c -c .\dummy.obj
gcc.exe: warning: .\dummy.obj: linker input file unused because linking not done
gcc.exe: error: .\dummy.obj: linker input file not found: No such file or directory

gcc .\08_multifile_structurul_compilation.o .\dummy.o -o .\08_and_dummy__multifile_structurul_compilation  
.\08_and_dummy__multifile_structurul_compilation.exe                                                     
Cube of given number is: 27
*/

#include<stdio.h>

extern int cube(int x);

void main(){

    printf("Cube of given number is: %d\n", cube(10));
}