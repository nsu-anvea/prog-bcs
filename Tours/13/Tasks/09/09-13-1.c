//_____________// Task #9 //_____________//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void SWAP(int * a, int * b) {
    int t = * a;
    * a = * b;
    * b = t;
}

void Quick_Sort(int n, int * a, int l, int r) {
    int i = l, j = r;

    srand(time(NULL));
    int pilot = a[(r + l) / 2 + (rand() % 2)];
    while (i < j) {
        while (a[i] < pilot) {
            i++;
        }
        while (a[j] > pilot) {
            j--;
        }
        if (i <= j) {
            SWAP(&a[i], &a[j]);
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
    FILE * in = fopen("input.bin", "rb");
    FILE * out = fopen("output.bin", "wb");

    int N;
    fread(&N, sizeof(int), 1, in);

    int * mas = (int *)malloc( sizeof(int) * N );

    for (int i = 0; i < N; i++) {
        fread(&mas[i], sizeof(int), 1, in);
    }
    fclose(in);

    Quick_Sort(N, mas, 0, N - 1);

    for (int i = 0; i < N; i++) {
        fwrite(&mas[i], sizeof(int), 1, out);
    }
    fclose(out);

    return 0;
}
