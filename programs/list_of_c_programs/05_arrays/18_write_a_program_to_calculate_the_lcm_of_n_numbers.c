#include <stdio.h>

int gcd(int a, int b){
    while(b != 0){
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int lcm(int a, int b){
    printf("%d and %d\n", a, b);
    return ((a/(gcd(a, b)))*b);
}

int main() {
    int arr[100];
    int size = 0, num, N;

    // Read sequence of positive integers (stop when non-positive number is entered)
    printf("Enter positive integers (enter 0 or negative number to stop):\n");
    while (1) {
        scanf("%d", &num);
        if (num <= 0) break;
        arr[size] = num;
        size++;
    }

    if (size == 0) {
        printf("Array is empty!\n");
        return 0;
    }

    // Output resultant array
    printf("Resultant array:\n");
    int temp = arr[0];
    for (int i = 1; i < (size); i++) {
        temp = lcm(temp, arr[i]);
    }
    printf("%d", temp);

    return 0;
}