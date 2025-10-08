#include <stdio.h>
#include <stdlib.h>

int Div_K(int m[10000], int ** t, int n, int k) {
    int ost;
    for (int i = 1; i < n; i++) {
        ost = (m[i] % k + k) % k;
        for (int j = 0; j < k; j++) {
            if (t[i - 1][j] == 1) {
                t[i][((j + ost) + k) % k] = 1;
                t[i][((j - ost) + k) % k] = 1;
            }
        }
    }
    if (t[n - 1][0] == 1) {
        return 1;
    }
    return 0;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int N, K;
    scanf("%d %d", &N, &K);

    // Таблица с остатками
    int ** table;
    // Выделяю память под table
    table = (int **)malloc( sizeof(int *) * N );
    for (int i = 0; i < N; i++) {
        table[i] = (int *)malloc( sizeof(int) * K );
        for (int j = 0; j < K; j++) {
            table[i][j] = 0;
        }
    }

    // Массив элементов
    int mas[10000] = {0};

    // Заполняю mas
    for (int i = 0; i < N; i++) {
        scanf("%d", &mas[i]);
    }
    table[0][(mas[0] % K + K) % K] = 1;

    // Проверка делимости на K при различных вариантах
    if (Div_K(mas, table, N, K)) {
        printf("Divisible");
    }
    else {
        printf("Not divisible");
    }

    return 0;
}