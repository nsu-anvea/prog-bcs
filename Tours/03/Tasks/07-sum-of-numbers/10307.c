#include <stdio.h>

int main() {
    freopen("input.txt", "r", stdin);

    int pred_res = 0, res = 0;

    while (1) {
        char a;
        scanf("%c", &a);

        if ('0' <= a && a <= '9') {
            res = res * 10 + (a - 48);
        }
        else {
            pred_res += res;
            res = 0;
        }
        if (a == '.') {
            break;
        }
    }
    printf("%d", pred_res);

    return 0;
}