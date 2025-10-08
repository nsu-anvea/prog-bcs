#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);

    int mas[100001] = {0};

    for (int i = 1; i <= N; i++) {
        int a;
        scanf("%d", &a);

        int d = 1;
        while (d * d < i) {
            if (i % d == 0) {
                mas[d] += a;
                mas[i / d] += a;
            }
            d++;
        }
        if (d * d == i) {
            mas[d] += a;
        }
    }

    for (int i = 1; i <= N; i++) {
        printf("%d\n", mas[i]);
    }

    return 0;
}
