#include <stdio.h>

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    unsigned long int N = 0;
    scanf("%d", &N);

    long int d = 0, d_max = 0;
    while (N != 0) {
        if (N & 1) {
            d++;
            if (d > d_max) {
                d_max = d;
            }
        }
        else {
            d = 0;
        }

        N = N >> 1;
    }
    printf("%ld", d_max);

    return 0;
}
