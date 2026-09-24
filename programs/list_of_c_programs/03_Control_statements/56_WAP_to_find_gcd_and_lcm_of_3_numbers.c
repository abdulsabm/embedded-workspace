#include<stdio.h>

int gcd(int a, int b){
    int temp = 0;
    while(b != 0) {
        temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int lcm(int a, int b){

    if(a == 0 || b == 0) return 0;
    else return ((a/(gcd(a,b)))*b);
}

int main(){
    int num1, num2, num3;

    printf("Enter the three numbers (n1 n2 and n3): ");
    scanf("%d %d %d", &num1, &num2, &num3);

    printf("GCD of the two numers are: %d\n", gcd(gcd(num1, num2), num3));
    printf("LCM of the two numers are: %d\n", lcm(lcm(num1, num2), num3));
    return 0;
}