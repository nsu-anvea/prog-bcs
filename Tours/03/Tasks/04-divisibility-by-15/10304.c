#include <stdio.h>

int main() {
    int summa = 0;
    char pred;

    while (1) {
        char a;
        scanf("%c", &a);

        if (a == '.') {
            break;
        }
        else {
            summa += a - 48;
            pred = a;
        }
    }

    if ((pred == '0' || pred == '5') && (summa % 3 == 0)) {
        printf("YES");
    }
    else {
        printf("NO");
    }

    return 0;
}