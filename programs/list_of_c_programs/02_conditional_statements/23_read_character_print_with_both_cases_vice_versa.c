#include<stdio.h>
#include<ctype.h>


int main(){
    char character;

    printf("Enter the character: ");
    scanf("%c", &character);

    (isupper(character))? printf("Lower: %c , Upper: %c", tolower(character), character) :\
        printf("Lower: %c , Upper: %c", character, toupper(character));
    return 0;
}