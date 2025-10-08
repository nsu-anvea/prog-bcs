//_____________// Task #3 //_____________//
#include <stdio.h>
#include <stdlib.h>

void ins_sort(int a[], int n) {

    for (int i = 1; i < n; i++) {
        int x = a[i];
        int k = i - 1;
        while (k >= 0 && x < a[k]) {
            a[k + 1] = a[k];
            k--;
        }
        a[k + 1] = x;
    }
}

int main() {
    freopen("input.txt", "r", stdin);

    int N;
    scanf("%d", &N);

    int * mas;
    mas = (int *)malloc(sizeof(int) * 100000);

    int el, i = 0;
    while (scanf("%d", &el) != EOF) {
        mas[i] = el;
        i++;
    }

    ins_sort(mas, N);

    for (int i = 0; i < N; i++) {
        printf("%d ", mas[i]);
    }

    return 0;
}
