#include<stdio.h>

int lcm(int a, int b){

    if(a == 0 || b == 0) return 0;
    else return (a*b);
}

int gcd(int a, int b){
    int temp = 0;
    while(b != 0) {
        temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main(){
    int num1, num2;

    printf("Enter the two numbers (n1 n2): ");
    scanf("%d %d", &num1, &num2);

    printf("GCD of the two numers are: %d\n", gcd(num1, num2));
    printf("LCM of the two numers are: %d\n", lcm(num1, num2));
    return 0;
}