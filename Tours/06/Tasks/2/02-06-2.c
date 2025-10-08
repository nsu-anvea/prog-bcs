//_____________// Task #2 //_____________//
#include <stdio.h>

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int N, M;
    scanf("%d %d", &N, &M);

    int mas[10][10];

    int el;
    for (int n = 0; n < N; n++) {
        for (int m = 0; m < M; m++) {
            scanf("%d", &el);

            mas[n][m] = el;
        }
    }

    // Для строк
    int flag = 0;

    int k_switch = 0;
    int d = 0;
    for (int i = 0; i < N; i++) { // lines
        flag = 0;

        k_switch = 0;
        d = 0;
        for (int j = 0; j < M; j++) { // columns
            if (mas[i][j] == 1) {
                d++;
                flag = 1;
            }
            if ((j == M - 1 || mas[i][j] == 0) && flag == 1) {
                k_switch++;
                printf("%d ", d);

                d = 0;
                flag = 0;
            }
        }
        if (k_switch == 0) {
            printf("");
        }
        printf("\n");
    }

    // Для столбцов
    for (int j = 0; j < M; j++) { // columns
        flag = 0;

        k_switch = 0;
        d = 0;
        for (int i = 0; i < N; i++) { // lines
            if (mas[i][j] == 1) {
                d++;
                flag = 1;
            }
            if ((i == N - 1 || mas[i][j] == 0) && flag == 1) {
                k_switch++;
                printf("%d ", d);

                d = 0;
                flag = 0;
            }
        }
        if (k_switch == 0) {
            printf("");
        }
        printf("\n");
    }

    return 0;
}
