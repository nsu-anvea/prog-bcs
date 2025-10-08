//_____________// Task #3 //_____________//
#include <stdio.h>
#include <stdlib.h>

typedef struct LIST {
    int a;
    struct LIST * next;
} S;

int main() {
    freopen("input.txt", "r", stdin);

    S * element;
    element = (S*) malloc( sizeof(S) );
    element->next = NULL;

    int el;
    scanf("%d", &element->a);

    S * head, * tail;
    head = element;
    tail = element;
    while (scanf("%d", &el) != EOF) {
        S * element;
        element = (S*) malloc( sizeof(S) );
        element->a = el;

        // add left
        if (el < head->a) {
            element->next = head;
            head = element;
        }
        else {
            // add right
            if (el > tail->a) {
                tail->next = element;
                element->next = NULL;
                tail = element;
            }
            // add middle
            else {
                S * p = head, * pp;
                while (p->next != NULL) {
                    if (p->a <= el && el <= (p->next)->a) {
                        if (el != p->a && el != (p->next)->a) {
                            pp = p->next;
                            p->next = element;
                            element->next = pp;

                            break;
                        }
                    }
                    p = p->next;
                }
            }
        }
    }

    S * h = head, * hh;
    while (h != NULL) {
        printf("%d ", h->a);
        hh = h;
        h = h->next;
        free(hh);
    }
    return 0;
}
