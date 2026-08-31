#include<stdio.h>

int main(){
    int maths, science, english, percentage;
    printf("Enter the marks in three subjects(marks/100): ");
    scanf("%d %d %d", &maths, &science, &english);
    percentage = (maths + science + english) / 3;
    if(percentage >= 70) printf("Student obtained first class with distinction\n");
    else if(percentage <= 69 && percentage >= 60) printf("Student obtained first class\n");
    else if(percentage <= 59 && percentage >= 50) printf("Student obtained second class\n");
    else if(percentage <= 49 && percentage >= 35) printf("Student obtained third class\n");
    else printf("Student has failed\n");
    return 0;
}