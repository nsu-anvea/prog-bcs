#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int h, m, s, k;
    int sum_s;
    scanf("%d %d %d %d", &h, &m, &s, &k);

    sum_s = h * 60 * 60 + m * 60 + s + k;

    int H = sum_s / 3600, ost;
    ost = sum_s % 3600;

    int M, S;
    M = ost / 60;
    S = ost % 60;

    printf("%d %d %d\n", H % 24, M, S);
}