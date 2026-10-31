#include <stdio.h>
#define PI 3.14159
int main(){
    float radius ,area,perimeter;
    float f,fc,c,cf;

     printf("Enter the radius of the circle: ");
    scanf("%f", &radius);

    area=PI*radius*radius;
    perimeter=2*PI*radius;

    printf("Enter temperature in Fahrenheit: ");
    scanf("%f", &f);
    fc=(5.0/9.0)*(f-32.0);
printf("Enter temperature in Celius: ");
    scanf("%f", &c);
    cf=(c*9.0/5.0)+32;

   printf("%.2f Fahrenheit = %.2f Celsius\n", fc, cf);


}