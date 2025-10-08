//_____________// Task #5 //_____________//
#include <stdio.h>
#include <stdlib.h>

typedef struct LIST {
    int a;
    struct LIST * next;
} S;

void empty(S * h) {
    S * B;
    while (h != NULL) {
        B = h;
        h = h->next;
        free(B);
    }
}

int main() {
    freopen("input.txt", "r", stdin);

    int delit;
    scanf("%d", &delit);

    S * element;
    element = (S*)malloc( sizeof(S) );
    
    int el;
    scanf("%d", &el);

    element->a = el;
    element->next = NULL;

    S * head = element;
    S * p = head;
    while (scanf("%d", &el) != EOF) {
        S * element;
        element = (S*)malloc( sizeof(S) );

        element->a = el;
        element->next = p;
        p = element;
        head = p;
    }

    S * HEAD;
    HEAD = (S*)malloc( sizeof(S) );
    HEAD->a = -100000;
    HEAD->next = head;

    S * pp = HEAD;
    p = HEAD->next;
    while (p->next != NULL) {
        if ((p->next)->a == delit) {
            S * Bin = p;
            pp->next = p->next;
            p = p->next;
            free(Bin);
        }
        else {
            pp = p;
            p = p->next;
        }
    }

    p = HEAD->next;
    while (p != NULL) {
        printf("%d ", p->a);
        p = p->next;
    }

    empty(HEAD);

    return 0;
}
