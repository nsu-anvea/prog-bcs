#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    freopen("input.txt", "r", stdin);

    int i = 0;
    while (1) {
        i++;

        char a;
        scanf("%c", &a);

        if (i == 2) {
            if (a != 'A') {
                printf("DOES NOT FIT");
                return 0;
            }
        }
        if (a == '.') {
            break;
        }
    }
    if (i != 4) {
        printf("DOES NOT FIT");
    }
    else {
        printf("FITS");
    }

    return 0;
}