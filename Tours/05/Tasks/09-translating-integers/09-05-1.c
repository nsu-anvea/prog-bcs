//_____________// Task #9 //_____________//
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

int FromSIS1(char s[50], int sis) {
    int n_10 = 0;

    char a;
    int n = 0;
    while (s[n] != '\0') {
        a = s[n];
        if ('a' <= a && a <= 'z') {
            n_10 = n_10 * sis + (int)(a - 'a' + 10);
        }
        else {
            n_10 = n_10 * sis + (int)(a - '0');
        }
        n++;
    }
    return n_10;
}

void ToSIS2(char s[50], int a, int sis) {
    int k = 0;
    while (a > 0) {
        int ost = a % sis;
        if (ost > 9) {
            ost = (char)('a' + ost - 10);
        }
        else {
            ost = (char)('0' + ost);
        }

        s[k] = ost;
        k++;
        a /= sis;
    }
    reverse(s, k);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int SIS1, SIS2;
    scanf("%d %d ", &SIS1, &SIS2);

    char N[50], res[50];
    scanf("%s", N);

    int N_10 = FromSIS1(N, SIS1);

    if (N_10 == 0) {
        printf("%d", 0);
    }
    else {
        ToSIS2(res, N_10, SIS2);
        printf("%s", res);
    }

    return 0;
}
