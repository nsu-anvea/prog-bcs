#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    double x1, y1;
    double x2, y2;
    double x3, y3;

    scanf("%lf %lf", &x1, &y1);
    scanf("%lf %lf", &x2, &y2);
    scanf("%lf %lf", &x3, &y3);

    int d1x = fabs(x1 - x2), d1y = fabs(y1 - y2);
    int d2x = fabs(x2 - x3), d2y = fabs(y2 - y3);
    int d3x = fabs(x3 - x1), d3y = fabs(y3 - y1);

    double a = sqrt(pow(d1x, 2) + pow(d1y, 2));
    double b = sqrt(pow(d2x, 2) + pow(d2y, 2));
    double c = sqrt(pow(d3x, 2) + pow(d3y, 2));

    double p, P, S;
    P = a + b + c;
    p = P / 2;
    S = sqrt(p * (p - a) * (p - b) * (p - c));

    printf("%0.3lf\n%0.3lf\n", P, S);
    return 0;
}