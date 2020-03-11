/*
** EPITECH PROJECT, 2019
** RPG
** File description:
** annex_option
*/

#include "my.h"

static void cat_path(dwd_t *dwd, int i, char *cating)
{
    char *full_path = malloc
        (my_strlen(cating) + my_strlen(dwd->menu.data[i]) + 1);
    char *path;
    int j = 0;

    for (; dwd->menu.data[i][j] != '='; j++);
    path = malloc(j + 2);
    for (j = 0; dwd->menu.data[i][j] != '='; j++)
        path[j] = dwd->menu.data[i][j];
    path[j] = '=';
    path[j + 1] = '\0';
    full_path = my_strcat(path, cating, full_path);
    free(dwd->menu.data[i]);
    dwd->menu.data[i] = my_strdup(full_path);
    free(full_path);
    free(path);
}

void modify_data(dwd_t *dwd, char *obj, char *cating)
{
    int fd = open("./src/menu/.loading_menu", O_WRONLY | O_TRUNC);

    for (int i = 0; dwd->menu.data[i] != NULL; i++) {
        my_strncmp(dwd->menu.data[i], obj, my_strlen(obj)) == 0 ?
            cat_path(dwd, i, cating) : 0;
        write(fd, dwd->menu.data[i], my_strlen(dwd->menu.data[i]));
        write(fd, "\n", 1);
    }
}
