#include <stdio.h>
#include <stdlib.h> // Required for abs()

// Function that accepts a pointer to the number (Call by Reference)
// It calculates and returns the reverse of the number.
long long reverseNumber(int *ptr) {
    long long reversed = 0;
    int temp = *ptr; // Dereference the pointer to get the value
    int isNegative = 0;

    // Handle negative numbers (though negative palindromes are rare, 
    // we handle sign properly just like before)
    if (temp < 0) {
        isNegative = 1;
        temp = -temp;
    }

    // Extract digits and build the reversed number
    while (temp > 0) {
        int digit = temp % 10;
        reversed = reversed * 10 + digit;
        temp /= 10;
    }

    return isNegative ? -reversed : reversed;
}

int main() {
    int num;

    // Prompt user for input
    printf("Enter an integer: ");
    if (scanf("%d", &num) != 1) {
        printf("Invalid input!\n");
        return 1;
    }

    // Call the function by passing the ADDRESS of 'num' using Call by Reference
    long long reversedNum = reverseNumber(&num);

    // Compare the original number with its reverse to check for palindrome
    printf("\nOriginal Number: %d\n", num);
    printf("Reversed Number: %lld\n", reversedNum);

    if (num == reversedNum) {
        printf("Result: %d is a palindrome!\n", num);
    } else {
        printf("Result: %d is NOT a palindrome.\n", num);
    }

    return 0;
}