//_____________// Task #4 //_____________//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int N, K, M, L;

char table[15][15][115];
int Answer[15];
int lamps_voltage[115];

void shuffle() {
    char temp;
    for (int pult = 0; pult < N; pult++) {
        for (int i = 0; i < K; i++) {
            int j = rand() % K;
            for (int k = 0; k < M; k++) {
                temp = table[pult][i][k];
                table[pult][i][k] = table[pult][j][k];
                table[pult][j][k] = temp;
            }
            temp = table[pult][i][114];
            table[pult][i][114] = table[pult][j][114];
            table[pult][j][114] = temp;
        }
    }
}

int f(int pult, int problem) {
    if (problem) {
        return 0;
    }
    else {
        if (pult == N) {
            // Проверка напряжения
            for (int i = 0; i < M; i++) {
                if (lamps_voltage[i] != L) {
                    return 0;
                }
            }
            return 1;
        }

        // Делаем полный перебор всей переключаетелей
        for (int i = 0; i < K; i++) {
            for (int j = 0; j < M; j++) {
                if (table[pult][i][j] == 'X') {
                    lamps_voltage[j]++;
                    if (lamps_voltage[j] > L) {
                        problem = 1;
                    }
                }
            }
            
            // Выбираем следующий подходящий переключатель
            Answer[pult] = (int)(table[pult][i][114] - '0' + 1);
            if (f(pult + 1, problem)) {
                return 1;
            }
            problem = 0;

            // Если, после выбора конкретных переключателей из каждого пульта
            // вольтаж не выполняется, то сбрасываем напряжение,
            // задаваемое этим переключателем
            for (int j = 0; j < M; j++) {
                if (table[pult][i][j] == 'X') lamps_voltage[j]--;
            }
        }
        return 0;
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d %d %d %d", &N, &K, &M, &L);

    srand(5);

    for (int i = 0; i < 115; i++) {
        lamps_voltage[i] = 0;
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < K; j++) {
            scanf("%s", table[i][j]);
            table[i][j][114] = (char)(j + '0');
        }
    }

    shuffle();

    if (f(0, 0)) {
        printf("YES\n");
        for (int i = 0; i < N; i++) {
            printf("%d\n", Answer[i]);
        }
    } else {
        printf("NO\n");
    }
    return 0;
}
