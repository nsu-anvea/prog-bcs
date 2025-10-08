#include <stdio.h>

// int (char(1), short(2), long(4), long long(8))
// float
// double в 2 раза больше float

// indigned - беззнаковый тип. Пример: unsigned char

// можно делать так: d = (a = 2) * 3
// можно делать a++ (значит: a += 1)

// && - and, || - or, ! - reverse (отрицание)
// pow - возведение в степень

// для double используем %lf

int summa(int x, int y) {
    int c;
    c = x + y;

    return c;
}

int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    a++;
    if (!(a)) {
        printf("%d", a + b);
    }
    b--;
    printf("%d %d", a, b);
    printf("%d\n", summa(a, b));

    // альтернативный условный оператор c = (a < b ? a : b);
    // это значит, что если а < b, то присваиваем с значение a, иначе b
    
    return 0;
}

