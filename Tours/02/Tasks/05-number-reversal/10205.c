#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int prime(int a) {
    int d = 2;
    while (d * d <= a) {
        if (a % d == 0) {
            return 0;
        }
        d++;
    }
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    scanf("%d", &n);

    for (int i = 2; i <= n; i++) {
        if (prime(i)) {
            printf("%d ", i);
        }
    }

    return 0;
}