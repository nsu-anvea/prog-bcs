#define _CTR_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int summa = 0, n;
    scanf("%d", &n);

    for (int i = 1; i <= n; i ++) {
        int a;
        scanf("%d", &a);
        if (a % 2 == 0) {
            summa += a;
        }
    }
    printf("%d", summa);

    return 0;
}