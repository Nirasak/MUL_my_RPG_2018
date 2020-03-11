/*
** EPITECH PROJECT, 2019
** RPG
** File description:
** create sprite from file
*/

#include "my.h"

int change_text_enemy(char *obj, sfSprite *sprite, char *place)
{
    char **all;
    sfTexture *text;
    char *path;

    if (extract_data_file(place, &all) == 84)
        return (84);
    path = find_obj(all, obj);
    text = sfTexture_createFromFile(path, NULL);
    sfSprite_setTexture(sprite, text, sfTrue);
    return (0);
}

int change_basic_stat_enemy(char *obj, char *place)
{
    char **all;
    char *path;

    if (extract_data_file(place, &all) == 84)
        return (84);
    path = find_obj(all, obj);
    path[my_strlen(path) - 1] = '\0';
    return (my_atoi(path));
}

float change_sec_enemy(char *obj, char *place)
{
    char **all;
    char *path;

    if (extract_data_file(place, &all) == 84)
        return (84);
    path = find_obj(all, obj);
    path[my_strlen(path) - 1] = '\0';
    return (my_atof(path));
}

int change_rect_enemy(char *obj, char *place, sfIntRect *rect)
{
    char **all;
    char *path;
    char **stock;

    if (extract_data_file(place, &all) == 84)
        return (-84);
    path = find_obj(all, obj);
    stock = str_to_wordtab(path);
    rect->left = 0;
    rect->top = my_atoi(stock[1]);
    rect->width = my_atoi(stock[2]);
    stock[3][my_strlen(stock[3]) - 1] = '\0';
    rect->height = my_atoi(stock[3]);
    return (0);
}
