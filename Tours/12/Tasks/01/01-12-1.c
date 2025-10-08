//_____________// Task #1 //_____________//
#include <stdio.h>

void permut_to_invtab (int a[], int b[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (a[j] > a[i]) {
                b[a[i] - 1]++;
            }
        }
    }
}

int main() {
    freopen("input.txt", "r", stdin);

    int N;
    scanf("%d", &N);

    int mas[1000];
    int res[1000] = {0};

    int el;
    for (int i = 0; scanf("%d", &el) != EOF; i++) {
        mas[i] = el;
    }
    permut_to_invtab(mas, res, N);
    
    for (int i = 0; i < N; i++) {
        printf("%d ", res[i]);
    }

    return 0;
}
