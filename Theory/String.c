#include <stdio.h>
#include <string.h>

int strl(char * s) {
    int n;

    for (n = 0; s[n]; n++) {}
    return n;
}

int main() {
    char * mas = "Hello world";
    printf("Strlen = %d", strl(mas));
    return 0;
}