#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int kol_vo_ch(int a) {
    int b = 0;
    int k = 0;
    while (b < a) {
        k++;
        b += k * 9 * pow(10, k - 1);
    }
    return k;
}

int main() {
    int n;
    scanf("%d", &n);

    if ((1 <= n && n <= 9)) {
        printf("%d", n);
        return 0;
    }

    int kol_vo = kol_vo_ch(n);
    //printf("kol_vo %d\n", kol_vo);
    int summa = 0;
    for (int i = 1; i <= kol_vo - 1; i++) {
        summa += i * 9 * pow(10, i - 1);
    }
    //printf("summa %d\n", summa);

    int prom_res = n - summa, res, ost;
    //printf("prom_res %d\n", prom_res);
    ost = prom_res % kol_vo;
    //printf("ost %d\n", ost);
    int i = kol_vo, ii = 1;
    while (i >= 1) {
        int x;
        if (ii == 1) {
            x = prom_res / (kol_vo * pow(10, i - 1)) + 1;
            if ((ii % kol_vo) == ost) {
            printf("%d", x);
            return 0;
            }
            prom_res = prom_res % (int)(kol_vo * pow(10, i - 1));
            //printf("%d\n", prom_res);
        }
        else {
            x = ceil(prom_res / (kol_vo * pow(10, i - 1))) - 1;
            if ((ii % kol_vo) == ost) {
            printf("%d", x);
            return 0;
            }
            prom_res = prom_res % (int)(kol_vo * pow(10, i - 1));
        }

        i--;
        ii++;
    }
  
    return 0;
}