/*
** EPITECH PROJECT, 2019
** str_to_wordtab
** File description:
** char * to char **
*/

#include <stdlib.h>

int my_strlen(char *str);

int count_word(char *map)
{
    int i = 0;
    int count = 0;

    for (i = 0; map[i] != '\0'; i++)
        map[i] == ';' ? count++ : 0;
    return (count);
}

char **str_to_wordtab(char *str)
{
    int j = 0;
    int y = 0;
    char **tab = NULL;

    tab = malloc(sizeof(char *) * (4 + 1));
    tab[j] = malloc(sizeof(char) * (my_strlen(str) + 1));
    for (int i = 0; str[i] != '\0'; i++) {
        for (; str[i] != ',' && str[i] != '\0'; i++, y++)
            tab[j][y] = str[i];
        tab[j][y] = '\0';
        y = 0;
        if (str[i] == '\0')
            break;
        j++;
        tab[j] = malloc(sizeof(char) * (my_strlen(str) + 1));
    }
    j++;
    tab[j] = NULL;
    return (tab);
}
