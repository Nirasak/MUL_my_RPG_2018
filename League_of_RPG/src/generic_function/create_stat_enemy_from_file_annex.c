/*
** EPITECH PROJECT, 2019
** RPG
** File description:
** create_sprite_from_enemi_annex
*/

#include "my.h"

char *cond_change_scl_enemy(char *path, int i)
{
    int a = 0;
    char *stk2 = NULL;

    stk2 = malloc(sizeof(char) * my_strlen(path));
    i++;
    for (a = 0; path[i] != '\0'; i++, a++)
        stk2[a] = path[i];
    stk2[a] = '\0';
    return (stk2);
}

int change_scl_enemy(char *obj, char *place, sfVector2f *scl)
{
    char **all;
    char *path;
    char *stk;
    char *stk2;
    int i = 0;

    if (extract_data_file(place, &all) == 84)
        return (84);
    path = find_obj(all, obj);
    path[my_strlen(path) - 1] = '\0';
    stk = malloc(sizeof(char) * my_strlen(path));
    for (i = 0; path[i] != ','; i++)
        stk[i] = path[i];
    stk[i] = '\0';
    scl->x = my_atof(stk);
    stk2 = cond_change_scl_enemy(path, i);
    scl->y = my_atof(stk2);
    return (0);
}
