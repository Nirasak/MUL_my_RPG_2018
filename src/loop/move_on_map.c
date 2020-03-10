/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** moves on map
*/

#include "my.h"

void move_map_left(map_t *map, fight_t *f)
{
    map->perso.run = 4;
    if (map->perso.mvmt == 0) {
        map->perso.r_perso.left = 10;
        map->perso.r_perso.top = 577;
        map->perso.mvmt = 1;
    }
    if (map->scd >= 0.3
        && map->tab
        [(int)(map->perso.p_perso.y / 2 + map->origin.y + 315) / 10 + 1]
        [(int)(map->perso.p_perso.x / 2 + map->origin.x + 485) / 10 - 1]
        == '0') {
        if (map->origin.x <= 6)
            map->perso.p_perso.x = map->perso.p_perso.x - 3;
        if (map->perso.p_perso.x > 0)
            map->perso.p_perso.x = map->perso.p_perso.x - 3;
        if (map->perso.p_perso.x == 0)
            map->origin.x = map->origin.x - 0.6 - (float)f->cait.spe[3] / 333;
    }
    if (map->scd >= 0.3)
        sfClock_restart(map->clock);
}

void move_map_right(map_t *map, fight_t *f)
{
    map->perso.run = 2;
    if (map->perso.mvmt == 0) {
        map->perso.r_perso.left = 10;
        map->perso.r_perso.top = 10;
        map->perso.mvmt = 1;
    }
    if (map->scd >= 0.3
        && map->tab
        [(int)(map->perso.p_perso.y / 2 + map->origin.y + 315) / 10 + 1]
        [(int)(map->perso.p_perso.x / 2 + map->origin.x + 485) / 10 + 1]
        == '0') {
        if (map->origin.x >= 1395)
            map->perso.p_perso.x = map->perso.p_perso.x + 3;
        if (map->perso.p_perso.x < 0)
            map->perso.p_perso.x = map->perso.p_perso.x + 3;
        if (map->perso.p_perso.x == 0)
            map->origin.x = map->origin.x + 0.6 + (float)f->cait.spe[3] / 333;
    }
    if (map->scd >= 0.3)
        sfClock_restart(map->clock);
}

void move_map_up(map_t *map, fight_t *f)
{
    map->perso.run = 1;
    if (map->perso.mvmt == 0) {
        map->perso.r_perso.left = 10;
        map->perso.r_perso.top = 199;
        map->perso.mvmt = 1;
    }
    if (map->scd >= 0.3
        && map->tab
        [(int)(map->perso.p_perso.y / 2 + map->origin.y + 315) / 10]
        [(int)(map->perso.p_perso.x / 2 + map->origin.x + 485) / 10]
        == '0') {
        if (map->origin.y <= 5.5)
            map->perso.p_perso.y = map->perso.p_perso.y - 3;
        if (map->perso.p_perso.y > 0)
            map->perso.p_perso.y = map->perso.p_perso.y - 3;
        if (map->perso.p_perso.y == 0)
            map->origin.y = map->origin.y - 0.6 - (float)f->cait.spe[3] / 333;
    }
    if (map->scd >= 0.3)
        sfClock_restart(map->clock);
}

void move_map_down(map_t *map, fight_t *f)
{
    map->perso.run = 3;
    if (map->perso.mvmt == 0) {
        map->perso.r_perso.left = 10;
        map->perso.r_perso.top = 388;
        map->perso.mvmt = 1;
    }
    if (map->scd >= 0.3
        && map->tab
        [(int)(map->perso.p_perso.y / 2 + map->origin.y + 315) / 10 + 2]
        [(int)(map->perso.p_perso.x / 2 + map->origin.x + 485) / 10]
        == '0') {
        if (map->origin.y >= 1163)
            map->perso.p_perso.y = map->perso.p_perso.y + 3;
        if (map->perso.p_perso.y < 0)
            map->perso.p_perso.y = map->perso.p_perso.y + 3;
        if (map->perso.p_perso.y == 0)
            map->origin.y = map->origin.y + 0.6 + (float)f->cait.spe[3] / 333;
    }
    if (map->scd >= 0.3)
        sfClock_restart(map->clock);
}
