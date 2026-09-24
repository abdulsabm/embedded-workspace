/*
gcc .\10_kilometer_to_meter.c -o .\10_kilometer_to_meter
.\10_kilometer_to_meter.exe
Enter the distance in kilometer: 1
The distance in meter is: 1000.00
*/

#include <stdio.h>
#include <string.h>

#define KM_TO_METER(kilometer) ((kilometer) * 1000)

int main(){

    float km;

    printf("Enter the distance in kilometer: ");
    scanf("%f", &km);

    printf("The distance in meter is: %.2f\n", KM_TO_METER(km));

    return 0;
}