#include <stdio.h>

int main() {
    FILE * in = fopen("input.bin", "rb");
    FILE * out = fopen("output.bin", "wb");

    int a, b;
    long long res;
    fread(&a, sizeof(int), 1, in);
    fread(&b, sizeof(int), 1, in);

    res = (long long)a + b;
    if (res >= 0) {
        res /= 2;
    }
    else {
        res = (res - 1) / 2;
    }
    a = (int)res;

    fwrite(&a, sizeof(int), 1, out);

    return 0;
}
