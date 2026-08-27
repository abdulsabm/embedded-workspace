// gcc .\03_conditional_compilation_guard_validation.c -DDEBUG -DFLAG
// gcc .\03_conditional_compilation_guard_validation.c -D DEBUG -D FLAG
// .\a.exe

#include<stdio.h>

int main(){

    #ifdef FLAG
        printf("Inside FLAG condition.\n");
    #endif
    #ifdef DEBUG
        printf("Inside DEBUG condition.\n");
    #endif
    printf("Standerd printf statement");

    return 0;
}