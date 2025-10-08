#include <stdio.h>
#include <stdlib.h>

typedef struct LIST {
    int weight;
    int count;
} S;

int MAX(int a, int b) {
    if (a >= b) {
        return a;
    }
    return b;
}

void Find_MAX_SUM(S * mas, int ** t, int n, int w) {
    for (int i = 1; i < n + 1; i++) {
        for (int j = 1; j < w + 1; j++) {
            if (j < mas[i].weight) {
                t[i][j] = t[i - 1][j];
            }
            else {
                t[i][j] = MAX( t[i - 1][j], t[i - 1][j - mas[i].weight] + mas[i].count);
            }
        }
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int N, W;
    scanf("%d %d", &N, &W);

    // Массив с входными данными
    S * mas = (S*)malloc( sizeof(S) * (N + 1) );
    for (int i = 1; i <= N; i++) {
        scanf("%d %d", &mas[i].weight, &mas[i].count);
    }

    // Таблица для вычисления
    int ** table = (int **)malloc( sizeof(int *) * (N + 1) );
    for (int i = 0; i <= N; i++) {
        table[i] = (int *)malloc( sizeof(int) * (W + 1) );
        for (int j = 0; j <= W; j++) {
            table[i][j] = 0;
        }
    }

    Find_MAX_SUM(mas, table, N, W);

    int MAX_SUM = 0;
    int WEIGHT = 0;
    for (int i = 1; i <= W; i++) {
        if (MAX_SUM < table[N][i]) {
            MAX_SUM = table[N][i];
            WEIGHT = i;
        }
    }

    // Массив для хранения номеров вещей
    int * res = (int *)malloc( sizeof(int) * N ), size_res = 0;

    int k = 0;
    int i = N, j = WEIGHT;
    while (i != 0) {
        if (table[i - 1][j] != table[i][j]) {
            k++;
            res[size_res] = i;
            size_res++;

            j -= mas[i].weight;
            i--;
        }
        else {
            i--;
        }
    }

    // Вывод
    printf("%d %d %d\n", k, WEIGHT, MAX_SUM);

    for (int i = k - 1; i >= 0; i--) {
        printf("%d ", res[i]);
    }

    // Очистка памяти
    for (int i = 0; i <= N; i++) {
        free(table[i]);
    }
    free(table);
    free(mas);


    return 0;
}