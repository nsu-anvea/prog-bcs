#include <stdio.h>

int main() {
    freopen("input.txt", "r", stdin);

    long long int N;
    scanf("%lld", &N);

    long long int mas[1000000 + 1] = {0};
    for (long long int i = 2; i <= N; i++) {
        mas[i] += i;
    }

    for (long long int i = 2; i <= N; i++) {
        if ((mas[i] != 0) && (mas[i] * mas[i] <= N)) {
            for (long long int j = mas[i] * mas[i]; j <= N; j += mas[i]) {
                mas[j] -= mas[j];
            }
        }
    }

    for (long long int i = 0; i <= N; i++) {
        if (mas[i] != 0) {
            printf("%lld ", mas[i]);
        }
    }

    return 0;
}
