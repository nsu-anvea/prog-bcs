//_____________// Task #1 //_____________//
#include <stdio.h>

int main() {
    FILE * f;
    f = fopen("input.txt", "r");

    int s[256] = {0};
    unsigned char a;
    while (fscanf(f, "%c", &a) != EOF) {
        s[(int)a]++;
    }

    fclose(f);
    f = fopen("output.txt", "w");

    for (int i = 13; i < 256; i++) {
        if (s[i] != 0) {
            fprintf(f, "%d : %c - %d\n", i, (char)i, s[i]);
        }
    }

    fclose(f);

    return 0;
}
