//_____________// Task #2 //_____________//
#include <stdio.h>
#include <stdlib.h>

// Массив для предыдущих размещений ферзей
int mas[15][2];
// Массив для вывода, если YES
int mas_Answer[15][15];

void Conclusion(int len, int lines, int columns) {
    for (int i = 0; i < len; i++) {
        mas_Answer[mas[i][0]][mas[i][1]] = 'X';
    }

    for (int i = 0; i < lines; i++) {
        for (int j = 0; j < columns; j++) {
            printf("%c", mas_Answer[i][j]);
        }
        printf("\n");
    }
}

int All_GOOD(int l, int c, int len_mas) {
    int flag = 1;
    
    for (int i = 0; i < len_mas; i++) {
        // Если выполняются эти условия, то либо на диагонали, либо
        // на вертикали тоже стоит ферзь
        if ((mas[i][1] == c) || (abs(mas[i][0] - l) == abs(mas[i][1] - c))) {
            flag = 0;
            break;
        }
    }
    return flag;
}

int Placement(int l, int len_mas, int lines, int columns, char m[15][15]) {
    int res = 0;
    for (int c = 0; c < columns; c++) {
        if (m[l][c] == '?') {
            res = 0;
            if (All_GOOD(l, c, len_mas)) {
                mas[len_mas][0] = l;
                mas[len_mas][1] = c;

                if (l != lines - 1) {
                    res = Placement(l + 1, len_mas + 1, lines, columns, m);
                }
                else {
                    res = 1;
                }
            }
        }
        if (res == 1) {
            break;
        }
    }
    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    // Задаю значения глобального массива (mas) нулями
    for (int i = 0; i < 15; i++) {
        mas[i][0] = 0;
        mas[i][0] = 0;
    }

    // Задаю значения массива для вывода (mas_Answer) точками
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 15; j++) {
            mas_Answer[i][j] = '.';
        }
    }

    int Lines, Columns;
    scanf("%d %d\n", &Lines, &Columns);

    // Матрица с элементами из исходной таблицы
    char matrix[15][15];

    // Заполняю матрицу значениями из данной таблицы
    char fields_dot, skip;
    for (int i = 0; i < Lines; i++) {
        for (int j = 0; j < Columns; j++) {
            scanf("%c", &fields_dot);

            matrix[i][j] = fields_dot;
        }
        scanf("%c", &skip);
    }

    if (Placement(0, 0, Lines, Columns, matrix)) {
        printf("YES\n");

        Conclusion(Lines, Lines, Columns);
    }
    else {
        printf("NO");
    }

    return 0;
}
