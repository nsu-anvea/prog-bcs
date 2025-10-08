//_____________// Task #1 //_____________//
#include <stdio.h>
#include <stdlib.h>

typedef struct DateTime_s {
    int year, month, day;
    int hours, minutes, seconds;
} DateTime;

DateTime redo(DateTime min__Data, int g, int m, int d, int hh, int mm, int ss) {
    min__Data.year = g;
    min__Data.month = m;
    min__Data.day = d;
    min__Data.hours = hh;
    min__Data.minutes = mm;
    min__Data.seconds = ss;

    return min__Data;
}

DateTime findMinData(DateTime * arr, int N) {
    DateTime min_Data;

    int G, M, D, h, m, s;
    G = arr[0].year;
    M = arr[0].month;
    D = arr[0].day;
    h = arr[0].hours;
    m = arr[0].minutes;
    s = arr[0].seconds;

    min_Data = redo(min_Data, G, M, D, h, m, s);

    for (int i = 1; i < N; i++) {
        int G, M, D, h, m, s;
        G = arr[i].year;
        M = arr[i].month;
        D = arr[i].day;
        h = arr[i].hours;
        m = arr[i].minutes;
        s = arr[i].seconds;

        if (G < min_Data.year) {
            min_Data = redo(min_Data, G, M, D, h, m, s);
        }
        else {
            if (G == min_Data.year) {
                if (M < min_Data.month) {
                    min_Data = redo(min_Data, G, M, D, h, m, s);
                }
                else {
                    if (M == min_Data.month) {
                        if (D < min_Data.day) {
                            min_Data = redo(min_Data, G, M, D, h, m, s);
                        }
                        else {
                            if (D == min_Data.day) {
                                if (h < min_Data.hours) {
                                    min_Data = redo(min_Data, G, M, D, h, m, s);
                                }
                                else {
                                    if (h == min_Data.hours) {
                                        if (m < min_Data.minutes) {
                                            min_Data = redo(min_Data, G, M, D, h, m, s);
                                        }
                                        else {
                                            if (m == min_Data.minutes) {
                                                if (s < min_Data.seconds) {
                                                    min_Data = redo(min_Data, G, M, D, h, m, s);
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return min_Data;
}

int main() {
    freopen("input.txt", "r", stdin);
    
    int N;
    scanf("%d", &N);

    DateTime * mas = (DateTime *)malloc( sizeof(DateTime) * N);

    for (int i = 0; i < N; i++) {
        scanf (
            "%d %d %d %d %d %d", 
            &mas[i].year, &mas[i].month, &mas[i].day,
            &mas[i].hours, &mas[i].minutes, &mas[i].seconds
        );    

    }

    DateTime minData = findMinData(mas, N);

    printf("%d %d %d %d %d %d", minData.year,
     minData.month, minData.day, minData.hours,
      minData.minutes, minData.seconds);

    return 0;
}
