#include<stdio.h>
#include<ctype.h>

int main(){
    char ch;
    char *ptr = &ch;

    printf("Enter the character: ");
    scanf("%c", ptr);
    

    if(isdigit(*ptr)) printf("The given character is a number.\n");
    else if(islower(*ptr)) printf("The given character is a lower character.\n");
    else if(isupper(*ptr)) printf("The given character is a upper character.\n");
    else printf("The given character is a special character.\n");

    return 0;
}