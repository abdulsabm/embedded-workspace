/*
gcc .\08_interchange_the_value_of_variable.c -o .\08_interchange_the_value_of_variable      
.\08_interchange_the_value_of_variable.exe
Enter the var1: 12
Enter the var2: 32
interchanged value of two variables are: var1 = 32 and var2 = 12
*/

#include <stdio.h>

int main(){

    int var1, var2, temp;
    printf("Enter the var1: ");
    scanf("%d", &var1);

    printf("Enter the var2: ");
    scanf("%d", &var2);
    temp = var1;
    var1 = var2;
    var2 = temp;
    printf("interchanged value of two variables are: var1 = %d and var2 = %d\n", var1, var2);

    return  0;
}
