//_____________// Task #3 //_____________//
#include <stdio.h>

int Step_Two(int e) {
    int k = 1;
    while (!(1 & e)) {
        k <<= 1;
        e >>= 1;
    }
    return k;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    unsigned N;
    scanf("%d", &N);

    int el, res;
    for (int i = 0; i < N; i++) {
        scanf("%d", &el);
        printf("%d\n", Step_Two(el));
    }

    return 0;
}
