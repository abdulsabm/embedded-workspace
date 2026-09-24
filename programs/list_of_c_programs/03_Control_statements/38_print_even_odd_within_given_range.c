#include<stdio.h>

int main(){
    int range = 0, range1 = 0;

    printf("Enter the range to print even and odd numbers within the range (n n1): ");
    scanf("%d %d", &range, &range1);

    printf("Even Numbers: ");
    int first_even = ((range%2) == 0)? range: range+1;
    for(int i = first_even; i<= range1; i += 2){
        printf("%d ", i);
    }

    printf("\nOdd Numbers: ");
    int first_odd = ((range%2) != 0)? range: range+1;
    for(int i = first_odd; i<= range1; i += 2){
        printf("%d ", i);
    }
    return 0;
}