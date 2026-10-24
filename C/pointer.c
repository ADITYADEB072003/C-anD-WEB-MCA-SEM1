#include <stdio.h>

int main(void)
{
    int firstvalue = 5, secondvalue = 15;
    int *p1, *p2;

    p1 = &firstvalue;   // p1 = address of firstvalue
    p2 = &secondvalue;  // p2 = address of secondvalue

    *p1 = 10;           // value pointed by p1 = 10
    *p2 = *p1;          // value pointed by p2 = value pointed by p1

    p1 = p2;            // p1 = p2 (value of pointer is copied)
    *p1 = 20;           // value pointed by p1 = 20

    printf("firstvalue is %d\n", firstvalue);
    printf("secondvalue is %d\n", secondvalue);

  



 int a = 10, b = 20, c = 30;
    int *p = &a;

    printf("%d\n", *p);

    p = &b;
    *p = *p + 5;
    printf("%d\n", *p);

    p = &c;
    *p = *p + *(&b);
    printf("%d\n", *p);

    printf("%d %d %d", a, b, c);
    printf("\n");
    int d=50;
    int *ptr = &d;
    printf("%ld", *(&ptr));
    return 0;
}