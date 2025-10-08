//_____________// Task #1 //_____________//
#include <stdio.h>
#include <stdlib.h>

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int N;
    scanf("%d", &N);

    int BASE[256][256] = {0};
    int G_mas[256][256] = {0};
    int Helper_mas[256][256] = {0};

    // Заполняю базовыми элементами и сразу вывожу BASE
    for (int i = 0; i < N; i++) {
        BASE[i][0] = i + 1;
        printf("%d\n", i + 1);

        G_mas[i][0] = i + 1;
        Helper_mas[i][0] = i + 1;
    }

    for (int steps = 0; steps < N - 1; steps++) {
        // Копирую Helper_mas в G_mas
        int cp = 0;
        while (G_mas[cp][0] != 0 || Helper_mas[cp][0] != 0) { // G_mas[cp][0] != 0
            for (int s = 0; s < steps + 1; s++) {
                G_mas[cp][s] = Helper_mas[cp][s];
            }
            //memcpy(G_mas[cp], Helper_mas[cp], sizeof(int) * N);
            cp++;
        }

        // Очищаю Helper_mas
        int delout = 0;
        while (Helper_mas[delout][0] != 0) {
            for (int delin = 0; delin < steps + 1; delin++) {
                Helper_mas[delout][delin] = 0;
            }
            delout++;
        }
        // Нахожу возможные комбинации каждого G_mas[i][steps] с элементами из BASE[G_mas[steps]][0]
        int start = 0;
        int i = 0;
        while (G_mas[i][0] != 0) {
            int start_points_combinations = G_mas[i][steps];
            int cnt_combinations = N - start_points_combinations;

            // Копирую нужное cnt... комбинаций в Helper
            // и дописываю комбинацию числом из BASE
            for (int j = 0; j < cnt_combinations; j++) {
                int xx = BASE[G_mas[i][steps] + j][0];
                int ind = 0;
                while (G_mas[i][ind] != 0) {
                    Helper_mas[start + j][ind] = G_mas[i][ind];

                    printf("%d ", Helper_mas[start + j][ind]);
                    ind++;
                }
                Helper_mas[start + j][steps + 1] = xx;

                printf("%d\n", Helper_mas[start + j][steps + 1]);
            }
            start = start + cnt_combinations;
            i++;
        }
    }

    return 0;
}
