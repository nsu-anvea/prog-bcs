#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    freopen("input.txt", "r", stdin);

    char x, y;
    scanf("%c %c", &x, &y);
    
    if (x == 'M') {
        printf("%d", 1);
    }
    if (x == 'T') {
        if (y == 'u') {
            printf("%d", 2);
        }
        else {
            printf("%d", 4);
        }
    }
    if (x == 'W') {
        printf("%d", 3);
    }
    if (x == 'F') {
        printf("%d", 5);
    }
    if (x == 'S') {
        if (y == 'a') {
            printf("%d", 6);
        }
        else {
            printf("%d", 7);
        }
    }

    return 0;
}