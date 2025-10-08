#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void) {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    float a, b, c;
    scanf("%f %f %f", &a, &b, &c);

    int D;

    if (a != 0) {
        D = pow(b, 2) - 4 * a * c;

        if (D > 0) {
            float x1 = (-b + sqrt(D)) / (2 * a), x2 = (-b - sqrt(D)) / (2 * a);
            
            if (x1 > x2) {
                printf("%d\n%0.5f %0.5f", 2, x2, x1);
            }
            else {
                printf("%d\n%0.5f %0.5f", 2, x1, x2);
            }
        }
        if (D == 0) {
            float x = (-b) / (2 * a);
            printf("%d\n%0.5f", 1, x);
        }
        if (D < 0) {
            printf("NO");
        }
    }
    else {
        if (b != 0) {
            float x = (-c) / b;
            printf("%d\n%0.5f", 1, x);
        }
        else {
            if (c != 0) {
                printf("ERROR");
            }
            else {
                printf("MANY");
            }
        }
    }
}