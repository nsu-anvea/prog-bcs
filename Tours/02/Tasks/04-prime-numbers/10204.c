#define _CTR_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int prime(int n) {
    int d = 2;
    while (d * d < n) {
        if (n % d == 0) {
            return 0;
        }
        d++;
    }
    if (d * d == n) {
        return 0;
    }
    return 1;
}


int main() {
    int a;
    scanf("%d", &a);

    char res = prime(a);
    if (res == 0 || a == 1) {
        printf("NO");
    }
    else {
        printf("YES");
    }

    return 0;
}