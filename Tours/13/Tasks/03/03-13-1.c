//_____________// Task #3 //_____________//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ShellSort(int b, int h, int * A, int N) {
    int i = b + h;
    while (i < N) {
        int x = A[i];
        int j = i - h;
        while (j >= b && A[j] > x) {
            A[j + h] = A[j];
            j -= h;
        }
        A[j + h] = x;
        i += h;
    }
}

int main() {
    freopen("input.txt", "r", stdin);

    int N;
    scanf("%d", &N);

    int * mas;
    mas = (int *)malloc( sizeof(int) * N);

    // Считываю все элементы
    for (int i = 0; i < N; i++) {
        scanf("%d", &mas[i]);
    }

    // Нахожу максимальный шаг
    int step = 1; // step * 3 + 1
    while (step < N / 6) {
        step = 3 * step + 1;
    }
    // Запускаю сортировку
    while (step >= 1) {
        for (int i = 0; i < step; i++) {
            ShellSort(i, step, mas, N);
        }
        step = (step - 1) / 3;
    }

    int * Answer;
    Answer = (int *)malloc( sizeof(int) * N);
    Answer[0] = mas[0];

    int k = 1;
    for (int i = 1; i < N; i++) {
        if (mas[i - 1] != mas[i]) {
            Answer[k] = mas[i];
            k++;
        }
    }

    printf("%d\n", k);
    for (int i = 0; i < k; i++) {
        printf("%d\n", Answer[i]);
    }

    return 0;
}
