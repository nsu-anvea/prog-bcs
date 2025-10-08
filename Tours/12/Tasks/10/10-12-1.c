//_____________// Task #10 //_____________//
#include <stdio.h>
#include <stdlib.h>

int binsearch(int a[], int l, int r, int x) {
    int res = -1;
    int middle;
    while (l <= r) {
        middle = l + (r - l) / 2;
        if (a[middle] == x) {
            res = middle;
            l = middle + 1;
        }
        else if (a[middle] < x) {
            l = middle + 1;
        }
        else {
            r = middle - 1;
        }
    }
    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int N;
    scanf("%d", &N);

    int * mas = (int *)malloc( sizeof(int) * N );

    for (int i = 0; i < N; i++) {
        scanf("%d", &mas[i]);
    }

    int Q;
    scanf("%d", &Q);

    int X, Y, R = 0;
    for (int j = 0; j < Q; j++) {
        scanf("%d", &X);

        Y = X + R;
        R = binsearch(mas, 0, N - 1, Y);

        printf("%d\n", R);
    }
    return 0;
}
