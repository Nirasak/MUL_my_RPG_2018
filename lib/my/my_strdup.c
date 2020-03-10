/*
** EPITECH PROJECT, 2018
** my_strdup
** File description:
** strduplicate
*/

#include <stdlib.h>

int my_strlen(char const *str);

char *my_strdup(char const *src)
{
    int i = 0;
    char *str = malloc(my_strlen(src) + 1);

    if (str == NULL)
        return (NULL);
    while (src[i] != '\0') {
        str[i] = src[i];
        i += 1;
    }
    str[i] = '\0';
    return (str);
}
