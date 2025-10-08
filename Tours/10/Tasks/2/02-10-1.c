//_____________// Task #2 //_____________//
#include <stdio.h>
#include <stdlib.h>

typedef struct list {
    int number;
    struct list * next;
} S;

int sr_a(S * h) {
    int s = 0;
    int k = 0;

    while (h != NULL) {
        s += h->number;
        k++;
        h = h->next;
    }

    return (int)(s / k);
}

void empty(S * h) {
    S * pp;
    while (h != NULL) {
        pp = h;
        h = h->next;
        free(pp);
    }
}

int main() {
    freopen("input.txt", "r", stdin);

    S * element;
    element = (S*)malloc( sizeof(S) );
    element->next = NULL;
    int el;
    scanf("%d", &el);
    element->number = el;

    S * head = element;
    S * p = head;

    while (scanf("%d", &el) != EOF) {
        S * element;
        element = (S*)malloc( sizeof(S) );

        element->number = el;
        p->next = element;
        p = element;
        element->next = NULL;
    }

    int Middle_arifmetic;
    Middle_arifmetic = sr_a(head);
    printf("%d", Middle_arifmetic);

    empty(head);

    return 0;
}
