#include <stdio.h>

double power(double x, int n){
    double res = 1;
    for (int i = 1; i <= n; i++) {
        res *= x;
    }
    return res;
}

int main(){
    double x = 2;
    int n = 3;
    printf("%.1f ^ %d = %.1f\n", x, n, power(x, n));
    return 0;
}