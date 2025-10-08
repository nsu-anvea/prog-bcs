//_____________// Task #4 //_____________//
#include <stdio.h>
#include <string.h>
#include <time.h>

int main() {
    freopen("input.txt", "r", stdin);

    char first[1000];
    scanf("%s", first);

    int len = strlen(first);
    char str[1000];
    while (scanf("%s", str) != -1) {
        int len_n = strlen(str);
        int k = 0;
        for (int i = 0; i < len_n; i++) {
            for (int j = 0; j < len; j++) {
                if (str[i] == first[j]) {
                    k++;
                    break;
                }
            }
            if (k != 0) {
                break;
            }
        }
        if (k == 0) {
            printf("%s\n", str);
        }
    }

    return 0;
}
