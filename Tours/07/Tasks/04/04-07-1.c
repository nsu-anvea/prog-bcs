#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE * file;
    file = fopen("input.txt", "r");

    int mas[127] = {0};

    char a;
    while (fscanf(file, "%c", &a) != -1) {
        mas[(int)a]++;
    }

    fclose(file);
    file = fopen("output.txt", "w");

    for (int i = 32; i < 127; i++) {
        if (mas[i] != 0) {
            fprintf(file, "%c ", i);
            for (int j = 0; j < mas[i]; j++) {
                fprintf(file, "#");
            }
            fprintf(file, "%c", '\n');
        }
    }
    fclose(file);

    return 0;
}
