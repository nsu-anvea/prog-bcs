//_____________// Task #4 //_____________//
#include <stdio.h>
#include <stdlib.h>

void swap(long long int * a, long long int * b) {
    long int t = *a;
    *a = *b;
    *b = t;
}

void Quick_Sort(int n, long long int * a, int l, int r) {
    int i = l, j = r;

    int pilot = a[(r + l) / 2];
    while (i < j) {
        while (a[i] < pilot) {
            i++;
        }
        while (a[j] > pilot) {
            j--;
        }
        if (i <= j) {
            swap(&a[i], &a[j]);
            i++;
            j--;
        }
    }

    if (l < j) {
        Quick_Sort(n, a, l, j);
    }
    if (i < r) {
        Quick_Sort(n, a, i, r);
    }
}

int main() {
    freopen("input.txt", "r", stdin);

    int N;
    scanf("%d", &N);

    long long int * mas;
    mas = (long long int *)malloc( sizeof(long long int) * N);

    for (int i = 0; i < N; i++) {
        scanf("%lld", &mas[i]);
    }

    Quick_Sort(N, mas, 0, N - 1);

    long long int S = 0;
    for (int i = 0; i < N; i++) {
        S += mas[i] * (N - i - 1);
    }
    printf("%lld", S);

    return 0;
}
