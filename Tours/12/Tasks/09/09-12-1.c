//_____________// Task #9 //_____________//
#include <stdio.h>
#include <stdlib.h>

#define P 301

typedef struct list {
    int el;
    struct list * next;
} COUPLE;

typedef struct LIST {
    struct list * head;
    struct list * tail;
} Pointer_HandT;

int isFunc(Pointer_HandT * Z) {
    for (int q = 0; q < P; q++) {
        if (Z[q].head != NULL) {
            COUPLE * h = Z[q].head;
            int x = h->el;
            while (h != NULL) {
                if (h->el != x) {
                    return 0;
                }
                h = h->next;
            }
        }
    }
    return 1;
}

int isAllDf(Pointer_HandT * Z, int n) {
    for (int q = 1; q <= n; q++) {
        if (Z[q].head == NULL) {
            return 0;
        }
    }
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);

    int N, M;
    scanf("%d %d", &N, &M);

    Pointer_HandT * basic_X;
    basic_X = (Pointer_HandT *)malloc( sizeof(Pointer_HandT) * P );

    Pointer_HandT * basic_Y;
    basic_Y = (Pointer_HandT *)malloc( sizeof(Pointer_HandT) * P );

    for (int i = 0; i < P; i++) {
        basic_X[i].head = NULL;
        basic_X[i].tail = NULL;

        basic_Y[i].head = NULL;
        basic_Y[i].tail = NULL;
    }

    int el1, el2;
    for (int i = 0; i < M; i++) {
        scanf("%d %d", &el1, &el2);
        if (basic_X[el1].head == NULL) {
            basic_X[el1].head = (COUPLE *)malloc( sizeof(COUPLE) );
            basic_X[el1].head->el = el2;
            basic_X[el1].head->next = NULL;
            basic_X[el1].tail = basic_X[el1].head;
        }
        else {
            COUPLE * element_for_X;
            element_for_X = (COUPLE *)malloc( sizeof(COUPLE) );

            element_for_X->el = el2;
            element_for_X->next = NULL;

            basic_X[el1].tail->next = element_for_X;
            basic_X[el1].tail = element_for_X;
        }

        if (basic_Y[el2].head == NULL) {
            basic_Y[el2].head = (COUPLE *)malloc( sizeof(COUPLE) );
            basic_Y[el2].head->el = el1;
            basic_Y[el2].head->next = NULL;
            basic_Y[el2].tail = basic_Y[el2].head;
        }
        else {
            COUPLE * element_for_Y;
            element_for_Y = (COUPLE *)malloc( sizeof(COUPLE) );

            element_for_Y->el = el1;
            element_for_Y->next = NULL;

            basic_Y[el2].tail->next = element_for_Y;
            basic_Y[el2].tail = element_for_Y;
        }
    }
    
    int k = 0;

    int Func = isFunc(basic_X);
    if (Func) {
        k++;
        printf("1 ");
    }

    int Df = Func * isAllDf(basic_X, N);
    if (Df) {
        k++;
        printf("2 ");
    }

    int Inec = isFunc(basic_Y);
    if (Inec) {
        k++;
        printf("3 ");
    }

    int Surec = Inec * isAllDf(basic_Y, N);
    if (Surec) {
        k++;
        printf("4 ");
    }

    int Biec = Inec * Surec;
    if (Biec) {
        printf("5 ");
    }

    if (k == 0) {
        printf("0");
    }

    return 0;
} 
