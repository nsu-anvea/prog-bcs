#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main() {
    freopen("input.txt", "r", stdin);

    int N;
    scanf("%d", &N);

    int mas[5000] = {0};
    for (int i = 0; i < N; i++) {
        int a;
        scanf("%d", &a);

        mas[i] = a;
    }

    int max_s = -50000000, min_L = N - 1, min_R = 0;

    for (int L = min_R; L < N; L++) {
        int summa = 0;
        for (int R = L; R < N; R++) {
            summa += mas[R];
            if (summa > max_s) {
                max_s = summa;
                min_L = L;
                min_R = R;
            }
            else {
                if (summa == max_s && ((L == min_L && R < min_R) || (L < min_L))) {
                    max_s = summa;
                    min_L = L;
                    min_R = R;
                }
            }
        }
    }
    printf("%d %d %d", min_L, min_R, max_s);
    
    return 0;
}
