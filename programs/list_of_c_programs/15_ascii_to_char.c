/*
gcc .\15_ascii_to_char.c -o .\15_ascii_to_char
.\15_ascii_to_char.exe
Enter the ASCII value: 97
The character corresponding to the ASCII value is: a
*/

#include <stdio.h>

int main(){
    int ASCII_value;
    printf("Enter the ASCII value: ");
    scanf("%d", &ASCII_value);

    printf("The character corresponding to the ASCII value is: %c\n", ASCII_value);
    return 0;
}