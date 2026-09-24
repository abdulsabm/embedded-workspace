/*
gcc .\13_price_of_item_befor_after_discount.c -o .\13_price_of_item_befor_after_discount  
.\13_price_of_item_befor_after_discount.exe
Enter the price of item: 1
Enter the quantity of item: 100
Enter the discount percentage: 10
Total price: 100.00
Price after discount: 90.00
*/

#include <stdio.h>

int main(){

    float price, quantity, discount, total_price, ptotal_price_after_discount;

    printf("Enter the price of item: ");
    scanf("%f", &price);
    printf("Enter the quantity of item: ");
    scanf("%f", &quantity);
    printf("Enter the discount percentage: ");
    scanf("%f", &discount);

    total_price = price * quantity;
    ptotal_price_after_discount = total_price - (total_price * discount / 100);
    printf("Total price: %.2f\n", total_price);
    printf("Price after discount: %.2f\n", ptotal_price_after_discount);
    return 0;
}