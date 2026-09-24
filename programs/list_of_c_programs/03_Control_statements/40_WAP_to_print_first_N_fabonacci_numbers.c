#include<stdio.h>

int main(){
    int num= 0, previous_num = 1, previous_to_previous_num = 0, current = 0;

    printf("Enter the number to print first n fibonacci numbers: ");
    scanf("%d", &num);

    printf("First N fibonacci numbers: ");
    for(int i = 0; i<=num; i++){
        printf("%d ", current);
        previous_to_previous_num = previous_num;
        previous_num = current;
        current = previous_to_previous_num + previous_num;
    }
    return 0;
}