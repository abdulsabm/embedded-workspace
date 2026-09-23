#include<stdio.h>

int main(){
    int len;
    printf("enter the histogram lenght(len): ");
    scanf("%d", &len);

    if(len%2 == 0){
        printf("You have enterd the even number; making it to odd number for better histogram.\n");
    }

    for(int i = 0; i < len; i++){
        for(int k = 0; k<((2*len)-(i*2)); k++) printf(" ");
        for(int j = 0; j <= i; j++){
            int ch = (65);
            if((j == 0) || (j == i)){
                ch += +i;
                printf("%c ", ch);
                if(j == 0) for(int m = 0; m<(i); m++) printf("%c ", (ch - m - 1));
            }
            else printf("%c ", (ch+j));
        }
        printf("\n");
    }
    return 0;
} 