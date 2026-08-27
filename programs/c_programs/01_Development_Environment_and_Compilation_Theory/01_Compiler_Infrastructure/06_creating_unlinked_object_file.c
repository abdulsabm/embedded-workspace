/*
gcc .\06_creating_unlinked_object_file.c -c .\06_creating_unlinked_object_file.obj
gcc.exe: warning: .\06_creating_unlinked_object_file.obj: linker input file unused because linking not done
gcc.exe: error: .\06_creating_unlinked_object_file.obj: linker input file not found: No such file or directory
*/

#include<stdio.h>

void main(){

    printf("Hello world!!\n");
}