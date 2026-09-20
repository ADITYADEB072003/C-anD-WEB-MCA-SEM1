#include <stdio.h>
#include <math.h>
int main() {
    float a,b,c,d, root1,root2;
    printf("Enter the coefficients a, b and c: ");
    scanf("%f %f %f", &a, &b, &c);
    d = b*b - 4*a*c;
    if (d>0){
        root1=(-b+sqrt(d))/(2*a);
        root2=(-b-sqrt(d))/(2*a);
        printf("Roots are real and different.\n");
        printf("Root 1 = %.2f\n", root1);
        printf("Root 2 = %.2f\n", root2);
    }
    else if (d==0){
        root1=-b/2*a;
        printf("Roots are real and same.\n");
        printf("Root 1 = Root 2 = %.2f\n", root1);
    }
    else{
        printf("No real roots.\n");
    }


 
    }
