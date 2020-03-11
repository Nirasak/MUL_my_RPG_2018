/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** instance
*/

#include "my.h"

void clock_instance(map_t *map)
{
    map->inst.time = sfClock_getElapsedTime(map->inst.clock);
    map->inst.scd = map->inst.time.microseconds / 1000000.0f;
    map->inst.time_b = sfClock_getElapsedTime(map->inst.clock_b);
    map->inst.scd_b = map->inst.time_b.microseconds / 1000000.0f;
}

void zoom_instance(map_t *map)
{
    map->inst.x = map->inst.x / 2;
    map->inst.y = map->inst.y / 2;
    map->inst.size.x = map->inst.size.x * 2;
    map->inst.size.y = map->inst.size.y * 2;
    sfSprite_setOrigin(map->s_map, map->inst.zoom);
    sfSprite_setScale(map->s_map, map->inst.size);
    if (map->inst.size.x < 30) {
        map->inst.zoom.x = map->inst.zoom.x + map->inst.x;
        map->inst.zoom.y = map->inst.zoom.y + map->inst.y;
    }
    sfClock_restart(map->inst.clock);
}

void zoom_caitlyn(map_t *map)
{
    map->inst.x_cait = map->inst.x_cait / 2;
    map->inst.y_cait = map->inst.y_cait / 2;
    sfSprite_setOrigin(map->perso.s_perso, map->inst.zoom_cait);
    sfSprite_setScale(map->perso.s_perso, map->inst.size);
    if (map->inst.size.x < 30 / 2) {
        map->inst.zoom_cait.x = map->inst.zoom_cait.x + map->inst.x_cait;
        map->inst.zoom_cait.y = map->inst.zoom_cait.y + map->inst.y_cait;
    }
}

void black_instance(map_t *map)
{
    if (map->inst.r_black.left < 15360)
        map->inst.r_black.left = map->inst.r_black.left + 1920;
    sfSprite_setTextureRect(map->inst.s_black, map->inst.r_black);
    sfClock_restart(map->inst.clock_b);
}

void my_instance_fight(map_t *map, dwd_t *dwd)
{
    init_instance(map);
    while (sfRenderWindow_isOpen(dwd->window) && map->inst.size.x < 30) {
        clock_instance(map);
        if (map->inst.scd >= 0.15) {
            zoom_caitlyn(map);
            zoom_instance(map);
        }
        display_map(map, dwd);
        if (map->inst.scd_b >= 0.05)
            black_instance(map);
        sfRenderWindow_drawSprite(dwd->window, map->inst.s_black, NULL);
        sfRenderWindow_display(dwd->window);
    }
}
