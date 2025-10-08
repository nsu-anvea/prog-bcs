#include <stdio.h>
#include <stdlib.h>
#include <math.h>
// #define N 100

int main() {
    int n;
    scanf("%d", &n);

    int mas[100] = {0};

    for (int i = 0; i < n; i++) {
        int a;
        scanf("%d", &a);

        mas[i] = a;
    }

    for (int i = 0; i < n; i++) {
        int k = 0;
        for (int j = i + 1; j < n; j++) {
            if (mas[j] < mas[i]) {
                k++;
            }
        }
        printf("%d ", k);
    }

    return 0;
}
