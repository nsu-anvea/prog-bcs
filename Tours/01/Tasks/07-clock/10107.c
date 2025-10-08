#include <stdio.h>

int main(void) {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int x, y, z;
    scanf("%d %d %d", &x, &y, &z);

    if (x <= 0 || y <= 0 || z <= 0) {
        if (x <= 0) {
            printf("%d", -1);
        }
        else {
            if (y <= 0) {
                printf("%d", -2);
            }
            else {
                printf("%d", -3);
            }
        }
    }
    else {
        int a = x * y, b = y * z, c = z * x;
        printf("%d\n", 2 * a + 2 * b + 2 * c);
    }

}