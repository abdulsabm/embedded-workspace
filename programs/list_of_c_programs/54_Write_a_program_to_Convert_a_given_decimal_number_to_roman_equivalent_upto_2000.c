#include <stdio.h>

void convert_to_roman(int num) {
    if (num <= 0 || num > 2000) {
        printf("Please enter a valid number between 1 and 2000.\n");
        return;
    }

    // Lookup tables for values and corresponding Roman symbols
    int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    const char *symbols[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

    printf("Roman equivalent of %d: ", num);

    for (int i = 0; i < 13; i++) {
        while (num >= values[i]) {
            printf("%s", symbols[i]);
            num -= values[i]; // Subtract the value
        }
    }
    printf("\n");
}

int main() {
    int number;
    printf("Enter a decimal number (1 to 2000): ");
    if (scanf("%d", &number) == 1) {
        convert_to_roman(number);
    }
    return 0;
}