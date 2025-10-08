//_____________// Task #6 //_____________//
#include <stdio.h>
#include <stdlib.h>

void swap(int * a, int * b) {
    int t = * a;
    * a = * b;
    * b = t;
}

void reverse(int b[], int len, int s, int ed) {
    int z = 1;
    for (int st = s; st < ed; st++) {
        swap(&b[st], &b[len - z]);
        z++;
    }
}

void next_permut ( int a[], int n) {
    int flag = 0;
    for (int i = n - 2; i >= 1; i--) {
        if (a[i] < a[i + 1]) {
            flag = 1;
            int min = i + 1;
            for (int j = i + 1; j < n; j++) {
                if (a[j] > a[i]) {
                    if (a[j] < a[min]) {
                        min = j;
                    }
                }
            }
            swap(&a[i], &a[min]);

            int q = i + 1;
            int p = q + (int)( (n - (i + 1)) / 2 );
            reverse(a, n, q, p);

            break;
        }
    }
    if (flag == 0) {
        reverse(a, n, 0, (int)( n / 2 ));
    }
}

int main() {
    freopen("input.txt", "r", stdin);

    int N;
    scanf("%d", &N);

    int mas[1000];

    int el, i = 0;
    while (scanf("%d", &el) != EOF) {
        mas[i] = el;
        i++;
    }

    next_permut(mas, N);

    for (int i = 0; i < N; i++) {
        printf("%d ", mas[i]);
    }

    return 0;
}
