//_____________// Task #8 //_____________//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000001

typedef struct list {
    char word[10];
    struct list * next;
} Under_Struct;

typedef struct LIST {
    struct list * head;
    struct list * tail;
} General_Struct;

int main() {
    freopen("input.txt", "r", stdin);

    int N;
    scanf("%d", &N);

    General_Struct * mas;
    mas = (General_Struct *)malloc( sizeof(General_Struct) * MAX );

    for (int i = 0; i < N; i++) {
        mas[i].head = NULL;
        mas[i].tail = NULL;
    }

    int el;
    while ( scanf("%d", &el) != EOF ) { 
        if (mas[el].head == NULL) {
            mas[el].head = (Under_Struct *)malloc( sizeof(Under_Struct) );
            mas[el].tail = mas[el].head;
            scanf("%s", (mas[el].head)->word);
            (mas[el].head)->next = NULL;
        }
        else {
            Under_Struct * el_of_struct;
            el_of_struct = (Under_Struct *)malloc( sizeof(Under_Struct) );

            scanf("%s", el_of_struct->word);
            el_of_struct->next = NULL;

            (mas[el].tail)->next = el_of_struct;
            mas[el].tail = el_of_struct;
        }
    }

    for (int i = 0; i < MAX; i++) {
        if (mas[i].head != NULL) {
            Under_Struct * P = mas[i].head;
            while (P != NULL) {
                printf("%d %s\n", i, P->word);
                P = P->next;
            }
        }
    }
 
    return 0;
}
