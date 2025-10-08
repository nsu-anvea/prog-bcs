//_____________// Task #4 //_____________//
#include <stdio.h>
#include <stdlib.h>

typedef struct LIST {
    int a;
    struct LIST * next;
} S;

/* int not_in_mas(S * h, int e) {
    while (h != NULL) {
        if (h->a == e) {
            return 0;
        }
        h = h->next;
    }
    return 1;
} */

void empty(S * h) {
    S * p = h;
    while (h != NULL) {
        h = h->next;
        free(p);
        p = h;
    }
}

int main() {
    freopen("input.txt", "r", stdin);

    S * element;
    element = (S*)malloc( sizeof(S) );
    int el;
    scanf("%d", &el);

    element->a = el;
    element->next = NULL;

    S * head = element;
    S * p = head;
    while (scanf("%d", &el) != EOF) {
        if (p->a != el) {
            S * element;
            element = (S*)malloc( sizeof(S) );

            element->a = el;
            element->next = NULL;
            p->next = element;
            p = element;
        }
    }

    while (head != NULL) {
        printf("%d ", head->a);
        head = head->next;
    }

    empty(head);

    return 0;
}
