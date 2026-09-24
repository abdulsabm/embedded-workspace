/*
gcc .\12_total_and_percentage_of_three_subject.c -o .\12_total_and_percentage_of_three_subject
.\12_total_and_percentage_of_three_subject.exe                          
Enter the marks in mathmatics: 23
Enter the marks in physics: 23
Enter the marks in chemistry: 23
Total marks: 69
Percentage: 23
*/

#include<stdio.h>

int main(){

    int mathmatics, physics, chemistry, total, percentage;

    printf("Enter the marks in mathmatics: ");
    scanf("%d", &mathmatics);
    printf("Enter the marks in physics: ");
    scanf("%d", &physics);
    printf("Enter the marks in chemistry: ");
    scanf("%d", &chemistry);

    total = mathmatics + physics + chemistry;
    percentage = (total) / 3;

    printf("Total marks: %d\n", total);
    printf("Percentage: %d\n", percentage);

    return 0;
}