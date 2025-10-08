#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    freopen("input.txt", "r", stdin);

    char a = '0', b = '0';

    int i = 0;
    while (1) {
        i++;

        char x;
        scanf("%c", &x);

        if (x == '.') {
            i--;
            break;
        }

        a = b;
        b = x;
    }
    freopen("input.txt", "r", stdin);

    if (a == 'e' && b == 'r') {
        for (int j = 1; j <= i - 1; j++) {
            char y;
            scanf("%c", &y);
            printf("%c", y);
        }
        printf("st");
    }
    else {
        if (b == 'e') {
            for (int j = 1; j <= i; j++) {
            char y;
            scanf("%c", &y);
            printf("%c", y);
        }
        printf("r");
        }
        else {
            for (int j = 1; j <= i; j++) {
            char y;
            scanf("%c", &y);
            printf("%c", y);
        }
        printf("er");
        }
    }

    return 0;
}