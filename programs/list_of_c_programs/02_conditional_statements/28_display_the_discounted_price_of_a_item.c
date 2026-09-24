#include<stdio.h>

#define TOTAL_PRICE_BEFORE_DISCOUNT(a, b) ((a) * (b))

int main(){
    float quantity, price, total_after_discount, total_before_discount, percentage;

    printf("Enter the price quantity of a item (qantity price): ");
    scanf("%f %f", &quantity, &price);

    total_before_discount = TOTAL_PRICE_BEFORE_DISCOUNT(quantity, price);

    (total_before_discount >= 1000) ? (percentage = 15.0): (percentage = 10.0);
    total_after_discount = total_before_discount - (total_before_discount*(percentage/100.0));
    printf("Total price after discount %f\n", total_after_discount);
    return 0;
}