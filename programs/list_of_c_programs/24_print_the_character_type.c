#include<stdio.h>
#include<ctype.h>


int main(){
    char character;

    printf("Enter the character: ");
    scanf("%c", &character);

    if(isalpha(character)){
        (isupper(character))?
            printf("It is a upper case character\n"):
            printf("It is a lower case character\n");
    }
    else if(isalnum(character)) printf("It is a digit\n");
    else printf("It is a special character\n");
    return 0;
}