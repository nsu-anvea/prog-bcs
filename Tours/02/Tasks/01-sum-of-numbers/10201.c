#define _CTR_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int summa = 0, n;
    scanf("%d", &n);

    for (int i = n; i >= 1; i--) {
        summa += i;
    }
    printf("%d", summa);
    return 0;
}