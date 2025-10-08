//_____________// Task #4 //_____________//
#include <stdio.h>
#include <stdlib.h>

void swap(int * a, int * b) {
    int t = * a;
    * a = * b;
    * b = t;
}

void shake_sort(int a[], int n) {
    int left = 0, right = n - 1;
    int flag = 1;
    while (flag) {
        flag = 0;
        int i = left;
        while (i < right) {
            if (a[i] > a[i + 1]) {
                swap(&a[i], &a[i + 1]);
                flag = 1;
            }
            i++;
        }
        right--;

        if (flag) {
            flag = 0;
            int j = right;
            while (j > left) {
                if (a[j - 1] > a[j]) {
                    swap(&a[j - 1], &a[j]);
                    flag = 1;
                }
                j--;
            }
            left++;
        }
    }
}

void puzirok_sort(int a[], int n) {
    for (int j = 0; j < n; j++) {
        for (int i = n - 1; i > j; i--) {
            if (a[i - 1] > a[i]) {
                swap(&a[i - 1], &a[i]);
            }
        }
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

    shake_sort(mas, N);

    for (int i = 0; i < N; i++) {
        printf("%d ", mas[i]);
    }

    return 0;
}
