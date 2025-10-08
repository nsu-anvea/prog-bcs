#include <stdio.h>

int main() { // A-Z: 65-90, a-z: 97-122
    freopen("input.txt", "r", stdin);

    int k = 0;
    int flag = 0;

    while (1) {
        char a;
        scanf("%c", &a);

        if ((a != '.') && (a != '\n')) {
            if (flag == 0) {
                k++;
                flag = 1;
            }
        }
        else {
            flag = 0;
        }
        if (a == '\n') {
            break;
        }
    }
    printf("%d", k);

    return 0;
}