#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int n;
    scanf("%d", &n);

    int k_m = 0, k_0 = 0, k_p = 0;

    for (int i = 1; i <= n; i++) {
        int a;
        scanf("%d", &a);
        if (a == 0) {
            k_0++;
        }
        else {
            if (a > 0) {
                k_p++;
            }
            else {
                k_m++;
            }
        }
    }

    double r1, r2, r3;
    r1 = (double)k_m / n;
    r2 = (double)k_0 / n;
    r3 = (double)k_p / n;

    printf("%0.5lf %0.5lf %0.5lf", r1, r2, r3);
    return 0;
}