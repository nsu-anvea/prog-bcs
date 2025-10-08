#include <stdio.h>

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int N;
    scanf("%d", &N);

    int s1 = 2, s2 = 3;
    if (N == 0) {
        printf("%d", 0);
    }
    else if (N == 1) {
        printf("%d", 2);
    }
    else if (N == 2) {
        printf("%d", 3);
    }
    else {
        int res;
        for (int n = 3; n <= N; n++) {
            res = s1 + s2;
            s1 = s2;
            s2 = res;
        }
        printf("%d", res);
    }

    return 0;
}