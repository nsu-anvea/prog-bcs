//_____________// Task #2 //_____________//
#include <stdio.h>

unsigned Big_Endian(unsigned el) {
    unsigned res = 0;

    int step = 0;
    unsigned S = 1 << 24, SS;
    step = 0;
    for (int j = 0; j < 4; j++) {
        SS = S;
        for (int z = 0; z < 8; z++) {
            if (el & SS) {
                res += (1 << step);
            }
            step++;
            SS = SS << 1;
        }
        S = S >> 8;
    }
    return res;
}

int main() {
    FILE * in = fopen("input.bin", "rb");
    FILE * out = fopen("output.bin", "wb");

    unsigned n;
    fread(&n, sizeof(int), 1, in);

    unsigned SUMMA = 0;

    // Если n очень большое, то записано в Big-Endian
    if (n > 10000) {
        unsigned N;
        N = Big_Endian(n); // Меняем байты в n

        int step = 0;
        for (int i = 0; i < N; i++) {
            unsigned el;
            fread(&el, sizeof(int), 1, in);

            // Меняем байты в el и добавляем в SUMMA
            SUMMA += Big_Endian(el);
        }
        unsigned Answer = Big_Endian(SUMMA);
        fwrite(&Answer, sizeof(int), 1, out);
    }
    // Если n если нормальное, то Little-Endian
    else {
        for (int i = 0; i < n; i++) {
            unsigned el;
            fread(&el, sizeof(int), 1, in);

            SUMMA += el;
        }
        fwrite(&SUMMA, sizeof(int), 1, out);
    }

    return 0;
}
