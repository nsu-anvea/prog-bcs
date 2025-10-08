#include <stdio.h>

int gcd(int a, int b) {

    while (b != 0) {
        int n = a;
        a = b;
        b = n % b;
    }
    return a;
}


int main() {
    int a, b;
    scanf("%d %d", &a, &b);

    printf("%d", gcd(a, b));

    return 0;
}