//_____________// Task #1 //_____________//
#include <stdio.h>
#include <string.h>

int main() {
    freopen("input.txt", "r", stdin);

    char a[100];

    int player = 0;
    while (scanf("%s", a) != -1) {
        player++;
        char bukva = (char)('a' + (player - 1));
        int cnt = 0;

        int len = strlen(a);
        for (int i = 0; i < len; i++) {
            if (a[i] == bukva) {
                cnt++;
            }
        }
        if (cnt == 0) {
            if (player % 2 == 0) {
                printf("PLAYER 1");
                return 0;
            }
            else {
                printf("PLAYER 2");
                return 0;
            }
        }
    }
    printf("NO WINNER");

    return 0;
}
