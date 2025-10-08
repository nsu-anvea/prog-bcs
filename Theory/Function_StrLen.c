#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int strl(char * s) {
    int n;

    for (n = 0; s[n]; n++) {}
    return n;
}

int main() {
    char * mas;
    mas = (char *) malloc(1);
    int cnt = 0;

    char a;
    scanf("%c", &a);
    while (a != '\n') {
        mas = malloc(16);
        mas[cnt] = a;
        cnt++;
        scanf("%c", &a);
    }

    printf("Strlen = %d", strl(mas));
    return 0;
}