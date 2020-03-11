/*
** EPITECH PROJECT, 2019
** cut str
** File description:
** cut_string.c
*/

#include <stdlib.h>

int my_strlen(char *s);

char *cut_str(char *s)
{
    char *stock = malloc(sizeof(char) * my_strlen(s));
    int j;

    for (j = 0; s[j] != ';'; j++)
        stock[j] = s[j];
    stock[j] = '\0';
    return (stock);
}

char *get_cut_str(char *s)
{
    char *stock = malloc(sizeof(char) * my_strlen(s) + 1);
    int j = 0;
    int a = 0;

    for (int count = 0; count < 2; j++)
        if (s[j] == ';')
            count++;
    for (a = 0; s[j] != '\0'; j++, a++) {
        if (s[j] == 'a' && s[j + 1] == 'n' && s[j + 2] == 'd')
            break;
        stock[a] = s[j];
    }
    stock[a] = '\0';
    return (stock);
}

char *get_and_str(char *s)
{
    char *stock = malloc(sizeof(char) * my_strlen(s) + 1);
    int j = 0;
    int a = 0;

    for (int count = 0; count < 2; j++)
        if (s[j] == ';')
            count++;
    for (; s[j] != '\0'; j++) {
        if (s[j] == 'a' && s[j + 1] == 'n' && s[j + 2] == 'd')
            break;
    }
    for (a = 0; s[j] != '\0'; j++, a++) {
        stock[a] = s[j];
    }
    stock[a] = '\0';
    return (stock);
}

char *return_price(char *s)
{
    int i = 0;
    char *stock = malloc(sizeof(char) * my_strlen(s) + 1);
    int a = 0;

    for (i = 0; s[i] != ':'; i++);
    i++;
    for (a = 0; s[i] != ';'; a++, i++)
        stock[a] = s[i];
    stock[a] = '\0';
    return (stock);
}

char *return_stat_item(char *s)
{
    int i = 0;
    char *stock = malloc(sizeof(char) * my_strlen(s) + 1);
    int a = 0;

    for (i = 0; s[i] != ';'; i++);
    i++;
    for (a = 0; s[i] != ':'; a++, i++)
        stock[a] = s[i];
    stock[a] = '\0';
    return (stock);
}
