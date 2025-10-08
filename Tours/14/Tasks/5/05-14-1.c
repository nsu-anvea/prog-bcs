#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 9

// Функции для работы с Судоку
bool is_valid(int sudoku[SIZE][SIZE], int row, int col, int num);
bool solve_sudoku(int sudoku[SIZE][SIZE]);
bool find_empty(int sudoku[SIZE][SIZE], int *row, int *col);
void print_sudoku(int sudoku[SIZE][SIZE]);

// Функции для работы с файлами
void read_sudoku(FILE *file, int sudoku[SIZE][SIZE]);
void write_sudoku(FILE *file, int sudoku[SIZE][SIZE]);

int main() {
    FILE *input_file = fopen("input.txt", "r");
    FILE *output_file = fopen("output.txt", "w");
    if (input_file == NULL || output_file == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    int puzzles_count;
    fscanf(input_file, "%d\n", &puzzles_count);

    for (int p = 0; p < puzzles_count; p++) {
        int sudoku[SIZE][SIZE];
        read_sudoku(input_file, sudoku);

        if (solve_sudoku(sudoku)) {
            write_sudoku(output_file, sudoku);
            fprintf(output_file, "\n");
        } else {
            fprintf(output_file, "No solution\n");
        }
    }

    fclose(input_file);
    fclose(output_file);
    return 0;
}

bool is_valid(int sudoku[SIZE][SIZE], int row, int col, int num) {
    for (int x = 0; x < SIZE; x++) {
        if (sudoku[row][x] == num || sudoku[x][col] == num ||
            sudoku[3 * (row / 3) + x / 3][3 * (col / 3) + x % 3] == num) {
            return false;
        }
    }
    return true;
}

bool solve_sudoku(int sudoku[SIZE][SIZE]) {
    int row, col;
    if (!find_empty(sudoku, &row, &col)) {
        return true;  // Решение найдено
    }

    for (int num = 1; num <= SIZE; num++) {
        if (is_valid(sudoku, row, col, num)) {
            sudoku[row][col] = num;
            if (solve_sudoku(sudoku)) {
                return true;
            }
            sudoku[row][col] = 0;  // Откатываем изменения
        }
    }
    return false;
}

bool find_empty(int sudoku[SIZE][SIZE], int *row, int *col) {
    for (*row = 0; *row < SIZE; (*row)++) {
        for (*col = 0; *col < SIZE; (*col)++) {
            if (sudoku[*row][*col] == 0) {
                return true;
            }
        }
    }
    return false;
}

void print_sudoku(int sudoku[SIZE][SIZE]) {
    for (int row = 0; row < SIZE; row++) {
        for (int col = 0; col < SIZE; col++) {
            printf("%d ", sudoku[row][col]);
        }
        printf("\n");
    }
}

void read_sudoku(FILE *file, int sudoku[SIZE][SIZE]) {
    for (int row = 0; row < SIZE; row++) {
        for (int col = 0; col < SIZE; col++) {
            char ch;
            do {
                fscanf(file, "%c", &ch);
            } while (ch == '\n');
            sudoku[row][col] = (ch == '.') ? 0 : ch - '0';
        }
    }
}

void write_sudoku(FILE *file, int sudoku[SIZE][SIZE]) {
    for (int row = 0; row < SIZE; row++) {
        for (int col = 0; col < SIZE; col++) {
            fprintf(file, "%d", sudoku[row][col]);
        }
        fprintf(file, "\n");
    }
}
