//_____________// Task #1 //_____________//
#include <stdio.h>
#include <stdlib.h>

typedef struct list {
    int a;
    struct list * next;
} S;

void empty(S * head) {
    S * pp;
    while (head != NULL) {
        pp = head;
        head = head->next;
        free(pp);
    }
}

int negative_numbers(S * head) {
    int k = 0;
    while (head->next != NULL) {
        if (head->a < 0) {
            if ((-1 * (head->a)) % 7 == 0) {
                k++;
            }
        }
        head = head->next;
    }
    return k;
}

int main() {
    freopen("input.txt", "r", stdin);

    S * element;
    element = (S*) malloc( sizeof( S ) );
    int el;
    scanf("%d", &el);

    element->a = el;
    element->next = NULL;

    S * head;
    head = element;
    S * p;
    p = head;

    while (scanf("%d", &el) != EOF) {
        S * element;
        element = (S*) malloc( sizeof( S ) );
        element->a = el;
        element->next = p;

        head = element;
        p = head;
    }

    printf("%d", negative_numbers(p));

    empty(p);

    return 0;
}
