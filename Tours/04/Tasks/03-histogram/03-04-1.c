#include <stdio.h>

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int N;
    scanf("%d", &N);

    int dublecates[10001] = {0};

    for (int i = 1; i <= N; i++) {
        int a;
        scanf("%d", &a);

        dublecates[a]++;
    }

    for (int i = 1; i <= 10000; i++) {
        if (dublecates[i] != 0) {
            printf("%d: %d\n", i, dublecates[i]);
        }
    }

    return 0;
}
