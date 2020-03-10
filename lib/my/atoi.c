/*
** EPITECH PROJECT, 2018
** my_runner
** File description:
** convert char * to int
*/

#include <stdlib.h>

int my_strlen(char const *str);

int my_atoi(char const *str)
{
    int nb = 0;

    for (int i = 0; str[i] != '\0'; i++)
        nb = (nb * 10) + (str[i] - '0');
    return (nb);
}

int my_size(char *str)
{
    int i = 0;
    int count = 1;

    for (i = 0; str[i] != '\0'; i++)
        count = count * 10;
    return (count);
}

float my_atof(char const *str)
{
    int i = 0;
    char *stk = malloc(sizeof(char) * my_strlen(str) + 1);
    char *stk2 = malloc(sizeof(char) * my_strlen(str) + 1);
    float stock = 0;
    float stock2 = 0;
    int a = 0;

    for (; str[i] != '.'; i++)
        stk[i] = str[i];
    stk[i] = '\0';
    i++;
    for (; str[i] != '\0'; i++, a++)
        stk2[a] = str[i];
    stk2[a] = '\0';
    stock = my_atoi(stk);
    stock2 = ((float)my_atoi(stk2) / (my_size(stk2)));
    stock = stock + stock2;
    return (stock);
}
