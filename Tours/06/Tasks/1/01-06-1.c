#include <stdio.h>

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int N;
    scanf("%d", &N);

    double Pascals_table[1001][1001] = {1};

    int start;
    for (int i = 1; i < 1001; i++) {
        start = 0;
        for (int j = 0; j < i + 1; j++) {
            if (j == 0 || j == i) {
                Pascals_table[i][j] = 1;
            }
            else {
                Pascals_table[i][j] = Pascals_table[i - 1][start] + Pascals_table[i - 1][start + 1];
                start++;
            }
        }
    }
    
    int n, k;
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &n, &k);

        printf("%0.10g\n", Pascals_table[n][k]);
    }

    return 0;
}
