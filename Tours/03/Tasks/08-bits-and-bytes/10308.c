#include <stdio.h>
#include <math.h>

int main() {
    freopen("input.txt", "r", stdin);

    float n;
    scanf("%f", &n);

    char skip;
    scanf("%c", &skip);

    int prom_res = ceil(n / 8);
    for (int i = 1; i <= prom_res; i++) {

        int d;
        if (i == prom_res) {
            d = n - 8 * (prom_res - 1);
        }
        else {
            d = 8;
        }

        int res = 0;
        for (int j = 0; j <= d - 1; j++) {
            char a;
            scanf("%c", &a);

            res += (a - 48) * pow(2, j);
        }

        printf("%d ", res);
    }

    return 0;
}