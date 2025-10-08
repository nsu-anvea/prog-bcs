//_____________// Task #5 //_____________//
#include <stdio.h>
#include <string.h>

void SWAP(char * a, char * b) {
    char t = * a;
    * a = * b;
    * b = t;
}

void reverse(char mas[100], int len) {
    int until = len / 2;
    for (int z = 0; z < until; z++) {
        SWAP(&mas[z], &mas[len - z - 1]);
    }
}

int main() {
    freopen("input.txt", "r", stdin);

    int kol_vo_strs;
    scanf("%d\n", &kol_vo_strs);

    for (int i = 0; i < kol_vo_strs; i++) {
        char a[100];
        scanf("%s\n", a);

        reverse(a, (int)strlen(a));

        printf("%s\n", a);
    }

    return 0;
}
