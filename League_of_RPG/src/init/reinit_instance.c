/*
** EPITECH PROJECT, 2019
** rpg.h
** File description:
** init instance
*/

#include "my.h"

void reinit_instance(map_t *map)
{
    map->inst.size.x = 2;
    map->inst.size.y = 2;
    map->inst.scd = 0;
    map->inst.p_black.x = 0;
    map->inst.p_black.y = 0;
    map->inst.r_black.top = 0;
    map->inst.r_black.left = 0;
    map->inst.r_black.width = 1920;
    map->inst.r_black.height = 1080;
    sfSprite_setTexture(map->inst.s_black, map->inst.t_black, sfTrue);
    sfSprite_setTextureRect(map->inst.s_black, map->inst.r_black);
    sfSprite_setPosition(map->inst.s_black, map->inst.p_black);
    map->inst.scd_b = 0;
}
