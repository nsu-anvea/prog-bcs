#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    // c4 = b*((a / b)*(-1) + 1) + a;
    // float c;
    int a, b, c1, c2, c3, c4;
    scanf("%d %d", &a, &b);
    
    // c = (float)a / b;
    if (a % b == 0) {
        printf("%d %d %d %d", a / b, a / b, a / b, 0);
        return 0;
    }

    if (a > 0) {
        c1 = a / b;
        c2 = (a / b) + 1;
        c3 = a / b;
        c4 = a % b;
    }
    else {
        c1 = (a / b) - 1;
        c2 = a / b;
        c3 = a / b;
        c4 = (a % b) + b;
    }
    
    printf("%d %d %d %d\n", c1, c2, c3, c4);
}