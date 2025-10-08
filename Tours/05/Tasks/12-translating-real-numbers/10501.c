#include <stdio.h>
#include <math.h>
#define LN 110

void swap(char *a, char *b) {
    char c = *a;
    *a = *b;
    *b = c;
}

void reverse(char *mas, int len) {
    for (int i = 0; i < len / 2; i++) {
        swap(&mas[LN - len + i], &mas[LN - (i + 1)]);
    }
}

int give_num(char sign) {
    if ('0' <= sign && sign <= '9')
        return sign - '0';
    if ('a' <= sign && sign <= 'f')
        return sign - 'a' + 10;
    if ('A' <= sign && sign <= 'F')
        return sign - 'A' + 10;
    return -1;
}

char give_sign(int num) {
    if (0 <= num && num <= 9)
        return (char)num + '0';
    if (10 <= num && num <= 15)
        return (char)num + 'a' - 10;
    return -1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    // ns - number system
    // ds - number of decimal places
    int ns1, ns2, ds;
    scanf("%d %d %d\n", &ns1, &ns2, &ds);

    if (ns1 > 16 || ns1 < 2 || ns2 > 16 || ns2 < 2) {
        printf("ERROR\n");
        return 1;
    }
    if (ds > 20 || ds < 1) {
        printf("ERROR\n");
        return 1;
    }

    float num_10 = 0;
    int   div = ns1;
    int   dot = 0;

    char sign;
    while (scanf("%c", &sign) != EOF && sign != '\n') {
        if (give_num(sign) >= ns1 || give_num(sign) == -1 || dot > 1) {
            printf("ERROR");
            return 1;
        }
        if (sign == '.')
            dot += 1;
        else {
            if (!dot)
                num_10 = num_10 * ns1 + give_num(sign);
            else {
                num_10 += ((float) 1 / div) * give_num(sign);
                div *= ns1;
            }
        }
    }

    char num_ns2[LN] = {'\0'};
    char len = 0;

    int int_part = floor(num_10);

    while (int_part > 0) {
        len++;
        num_ns2[LN - len] = give_sign(int_part % ns2);
        int_part /= ns2;
    }
    len++;
    num_ns2[LN - len] = '.';

    int max_len = len + ds;

    reverse(num_ns2, len - 1);

    if (floor(num_10) != num_10) {
        float float_part = num_10 - floor(num_10);

        while (float_part && len < max_len) {
            float_part *= ns2;
            len++;
            num_ns2[LN - len] = give_sign((int)floor(float_part));
            float_part -= floor(float_part);
        }


        for (int i = 1; i <= len; i++) {
            printf("%c", num_ns2[LN - i]);
        }
    }
    else {
        for (int i = 1; i < len; i++) {
            printf("%c", num_ns2[LN - i]);
        }
    }

    return 0;
}