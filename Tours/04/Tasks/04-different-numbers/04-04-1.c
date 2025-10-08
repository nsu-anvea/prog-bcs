#include <stdio.h>

int main() {
    //freopen("input.txt", "r", stdin);

    int N;
    scanf("%d", &N);

    int mas[2001] = {0};

    for (int i = 1; i <= N; i++) {
        int a;
        scanf("%d", &a);

        mas[1000 + a]++;
    }

    int k = 0;
    for (int i = 0; i <= 2000; i++) {
        if (mas[i] != 0) {
            k++;
        }
    }
    printf("%d", k);

    return 0;
}
