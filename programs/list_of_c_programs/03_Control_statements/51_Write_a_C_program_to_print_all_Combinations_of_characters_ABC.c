#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    char alpha[] = {'A','B','C'};
    for(int i = 0; i < (sizeof(alpha)/sizeof(alpha[0])); i++){
        printf("%c\n",alpha[i]);
        for(int j = 0; j < (sizeof(alpha)/sizeof(alpha[0])); j++){
            if(alpha[i] != alpha[j]) printf("%c%c\n",alpha[i], alpha[j]);
        }
    }
    return 0;
}