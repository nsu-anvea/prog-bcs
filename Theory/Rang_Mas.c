#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define N 5

void rev_ot_l_do_r(int mas[], int l, int r) {
    while (l < r) {
        int n;
        n = mas[l];
        mas[l] = mas[r];
        mas[r] = n;

        l++;
        r--;
    }
}

void obed_2_mas(int a[], int b[], int c[], int n) {
    for (int i = 1; i <= n; i++) {
        c[i] = a[i] || b[i]? 1:0;
    }
}

int main() {
    int arr[N];
    srand(3);

    arr[0] = -10000 + rand() % 10000;
    printf("%d\n\n", arr[0]);
    for (int i = 1; i < N; i++) {
        arr[i] = arr[i - 1] + rand() % 1000;
    }

    for (int i = 0; i < N; i++) {
        printf("%d\n", arr[i]);
    }

    int p = arr[N - 1];
    for (int i = N - 1; i >= 1; i--) {
        arr[i] = arr[i - 1];
    }
    arr[0] = p;
    printf("\n");
    for (int i = 0; i < N; i++) {
        printf("%d\n", arr[i]);
    }
    return 0;
}