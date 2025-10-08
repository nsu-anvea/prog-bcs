//_____________// Task #3 //_____________//
#include <stdio.h>
#include <stdlib.h>

void Conclusion(int * m, int len, FILE * OUT) {
    for (int i = 0; i < len; i++) {
        fwrite(&m[i], sizeof(int), 1, OUT);
    }
}

int main() {
    FILE * in = fopen("input.bin", "rb");
    FILE * out = fopen ("output.bin", "wb");

    int N;
    fread(&N, sizeof(int), 1, in);

    int PILOT;
    fread(&PILOT, sizeof(int), 1, in);

    // mas_smaller - массив эл-ов меньших PILOT
    int * mas_smaller = (int *)malloc( sizeof(int) * N ), len_s = 0;
    // mas_bigger - массив эл-ов больших PILOT
    int * mas_bigger = (int *)malloc( sizeof(int) * N ), len_b = 0;
    // mas_equal - массив эл-ов равных PILOT
    int * mas_equal = (int *)malloc( sizeof(int) * N ), len_e = 0;

    int el;
    for (int i = 0; i < N; i++) {
        fread(&el, sizeof(int), 1, in);

        if (el == PILOT) {
            mas_equal[len_e] = el;
            len_e++;
        }
        else {
            if (el < PILOT) {
                mas_smaller[len_s] = el;
                len_s++;
            }
            else {
                mas_bigger[len_b] = el;
                len_b++;
            }
        }
    }

    int k = len_s + len_e / 2;
    fwrite(&k, sizeof(int), 1, out);
    
    Conclusion(mas_smaller, len_s, out);
    Conclusion(mas_equal, len_e, out);
    Conclusion(mas_bigger, len_b, out);

    return 0;
}
