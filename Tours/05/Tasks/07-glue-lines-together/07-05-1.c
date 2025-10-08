//_____________// Task #7 //_____________//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * concat(char * pref, char * suff) {
    int l = strlen(suff);
    for (int i = 0; i < l; i++) {
        *(pref + i) = *(suff + i);
    }
    *(pref + l) = '\0';

    pref = pref + l;
    return pref;
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int N;
    scanf("%d", &N);

    char * a = (char *)malloc( sizeof(char) * N * 101 );

    char * p = a;
    for (int i = 0; i < N; i++) {
        char string[101];
        scanf("%s", string);

        p = concat(p, string);
    }

    printf("%s", a);

    return 0;
}
