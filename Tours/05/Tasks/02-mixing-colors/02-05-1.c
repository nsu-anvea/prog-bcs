#include <stdio.h>
#include <string.h>

char need[6];
char colors[26];

int purple() {
    for (int i = 0; i < 26; i++) {
        int R = 0, B = 0;
        if (colors[i] == 'R') {
            R = i + 1;
            printf("%d ", R);
        }
        if (colors[i] == 'B') {
            B = i + 1;
            printf("%d ", B);

        }
    }
}

int green() {
    for (int i = 0; i < 26; i++) {
        int B = 0, Y = 0;
        if (colors[i] == 'B') {
            B = i + 1;
            printf("%d ", B);
        }
        if (colors[i] == 'Y') {
            Y = i + 1;
            printf("%d ", Y);

        }
    }
}

int orange() {
    for (int i = 0; i < 26; i++) {
        int R = 0, Y = 0;
        if (colors[i] == 'R') {
            R = i + 1;
            printf("%d ", R);
        }
        if (colors[i] == 'Y') {
            Y = i + 1;
            printf("%d ", Y);

        }
    }
}

int main() {
    freopen("input.txt", "r", stdin);

    scanf("%s", need);
    scanf("%s", colors);

    if (need[0] == 'p') {
        purple();
    }
    if (need[0] == 'g') {
        green();
    }
    if (need[0] == 'o') {
        orange();
    }

    return 0;
}
