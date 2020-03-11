/*
** EPITECH PROJECT, 2018
** my_strcmp
** File description:
** compare strings
*/

#include <stddef.h>

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;

    while (s1[i] == s2[i] && (s1[i] != '\0' && s2[i] != '\0')) {
        if (s1[i] != '\0' && s2[i] == '\0')
            return (1);
        if (s1[i] == '\0' && s2[i] != '\0')
            return (-1);
        i += 1;
    }
    if (s1[i] == s2[i])
        return (0);
    if (s1[i] > s2[i])
        return (1);
    else
        return (-1);
}

int my_strncmp(char const *s1, char const *s2, int n)
{
    if (s1 == NULL || s2 == NULL || n <= 0)
        return (-1);
    for (int i = 0; i != n; i++) {
        if (s1[i] != s2[i])
            return (1);
    }
    return (0);
}
