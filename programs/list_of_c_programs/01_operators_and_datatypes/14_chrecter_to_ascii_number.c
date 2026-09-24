/*
gcc .\14_chrecter_to_ascii_number.c -o .\14_chrecter_to_ascii_number
.\14_chrecter_to_ascii_number.exe
Enter the character: a
The ASCII value of the given character is: 97
*/

#include <stdio.h>

int main(){
    char character;
    printf("Enter the character: ");
    scanf("%c", &character);

    printf("The ASCII value of the given character is: %d\n", character);
    return 0;
}