#include<stdio.h>

int main(){
    double units = 0, total_bill = 0;

    printf("Enter the number of units consumed (U): ");
    scanf("%lf", &units);

    if(units < 0.0) {
        printf("Invalid units\n");
        return 1;
    }
    else if(units <= 200.0){
        total_bill = (units * (0.50));
    }
    else if(units <= 400.0) {
        total_bill = (((units - 200) *(0.65)) + 100);
    }
    else if(units <= 600.0) {
        total_bill = ((units - 400) *(0.8)) + 230;
    }
    else{
        total_bill = (units - 600) + 390;
    }
    printf("Total electricity bill is: %.3lf\n", total_bill);

    return 0;
}