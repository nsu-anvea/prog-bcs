//_____________// Task #5 //_____________//
#include <stdio.h>
#include <stdlib.h>

// Сравнивающая функция для qsort
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    freopen("input.txt", "r", stdin);

    // Считываю информацию о 1 массиве
    int N1;
    scanf("%d", &N1);

    int * mas_first;
    mas_first = (int *)malloc( sizeof(int) * N1 );

    for (int i = 0; i < N1; i++) {
        scanf("%d", &mas_first[i]);
    }

    // Считываю информацию о 2 массиве
    int N2;
    scanf("%d", &N2);

    int * mas_second;
    mas_second = (int *)malloc( sizeof(int) * N2 );

    for (int i = 0; i < N2; i++) {
        scanf("%d", &mas_second[i]);
    }

    // Сортирую массивы
    qsort(mas_first, N1, sizeof(int), compare);
    qsort(mas_second, N2, sizeof(int), compare);

    // Массив для подходящих элементов
    int * Answer;
    Answer = (int *)malloc( sizeof(int) * N1 );

    // Поиск элементов из mas1, которых нет в mas2
    int k = 0, start = 0;
    for (int i = 0; i < N1; i++) {
        int flag = 0;
        
        int x = mas_first[i];
        while ((x >= mas_second[start]) && (start < N2)) {
            if (x == mas_second[start]) {
                flag = 1;
            }
            start++;
        }
        if (start != 0) {
            start--;
        }

        if (flag == 0) {
            if (k == 0) {
                Answer[0] = x;
                k++;
            }
            else {
                if (Answer[k - 1] != x) {
                    Answer[k] = x;
                    k++;
                }
            }
        }
    }

    printf("%d\n", k);
    for (int i = 0; i < k; i++) {
        printf("%d ", Answer[i]);
    }

    return 0;
}
