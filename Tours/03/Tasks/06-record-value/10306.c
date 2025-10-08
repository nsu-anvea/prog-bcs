#include <stdio.h>

int main() {
    freopen("input.txt", "r", stdin);

    int sis_schis, res = 0;
    char skip;
    scanf("%d", &sis_schis);
    scanf("%c", &skip);

    while (1) {
        char a;
        scanf("%c", &a);

        if (a != '\n') {
            if ('a' <= a && a <= 'z') {
                a -= 87;
            }
            else {
                a -= 48;
            }
            res = res * sis_schis + a;
        }
        else {
            break;
        }
    }
    printf("%d", res);

    return 0;
}