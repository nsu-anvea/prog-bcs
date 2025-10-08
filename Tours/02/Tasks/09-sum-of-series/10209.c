#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int n, index;
    double min_raz = 1;
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        double a;
        scanf("%lf", &a);

        if (a > 0) {
            double r1, r2;
            r1 = fabs(((int)a) + 1 - a);
            r2 = fabs(((int)a) - a);

            if (r1 < r2) {
                if (r1 < min_raz) {
                    min_raz = r1;
                    index = i;
                }
            }
            else {
                if (r2 < min_raz) {
                    min_raz = r2;
                    index = i;
                }
            }
        }
        else {
            double r1, r2;
            r1 = fabs(((int)a) + 1 - a);
            r2 = fabs(((int)a) - a);

            if (r1 < r2) {
                if (r1 < min_raz) {
                    min_raz = r1;
                    index = i;
                }
            }
            else {
                if (r2 < min_raz) {
                    min_raz = r2;
                    index = i;
                }
            }
        }
    }

    printf("%d", index);
    return 0;
}