//_____________// Task #2 //_____________//
#include <stdio.h>
#define R 32

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    unsigned N;
    scanf("%d", &N);

    int S = 1 << (R - 1);
    int res = 0;

    for (int i = 0; i < R; i++) {
        if (S & (N << i)) {
            res += (1 << i);
            printf("1");
        }
        else {
            printf("0");
        }
    }
    printf("\n%d\n", res);

    for (int i = 0; i < R; i++) {
        if (1 & (N >> i)) {
            printf("1");
        }
        else {
            printf("0");
        }
    }

    return 0;
}
