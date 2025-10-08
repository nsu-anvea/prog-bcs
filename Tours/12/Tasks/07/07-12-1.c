//_____________// Task #7 //_____________//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct LIST {
    int key;
    char word[10];
} S;

void ins_sort(S ** a, int n) {
    for (int i = 1; i < n; i++) {
        S * x = a[i];
        int j = i - 1;
        while ((j >= 0) && (a[j]->key > x->key)) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = x;
    }
}

int main() {
    freopen("input.txt", "r", stdin);

    int N;
    scanf("%d", &N);

    S ** mas;
    mas = (S**)malloc( sizeof(S*) * N );

    int el, i = 0;
    while (scanf("%d", &el) != EOF) {
        S * element;
        element = (S*)malloc( sizeof(S) );

        element->key = el;
        scanf("%s", element->word);

        mas[i] = element;

        i++;
    }

    ins_sort(mas, N);
    
    for (int i = 0; i < N; i++) {
        printf("%d %s\n", mas[i]->key, mas[i]->word);
    }

    for (int i = 0; i < N; i++) {
        free(mas[i]);
    }

    return 0;
}
