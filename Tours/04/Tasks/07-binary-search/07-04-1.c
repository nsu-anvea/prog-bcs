#include <stdio.h>

int main() {
    freopen("input.txt", "r", stdin);

    int len_mas;
    int x;
    scanf("%d", &len_mas);
    scanf("%d", &x);

    int mas[1000000] = {0};
    for (int i = 0; i < len_mas; i++) {
        int a;
        scanf("%d", &a);

        mas[i] = a;
    }

    int l = 0, r = len_mas - 1;

    while (l != r && mas[l] != x) {
        int razdel;
        razdel = l + (r - l) / 2; // 2    3

        if (x == mas[razdel]) {
            l = razdel;
        }
        else {
            if (x > mas[razdel]) { // 9 > 7, l = 3
                l = razdel + 1;
            }
            else {
                r = razdel - 1;
            }
        }
//        for (int i = l; i <= r; i++) {
//            printf("%d ", mas[i]);
//        }
//        printf("\n");
    }
    if (mas[l] != x) {
        printf("%d", -1);
        return 0;
    }
//    while (mas[l] == mas[l - 1]) {
//        l = l - 1;
//    }
    printf("%d", l);

    return 0;
}
