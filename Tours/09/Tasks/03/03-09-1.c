//_____________// Task #3 //_____________//
#include <stdio.h>
#include <stdlib.h>

typedef struct Tokens_s {
    int num; //количество слов в строке
    char **arr; //массив слов (каждый элемент –- строка, т.е. char*)
} Tokens;
//tokens: структура, в которую нужно положить результаты
//str: строка, в которой нужно искать слова
//delims: все символы-разделители в виде строки
//Разделители - точка, запятая, точка с запятой, двоеточие

void tokensSplit(Tokens *tokens, const char *str, const char *delims) {
    if (tokens->arr == NULL) {
        int * mas;
        mas = (int *)malloc( sizeof(int) * 1000000 );

        int flag = 0, k_num = 0, ind = 0;
        char el = *str;
        if (el != *(delims) && el != *(delims + 1) &&
         el != *(delims + 2) && el != *(delims + 3)) {
            flag = 1;
            ind++;
        }
        int z = 1;
        while (*(str + z) != '\0') {
            el = *(str + z);
            if (el == *(delims) || el == *(delims + 1) ||
             el == *(delims + 2) || el == *(delims + 3)) {
                if (flag == 1) {
                    mas[k_num] += ind + 1;
                    k_num++;
                    ind = 0;
                    flag = 0;
                }
            } 
            else {
                ind++;
                flag = 1;
            }
            z++;
        }
        if (flag == 1) {
            mas[k_num] += ind + 1;
            k_num++;
        }
        mas[k_num] += -1;

        tokens->arr = (char **)malloc( sizeof(char *) * k_num );
        tokens->num = k_num;
        ind = 0;
        while (mas[ind] != -1) {
            tokens->arr[ind] = (char *)malloc( mas[ind] );
            ind++;
        }
    } 
    else {
        int flag = 0, k_num = 0, index = 0;
        char el = *str;

        if (el != *(delims) && el != *(delims + 1) &&
         el != *(delims + 2) && el != *(delims + 3)) {
            flag = 1;
            tokens->arr[k_num][index] = el;
            index++;
        }
        int z = 1;
        while (*(str + z) != '\0') {
            el = *(str + z);
            if (el == *(delims) || el == *(delims + 1) ||
             el == *(delims + 2) || el == *(delims + 3)) {
                if (flag == 1) {
                    tokens->arr[k_num][index] = '\0';
                    k_num++;
                    flag = 0;
                    index = 0;
                }
            } 
            else {
                flag = 1;
                tokens->arr[k_num][index] = el;
                index++;
            }
            z++;
        }
        if (flag == 1) {
            tokens->arr[k_num][index] = '\0';
            k_num++;
        }
    }
}
//удаляет все ресурсы внутри tokens
void tokensFree(Tokens *tokens) {
    int len = tokens->num;
    for (int i = 0; i < len; i++) {
        free(tokens->arr[i]);
    }
    free(tokens->arr);
}

int main() {
    freopen("input.txt", "r", stdin);

    Tokens tokens;
    tokens.arr = NULL;
    char Delims[] = {'.', ',', ';', ':'};
    char * String;
    String = (char *)malloc( 1000001 );

    scanf("%s", String);

    tokensSplit(&tokens, String, Delims);
    tokensSplit(&tokens, String, Delims);

    int kk = tokens.num;
    printf("%d\n", kk);
    for (int i = 0; i < kk; i++) {
        printf("%s\n", tokens.arr[i]);
    }

    tokensFree(&tokens);

    return 0;
}
