//_____________// Task #8 //_____________//
#include <stdio.h>

void SWAP(int * a, int * b) {
    int c = * a;
    * a = * b;
    * b = c;
}

void reverse(int m[100000], int st, int ed) {
    int until = (ed - st) / 2;
    for (int i = st; i < st + until; i++) {
        SWAP(&m[i], &m[ed - (i - st) - 1]);
    }
}

int main() {
    freopen("input.txt", "r", stdin);

    int N, k;
    scanf("%d %d\n", &N, &k);

    int mas[100000] = {0}, a;
    for (int i = 0; i < N; i++) {
        scanf("%d", &a);

        mas[i] = a;
    }

    k = k % N;

    reverse(mas, 0, N);
    reverse(mas, 0, k);
    reverse(mas, k, N);

    // Conclusion
    for (int i = 0; i < N; i++) {
        printf("%d ", mas[i]);
    }

    return 0;
}
