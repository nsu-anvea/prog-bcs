#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

void reverse(char* start, int len)
{
    int n = 0;
    char k;
    while (n < len)
    {
        k = start[n];
        start[n] = start[len];
        start[len] = k;
        n++;
        len--;
    }
}

int main()
{
    char s[] = "0123456789abcdefg";
    char number_osn1, number_osn2[1000000], checker = 0;
    int osn1, osn2, number_10 = 0, k, check = 1;
    scanf("%d %d %d ", &osn1, &osn2, &k);
    if (osn1 > 16 || osn1 < 2 || osn2 > 16 || osn2 < 2)
    {
        printf("NO");
        return 0;
    }
    if (k > 20 || k < 1)
    {
        printf("NO");
        return 0;
    }
    while (scanf("%c", &number_osn1) == 1)
    {
        if (number_osn1 == '.')
        {
            check = 1;
            break;
        }
        if (number_osn1 == '\n')
        {
            check = 0;
            break;
        }
        while (s[checker] != number_osn1)
        {
            checker++;
        }
        if (checker >= osn1 || checker < 0)
        {
            printf("NO");
            return 0;
        }
        checker = 0;
        int b = 0;
        for (int i = 0; i < 20; i++)
        {
            if (number_osn1 == s[i])
            {
                b = i;
                break;
            }
        }
        number_10 *= osn1;
        number_10 += b;
    }

    int i = 0, j;
    while (number_10 >= osn2)
    {
        j = number_10 % osn2;
        number_osn2[i] = s[j];
        number_10 = number_10 / osn2;
        i++;
    }
    j = number_10 % osn2;
    number_osn2[i] = s[j];
    reverse(number_osn2, i);



    if (check == 1)
    {
        int len;
        double number2 = 0;
        char number1[10000];
        scanf("%s", number1);
        len = strlen(number1);
        for (int j = len - 1; j > -1; j--)
        {
            if (number1[j] >= s[osn1] || number1[j] == '.')
            {
                printf ("NO");
                return 0;
            }
            if (number1[j] < 'a')
            {
                number2 = (number1[j] - '0' + number2) / osn1;
            }
            else if (number1[j] <= 'f')
            {
                number2 = (number1[j] - 'a' + 10 + number2) / osn1;
            }
        }
        number2 *= 1000000;
        number2 = round(number2);
        number2 /= 1000000;
        printf("%s", number_osn2);


        int l = 0, b;
        char number3[10000];
        while (l < k)
        {
            number2 *= osn2;
            number2 *= 1000000000;
            number2 = round(number2);
            number2 /= 1000000000;
            b = (int)number2;
            number3[l] = s[b];
            l++;
            if (number2 == b)
                break;
            if (number2 > 1)
                number2 -= b;
        }
        int d = l;
        for (int k = l - 1; k > 0; k--)
        {
            if (number3[k] != '0')
                break;
            d = k;

        }
        int m = 0;
        if (m < d)
            printf(".");
        while (m < d)
        {
            printf("%c", number3[m]);
            m++;
        }
    }
    else
    {
        printf("%s", number_osn2);
    }
    return 0;
}