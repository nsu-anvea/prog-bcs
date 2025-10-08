//_____________// Task #3 //_____________//
#include <stdio.h>
#include <stdlib.h>

typedef struct Answer {
    unsigned long long max_gold;
    int k;
    unsigned positions;
} A;

typedef struct LIST {
    long long int weight;
    long long int gold;
} S;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int N;
    unsigned long long W;
    scanf("%d %lld\n", &N, &W);

    A Answer;
    Answer.max_gold = 0;

    S * mas = (S*)malloc( sizeof(S) * N );

    for (int i = 0; i < N; i++) {
        scanf("%lld %lld\n", &mas[i].weight, &mas[i].gold);
    }

    unsigned long long SUM_Weight, SUM_Gold;
    int k, flag;
    unsigned until = 1 << N, Mask;
    for (unsigned i = 0; i < until; i++) {
        SUM_Weight = 0;
        SUM_Gold = 0;
        k = 0;
        flag = 1;

        Mask = 1;
        for (int step = 1; step <= 32; step++) {
            if (Mask & i) {
                k++;
                SUM_Weight += mas[step - 1].weight;
                if (SUM_Weight > W) {
                    flag = 0;
                    break;
                }
                SUM_Gold += mas[step - 1].gold;
            }
            Mask = Mask << 1;
        }
        if (SUM_Weight <= W && flag == 1) {
            if (SUM_Gold >= Answer.max_gold) {
                Answer.max_gold = SUM_Gold;
                Answer.k = k;
                Answer.positions = i;
            }
        }
    }

    printf("%lld %d\n", Answer.max_gold, Answer.k);

    Mask = 1;
    for (int i = 1; i <= 32; i++) {
        if (Answer.positions & Mask) {
            printf("%d ", i);
        }
        Mask = Mask << 1;
    }

    return 0;
}
