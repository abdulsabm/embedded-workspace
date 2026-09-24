#include<stdio.h>
#include<math.h>

int main(){
    float a, b, c, root1, root2, discriminant;

    printf("Enter the 3 numbers (a b c): ");
    scanf("%f %f %f", &a, &b, &c);
    discriminant = ((b*b) - (4*a*c));
    if(a == 0){
        printf("A value should be greated than 0.\n");
        return 0;
    }

    if(discriminant > 0){
        root1 = ((-b) - (sqrt(discriminant))) /(2*a);
        root2 = ((-b) + (sqrt(discriminant)))/(2*a);

        printf("roots are real and distinct root1 %.2f\n", root1);
        printf("roots are real and distinct root2 %.2f\n", root2);
    }
    else if( discriminant == 0){
        root1 = root2 =  (-b)/(2*a);

        printf("roots are real and distinct root1 %.2f\n", root1);
        printf("roots are real and distinct root2 %.2f\n", root2);
    }
    else{
        float real_part = (-b)/(2*a);
        float imaginary_part = sqrt(- discriminant)/(2*a);

        printf("roots are real and imaginary root1 %.2f+ %.2fi\n", real_part, imaginary_part);
        printf("roots are real and imaginary root2 %.2f+ %.2fi\n", real_part, imaginary_part);
    }
    return 0;
}