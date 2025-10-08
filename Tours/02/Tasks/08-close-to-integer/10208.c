#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int n;
    scanf("%d", &n);
    int min, n_min = 1, max, n_max = 1;
    scanf("%d", &min);
    max = min;

    for (int i = 2; i <= n; i++) {
        int a;
        scanf("%d", &a);

        if (a > max) {
            max = a;
            n_max = i;
        }
        if (a < min) {
            min = a;
            n_min = i;
        }
    }

    printf("%d %d %d %d", min, n_min, max, n_max);
    return 0;
}