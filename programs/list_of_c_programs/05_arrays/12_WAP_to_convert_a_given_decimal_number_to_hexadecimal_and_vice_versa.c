#include<stdio.h>
#include<string.h>
#include<ctype.h>

void deci2hex(int decinum, char *hexnum, int *index_count){
    int i = 0;
    if(decinum == 0){
        (hexnum[i] = '0');
        i += 1;
    }
    else{
        while (decinum> 0){
            int temp = decinum%16;
            if(temp < 10){
                (hexnum[i] = temp + '0');
            }
            else{
                hexnum[i] = (temp-10) + 'A';
            }
            i += 1;
            decinum /= 16;
        }
    }
    *index_count = i;
}
void hex2deci(char *hexnum, int *decinum){
    int len = strlen(hexnum), base = 1;
    *decinum = 0;
    char temp;
    for(int i = (len-1); i>=0; i--){
        if((toupper(hexnum[i]) == 'A') || (toupper(hexnum[i]) == 'B') ||\
        (toupper(hexnum[i]) == 'C') ||(toupper(hexnum[i]) == 'D') ||\
        (toupper(hexnum[i]) == 'E') || (toupper(hexnum[i]) == 'F')){
            *decinum += (((toupper(hexnum[i]) - 'A') + 10) * base);
        }
        else if(hexnum[i] >= '0' && hexnum[i] <= '9'){
            *decinum += ((hexnum[i] - '0') * base);
        }
        else{
            if((hexnum[i] != 'x') || hexnum[i+1] != '0')
                printf("Please enter the valid hexadecimal number.\n");
        }
        base *= 16;
    }
}
int main(){
    int number = 0, index_count = 0;
    char hexnum[100] = {0};
    printf("Enter the decimal number to find  hexadecimal equivalent of it: ");
    scanf("%d", &number);
    deci2hex(number, hexnum, &index_count);
    printf("Hexadecimal number of %d is 0x", number);
    for(int i = (index_count-1); i>= 0; i--) printf("%c", hexnum[i]);
    
    printf("\nEnter the hex number to convert in decinum: ");
    scanf("%s", hexnum);
    hex2deci(hexnum, &number);
    printf("%d", number);
    return 0;
} 