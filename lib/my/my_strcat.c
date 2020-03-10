/*
** EPITECH PROJECT, 2018
** my_strcat
** File description:
** strcat
*/

#include <stdlib.h>

int my_strlen(char const *s);

char *my_strcat(char const *dest, char const *src, char *save)
{
    int i = 0;

    for (; dest[i] != '\0'; i++)
        save[i] = dest[i];
    for (int count = 0; src[count] != '\0'; count++, i++)
        save[i] = src[count];
    save[i] = '\0';
    return (save);
}

char *my_realstrcat(char *dest, char const *src)
{
    int i = 0;
    int count = 0;
    char *stock = malloc(sizeof(char) * my_strlen(dest) + my_strlen(src) + 3);

    for (; dest[i] != '\0'; i++)
        stock[i] = dest[i];
    while (src[count] != '\0') {
        stock[i] = src[count];
        count += 1;
        i += 1;
    }
    stock[i] = '\0';
    return (stock);
}
