//_____________// Task #8 //_____________//
#include <stdio.h>
#include <stdlib.h>

void merge_sort(int * m, int l, int r, int * res) {
    if (r - l <= 0) {
        res[l] = m[l];
    }
    else {
        int middle = (l + r) / 2;

        merge_sort(m, l, middle, res);
        merge_sort(m, middle + 1, r, res);

        int len_for_l = middle - l + 1;
        int len_for_r = r - middle;

        int position_res = 0, ind_left = 0, ind_right = 0;
        while (ind_left < len_for_l || ind_right < len_for_r) {
            if (ind_left == len_for_l) {
                res[l + position_res] = m[middle + 1 + ind_right];
                position_res++;
                ind_right++;
            }
            else if (ind_right == len_for_r) {
                res[l + position_res] = m[l + ind_left];
                position_res++;
                ind_left++;
            }
            else {
                if (m[l + ind_left] < m[middle + 1 + ind_right]) {
                    res[l + position_res] = m[l + ind_left];
                    position_res++;
                    ind_left++;
                }
                else {
                    res[l + position_res] = m[middle + 1 + ind_right];
                    position_res++;
                    ind_right++;
                }
            }
        }

        for (int i = l; i <= r; i++) {
            m[i] = res[i];
        }
    }
}

int main() {
    FILE * in = fopen("input.bin", "rb");
    FILE * out = fopen("output.bin", "wb");

    int N;
    fread(&N, sizeof(int), 1, in);

    int * mas = (int *)malloc( sizeof(int) * N );
    int * mas_sorted = (int *)malloc( sizeof(int) * N );

    for (int i = 0; i < N; i++) {
        fread(&mas[i], sizeof(int), 1, in);
    }
    fclose(in);

    merge_sort(mas, 0, N - 1, mas_sorted);

    for (int i = 0; i < N; i++) {
        fwrite(&mas[i], sizeof(int), 1, out);
    }

    fclose(out);

    // Clearning the memory
    free(mas);
    free(mas_sorted);

    return 0;
}
