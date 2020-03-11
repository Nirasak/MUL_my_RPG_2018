/*
** EPITECH PROJECT, 2019
** backgrounds_fights.c
** File description:
** create my backgrounds for my fight
*/

#include "my.h"

int init_bg_fight(fight_t *f)
{
    char **path;

    if (extract_data_file("./src/menu/.bgfight", &path) == 84)
        return (84);
    f->bgf.jungle = f_sprite_create("JUNGLE", path, 0, 0);
    f->bgf.cave = f_sprite_create("CAVE", path, 0, 0);
    return (0);
}
