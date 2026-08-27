#include<stdio.h>
#include<string.h>

int main(){
    int a, b;
    a = 60;
    b = 13;

    printf("OR: %d\n", (a|b));
    printf("AND: %d\n", (a&b));
    printf("XOR: %d\n", (a^b));
    return 0;
}
