#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void) {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int n;
    int m, p, k, l;

    scanf("%d", &n);
    scanf("%d %d %d %d", &m, &p, &k, &l);

    float k_k = m / ((p - 1) * l + (k - 1));

    int res1, res2;
    res1 = ceil(n / (l * k_k));
    res2 = ceil((n - (res1 - 1) * k_k * l) / k_k);

    printf("%d %d", res1, res2);
}