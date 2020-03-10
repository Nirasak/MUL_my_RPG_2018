/*
** EPITECH PROJECT, 2019
** RPG
** File description:
** modify_file
*/

#include "my.h"

static void cat_path(char **tab, int i, char *cating)
{
    char *full_path = malloc
        (my_strlen(cating) + my_strlen(tab[i]) + 1);
    char *path;
    int j = 0;

    for (; tab[i][j] != '='; j++);
    path = malloc(j + 2);
    for (j = 0; tab[i][j] != '='; j++)
        path[j] = tab[i][j];
    path[j] = '=';
    path[j + 1] = '\0';
    full_path = my_strcat(path, cating, full_path);
    free(tab[i]);
    tab[i] = my_strdup(full_path);
    free(full_path);
    free(path);
}

void modify_file(char **tab, char *obj, char *cating, char *path)
{
    int fd = open(path, O_WRONLY | O_TRUNC);

    for (int i = 0; tab[i] != NULL; i++) {
        my_strncmp(tab[i], obj, my_strlen(obj)) == 0 ?
            cat_path(tab, i, cating) : 0;
        write(fd, tab[i], my_strlen(tab[i]));
        write(fd, "\n", 1);
    }
}
