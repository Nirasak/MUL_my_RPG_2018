/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** instance
*/

#include "my.h"

void init_instance(map_t *map)
{
    map->inst.x = 485 / 2 + map->perso.p_perso.x / 4;
    map->inst.y = 290 / 2 + map->perso.p_perso.y / 4;
    map->inst.zoom.x = map->origin.x + map->inst.x;
    map->inst.zoom.y = map->origin.y + map->inst.y;
    map->inst.x_cait = map->perso.r_perso.width / 4;
    map->inst.y_cait = map->perso.r_perso.height / 4;
    map->inst.zoom_cait.x = map->inst.x_cait;
    map->inst.zoom_cait.y = map->inst.y_cait;
}

void unblack_instance(map_t *map)
{
    map->inst.r_black.left = map->inst.r_black.left - 1920;
    sfSprite_setTextureRect(map->inst.s_black, map->inst.r_black);
    sfClock_restart(map->inst.clock_b);
}

void reini_instance_before(map_t *map)
{
    sfVector2f pos = {0, 0};
    sfVector2f len = {1, 1};

    map->inst.size.x = 2;
    map->inst.size.y = 2;
    sfSprite_setOrigin(map->s_map, map->origin);
    sfSprite_setScale(map->s_map, map->inst.size);
    sfSprite_setOrigin(map->perso.s_perso, pos);
    sfSprite_setScale(map->perso.s_perso, len);
}

void after_instance(map_t *map, dwd_t *dwd)
{
    reini_instance_before(map);
    while (sfRenderWindow_isOpen(dwd->window) && map->inst.r_black.left > 0) {
        clock_instance(map);
        display_map(map, dwd);
        if (map->inst.scd_b >= 0.05 && map->inst.r_black.left > 0)
            unblack_instance(map);
        sfRenderWindow_drawSprite(dwd->window, map->inst.s_black, NULL);
        sfRenderWindow_display(dwd->window);
    }
}
