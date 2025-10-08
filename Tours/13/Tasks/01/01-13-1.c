#include <stdio.h>
#include <stdlib.h>

void swap(int * a, int * b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void Quick_Sort(int n, int * a, int l, int r) {
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
    // for (int z = 0; z < n; z++) {
    //     printf("%d ", a[z]);
    // }
    // printf("\n");
    // printf("%d %d\n", l, r);
    // printf("%d %d", i, j);
    // exit(0);
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

    int * mas;
    mas = (int *)malloc( sizeof(int) * N );

    for (int i = 0; i < N; i++) {
        scanf("%d", &mas[i]);
    }

    Quick_Sort(N, mas, 0,  N - 1);

    for (int i = 0; i < N; i++) {
        printf("%d ", mas[i]);
    }

    return 0;
}
