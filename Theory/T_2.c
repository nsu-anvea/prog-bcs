#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS

int getSum(int a, int b, int table[10][10]) {
    return table[a][b];
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int table[10][10];
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            scanf("%d", &table[i][j]);
        }
    }

    // Чтение таблицы сложения цифры '@' с десятичной цифрой
    int a_table[10];
    for (int i = 0; i < 10; i++) {
        scanf("%d", &a_table[i]);
    }

    // Чтение таблицы сложения десятичной цифры с цифрой '@'
    int with_a_table[10];
    for (int i = 0; i < 10; i++) {
        scanf("%d", &with_a_table[i]);
    }

    int Q;
    scanf("%d", &Q);

    for (int q = 0; q < Q; q++) {
        char num1[1004], num2[1004];
        scanf("%s %s", num1, num2);

        int len1 = strlen(num1);
        int len2 = strlen(num2);

        // Выравнивание чисел по младшим разрядам
        int maxLen = max(len1, len2);
        int diff = (len1 > len2) ? (len1 - len2) : (len2 - len1);
        char alignedNum1[1004], alignedNum2[1004];

        // Дописывание '@' слева от значащих цифр
        if (len1 < len2) {
            for (int i = 0; i < diff; i++) {
                alignedNum1[i] = '@';
            }
            for (int i = diff; i < maxLen; i++) {
                alignedNum1[i] = num1[i - diff];
            }
            alignedNum1[maxLen] = '\0';
            for (int i = 0; i <= len2; i++) {
                alignedNum2[i] = num2[i];
            }
        } else if (len2 < len1) {
            for (int i = 0; i < diff; i++) {
                alignedNum2[i] = '@';
            }
            for (int i = diff; i < maxLen; i++) {
                alignedNum2[i] = num2[i - diff];
            }
            alignedNum2[maxLen] = '\0';
            for (int i = 0; i <= len1; i++) {
                alignedNum1[i] = num1[i];
            }
        } else {
            for (int i = 0; i <= len1; i++) {
                alignedNum1[i] = num1[i];
            }
            for (int i = 0; i <= len2; i++) {
                alignedNum2[i] = num2[i];
            }
        }

        // результат сложения
        char res[1004];
        for (int i = 0; i < maxLen; i++) {
            int digit1, digit2;
            if (alignedNum1[i] == '@') {
                digit1 = 10;
            } else {
                digit1 = alignedNum1[i] - '0';
            }
            if (alignedNum2[i] == '@') {
                digit2 = 10;
            } else {
                digit2 = alignedNum2[i] - '0';
            }

            if (digit1 == 10 && digit2 == 10) {
                res[i] = '@';
            } else if (digit1 == 10) {
                res[i] = a_table[digit2] + '0';
            } else if (digit2 == 10) {
                res[i] = with_a_table[digit1] + '0';
            } else {
                res[i] = getSum(digit1, digit2, table) + '0';
            }
        }
        res[maxLen] = '\0';

        printf("%s\n", res);
    }

    return 0;
}