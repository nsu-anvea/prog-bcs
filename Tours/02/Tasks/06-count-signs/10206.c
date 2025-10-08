#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int kolvo (int a) {
    int i = 0;

    while (a > 0) {
        i++;
        a /= 10;
    }

    return i - 1;
}

int rev_int(int k, int b) {
    int summa = 0;

    while (b > 0) {
        summa += (b % 10) * pow(10, k);
        b /= 10;
        k--;
    }
    return summa;
}

int main() {

    int n, kol_vo, res;
    scanf("%d", &n);

    kol_vo = kolvo(n);
    res = rev_int(kol_vo, n);

    printf("%d", res);

    return 0;
}