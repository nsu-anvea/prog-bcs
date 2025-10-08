//_____________// Task #3 //_____________//
#include <stdio.h>
#include <string.h>
#define MAX 1000000

int main() {
    FILE * f;
    f = fopen("input.txt", "r");

    char str[MAX];
    int SUMMA = 0;
    while (fgets(str, MAX, f) != NULL) {
        int cnt__ = 0;
        int flag = 0;
        int i = 0;
        while (1) {
            if ((int)str[i] != 0) {
                if ((int)str[i] <= 32) {
                    if (str[i] == ' ') {
                        cnt__++;
                    }
                }
                else {
                    flag = 1;
                    break;
                }
            i++;
            }
            else {
                break;
            }
        }

        if (flag == 1) {
            SUMMA += cnt__;
        }
    }

    fclose(f);
    f = fopen("output.txt", "w");
    fprintf(f, "%d", SUMMA);

    return 0;
}
