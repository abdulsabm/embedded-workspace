#include<stdio.h>

int main(){
    int len;
    printf("enter the histogram lenght(len): ");
    scanf("%d", &len);

    for(int i = 1; i <= len; i++){
        for(int j = 0; j < i; j++) printf("%d",(i));
        printf("\n");
    }
    return 0;
}