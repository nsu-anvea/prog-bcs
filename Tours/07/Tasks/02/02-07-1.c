#include <stdio.h>
#define MAX 1000000
#include <string.h>

int main() {
    FILE * f;
    f = fopen("input.txt", "r");

    int mas_dl[MAX] = {0};

    char s[MAX];
    while (fscanf(f, "%s", s) != EOF) {
        int len = strlen(s);
        mas_dl[len]++;
    }
    fclose(f);
    f = fopen("output.txt", "w");
    for (int i = 1; i < MAX; i++) {
        if (mas_dl[i] != 0) {
            fprintf(f, "%d - %d\n", i, mas_dl[i]);
        }
    }

    return 0;
}
