#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void) {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int k;
    scanf("%d", &k);

    int D = 1 + 4 * 2 * (k - 1);
    float res = (-1 + sqrt(D)) / 2;
    
    if (res == (int)res) {
        printf("1");
    }
    else {
        printf("0");
    }
}