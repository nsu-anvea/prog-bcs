//_____________// Task #3 //_____________//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Create(int l, char ** m, int index) {
    m[index] = (char *)malloc( sizeof(char) * (l + 1) );
    int i = 0;
    while (i < l) {
        scanf("%c", &m[index][i]);
        i++;
    }
    m[index][i] = '\0';
}

int Cnt_El(char e, char * m) {
    int i = 0, k = 0;
    while (*(m + i) != '\0') {
        if (*(m + i) == e) {
            k++;
        }
        i++;
    }
    return k;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int N;
    scanf("%d", &N);

    char ** mas;
    mas = (char **)malloc( sizeof(char *) * 100000 );

    int mas_index[100000] = {0};

    int ind_str = 0;
    int e1, e2;
    for (int i = 0; i < N; i++) {
        scanf("%d %d ", &e1, &e2);

        if (e1 == 0) {
            Create(e2, mas, ind_str);

            mas_index[ind_str] = 1;

            ind_str++;
        }
        if (e1 == 1) {
            free(mas[e2]);

            mas_index[e2] = 0;
        }
        if (e1 == 2) {
            printf("%s\n", mas[e2]);
        }
        if (e1 == 3) {
            char el;
            scanf("%c", &el);

            printf("%d\n", Cnt_El(el, mas[e2]));
        }
    }

    for (int i = 0; i < ind_str; i++) {
        if (mas_index[i] != 0) {
            free(mas[i]);
        }
    }
    free(mas);

    return 0;
}
