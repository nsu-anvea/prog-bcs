//---------------// task #2 //---------------//
#include <stdio.h>
#include <string.h>

int main() {
    freopen("input.txt", "r", stdin);

    char S1[26], S2[26];

    scanf("%s", S1);
    scanf("%s", S2);

    char mas[26] = {0};

    int len1 = strlen(S1);
    int len2 = strlen(S2);
    for (int i = 0; i < len1; i++) {
        int cnt = 0;
        for (int j = 0; j < len2; j++) {
            if (S1[i] == S2[j]) {
                cnt++;
            }
        }

        if (cnt == 0) {
            mas[(int)(S1[i] - 'A')] = S1[i];
        }
    }

   int k = 0;
    for(int i = 0; i < 26; i++) {
        if (mas[i] >= 'A' && mas[i] <='Z') {
            k++;
            printf("%c", mas[i]);
        
        }
    }

    if (k == 0) {
        printf("Empty Set");
    }

    return 0;
}
