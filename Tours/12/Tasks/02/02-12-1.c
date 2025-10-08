//_____________// Task #2 //_____________//
#include <stdio.h>
#include <stdlib.h>

void select_sort(int a[], int n) {

    for (int i = 0; i < n; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[min]) {
                min = j;
            }
        }
        int temp = a[i];
        a[i] = a[min];
        a[min] = temp;
    }
}

int main() {
    freopen("input.txt", "r", stdin);

    int N;
    scanf("%d", &N);

    int * mas;
    mas = (int *)malloc(sizeof(int) * 100000);

    int el;
    for (int i = 0; scanf("%d", &el) != EOF; i++) {
        mas[i] = el;
    }

    select_sort(mas, N);

    for (int i = 0; i < N; i++) {
        printf("%d ", mas[i]);
    }

    return 0;
}
