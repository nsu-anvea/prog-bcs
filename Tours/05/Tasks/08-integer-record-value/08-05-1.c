//_____________// Task #8 //_____________//
#include <stdio.h>
#include <string.h>

void SWAP(char * a, char * b) {
    char t = * a;
    * a = * b;
    * b = t;
}

void reverse(char mas[50], int len) {
    int until = len / 2;
    for (int z = 0; z < until; z++) {
        SWAP(&mas[z], &mas[len - z - 1]);
    }
    mas[len] = '\0';
}

int main() {
    freopen("input.txt", "r", stdin);

    int SIS, a;
    scanf("%d\n%d", &SIS, &a);

    char s[50];

    if (a == 0) {
        printf("%d", 0);
    }

    int k = 0;
    while (a > 0) {
        int ost = a % SIS;
        if (ost > 9) {
            ost = (char)('a' + ost - 10);
        }
        else {
            ost = (char)('0' + ost);
        }

        s[k] = ost;
        k++;
        a = a / SIS;
    }
    reverse(s, k);

    printf("%s", s);

    return 0;
}
