//_____________// Task #7 //_____________//
#include <stdio.h>
#include <stdlib.h>

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


    int C, l, m, r;
    for (int i = 0; i < Q; i++) { 
        scanf("%d", &C);

        l = -1;
        r = N - 1; 
        while (l < r - 1) { 
            m = (l + r + 1) / 2;

            if (mas[m + 1] - mas[m] + C < 0) {
                l = m;
            }
            else {
                r = m;
            }
        }
        printf("%d\n", r);
    }
    return 0;
}
