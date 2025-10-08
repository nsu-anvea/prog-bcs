#include <stdio.h>
#include <string.h>
#define max 20

typedef struct Label_s {
    char name [max]; //имя автора (заканчивается нулём)
    int age; //возраст автора (сколько лет)
} Label;

typedef struct NameStats_s {
    int cntTotal; //сколько всего подписей
    int cntLong; //сколько подписей с именами длиннее 10 букв
} NameStats;

typedef struct AgeStats_s {
    int cntTotal;
    int cntAdults;
    int cntKids;
} AgeStats;

void calcStats(const Label *arr, int cnt, NameStats *oNames, AgeStats *oAges) {
    oNames -> cntTotal++;
    if (strlen((arr + cnt)->name) > 10) {
        oNames -> cntLong++;
    }
    oAges -> cntTotal++;
    if ((arr + cnt)->age >= 18) {
        oAges -> cntAdults++;
    }
    else {
        if ((arr + cnt)->age < 14) {
        oAges -> cntKids++;
        }
    }
}

int main() {
    freopen("input.txt", "r", stdin);

    int N;
    scanf("%d", &N);

    Label list[1000];
    NameStats NS;
    AgeStats AS;


    for (int i = 0; i < N; i++) {
        char skip[5];
        scanf("%s %d %s", list[i].name, &list[i].age, skip);

        calcStats(list, i, &NS, &AS);
    }

    printf("names: total = %d\nnames: long = %d\nages: total = %d\nages: adult = %d\nages: kid = %d",
    NS.cntTotal, NS.cntLong, AS.cntTotal, AS.cntAdults, AS.cntKids);

    return 0;
}
