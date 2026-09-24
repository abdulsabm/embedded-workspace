#include<stdio.h>

int main(){
    int len;
    printf("enter the histogram lenght(len): ");
    scanf("%d", &len);

    if(len%2 == 0){
        printf("You have enterd the even number; making it to odd number for better histogram.\n");
    }

    for(int i = 0; i < len; i++){
        for(int k = 0; k<(len-i); k++) printf(" ");
        for(int j = 0; j <= i; j++){
            if((j == 0) || (j == i)){
                printf("%c", (65 + i));
                for(int m = 0; m<(i); m++) printf(" ");
            }
            else printf(" ");
        }
        printf("\n");
    }
    return 0;
}