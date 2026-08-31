/*
gcc .\09_interchange_the_value_of_variable_without_third_variable.c -o .\09_interchange_the_value_of_variable_without_third_variable  
.\09_interchange_the_value_of_variable_without_third_variable.exe
Enter the first variable: 23
Enter the second variable: 43
interchanged value of two variables are: var1 = 43 and var2 = 23
*/

#include<stdio.h>

int main(){

    int var1, var2;
    printf("Enter the first variable: ");
    scanf("%d", &var1);

    printf("Enter the second variable: ");
    scanf("%d", &var2);

    var1 += var2;
    var2 = var1-var2;
    var1 = var1-var2;

    printf("interchanged value of two variables are: var1 = %d and var2 = %d\n", var1, var2);

    return 0;
}