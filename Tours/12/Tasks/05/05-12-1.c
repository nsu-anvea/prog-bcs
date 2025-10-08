//_____________// Task #5 //_____________//
#include <stdio.h>

int invtab_to_permut(int b[], int a[], int n) {
    //a[0] = n;    1 0 1    0 0 0    3
    for (int i = n; i >= 1; i--) {
        int x = b[i - 1];
        int j = n - i;
        while (j != x) {
            a[j] = a[j - 1];
            j--;
            if (j < 0) {
                return 0;
            }
        }
        a[j] = i;
    }
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);

    int N;
    scanf("%d", &N);

    int mas[1000];
    int res[1000] = {0};

    int el, i = 0;
    while (scanf("%d", &el) != EOF) {
        mas[i] = el;
        i++;
    }

    if (invtab_to_permut(mas, res, N)) {
        for (int i = 0; i < N; i++) {
            printf("%d ", res[i]);
        }
    }
    else {
        printf("NO");
    }

    return 0;
}
