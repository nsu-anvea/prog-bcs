#include <stdio.h>
#include <string.h>
#define MAX 105

int calcLetters(char *iStr, int *oLowerCnt, int *oUpperCnt, int *oDigitsCnt) {
    int z = 0;
    while ((int)(*(iStr + z)) != 0 && *(iStr + z) != '\n') { // (int)(*(iStr + z)) != 0 && 
        if ('a' <= *(iStr + z) && *(iStr + z) <= 'z') {
            (*oLowerCnt)++;
        }
        if ('A' <= *(iStr + z) && *(iStr + z) <= 'Z') {
            (*oUpperCnt)++;
        }
        if ('0' <= *(iStr + z) && *(iStr + z) <= '9') {
            (*oDigitsCnt)++;
        }
        z++;
    }

    return z;
}

int main() {
    FILE *file;
    file = fopen("input.txt", "r");
    FILE *file2;
    file2 = fopen("output.txt", "w");

    char s[MAX];
    int k = 0;
    while (fgets(s, MAX, file) != NULL) {
        k++;
        int Low = 0, Upp = 0, Digits = 0;
        int len_str = calcLetters(s, &Low, &Upp, &Digits);
        // int len_str = (int)strlen(s) - 1; 

        fprintf(file2, "Line %d has %d chars: %d are letters (%d lower, %d upper), %d are digits.\n", k, len_str, Low + Upp, Low, Upp, Digits);
    }
    fclose(file);
    fclose(file2);

    return 0;
}
