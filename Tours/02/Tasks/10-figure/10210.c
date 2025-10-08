#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    float x, eps;
    scanf("%f", &x);
    scanf("%f", &eps);

    double y = x, prom_res = x, znam = 1;
    // -1 < x < 1 до 2 знаков после .
    // 0 < eps < 1 до 5 знаков после .
    if (x < eps) {
        printf("%0.5f", x);
        return 0;
    }

    int i = 1;
    double normalizator = -1;
    while (1) {;

        znam += 2;
        prom_res = normalizator * prom_res * (znam - 2) * x * x / znam;
        y += prom_res;
        // printf("%lf %lf\n", prom_res, y);

        if (((1 - 2 * (i % 2)) * prom_res) < eps) {
            printf("%0.5lf", y);
            return 0;
        }
        i++;
    }
    return 0;
}