/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** particules
*/

#include "my.h"

void clock_part(map_t *map, int i)
{
    map->part[i].time = sfClock_getElapsedTime(map->part[i].clock);
    map->part[i].scd = map->part[i].time.microseconds / 100000.0f;
    map->part[i].pos_c.y = map->part[i].pos_b.y + 8;
    map->part[i].pos_c.x = map->part[i].pos_b.x;
    map->part[i].pos_d.y = map->part[i].pos_b.y;
    map->part[i].pos_d.x = map->part[i].pos_b.x + 8;
    map->part[i].pos_e.y = map->part[i].pos_b.y + 8;
    map->part[i].pos_e.x = map->part[i].pos_b.x + 8;
}

void move_particules(map_t *map, int i)
{
    if (map->part[i].pos_b.x >= 1908 && map->part[i].pos_b.y <= 4)
        map->part[i].way = 1;
    if (map->part[i].pos_b.x >= 1908 && map->part[i].pos_b.y >= 292)
        map->part[i].way = 2;
    if (map->part[i].pos_b.x <= 1518 && map->part[i].pos_b.y >= 292)
        map->part[i].way = 3;
    if (map->part[i].pos_b.x <= 1518 && map->part[i].pos_b.y <= 4)
        map->part[i].way = 0;
    if (map->part[i].way == 0)
        map->part[i].pos_b.x = map->part[i].pos_b.x + 4;
    if (map->part[i].way == 1)
        map->part[i].pos_b.y = map->part[i].pos_b.y + 3;
    if (map->part[i].way == 2)
        map->part[i].pos_b.x = map->part[i].pos_b.x - 4;
    if (map->part[i].way == 3)
        map->part[i].pos_b.y = map->part[i].pos_b.y - 3;
    sfClock_restart(map->part[i].clock);
}

void set_vertex(map_t *map, int i)
{
    sfVector2f direct = {0, 0};
    sfVertex vertex = {map->part[i].pos_b, map->part[i].color, direct};
    sfVertex vertex2 = {map->part[i].pos_c, map->part[i].color, direct};
    sfVertex vertex3 = {map->part[i].pos_d, map->part[i].color, direct};
    sfVertex vertex4 = {map->part[i].pos_e, map->part[i].color, direct};

    sfVertexArray_append(map->part[i].array, vertex);
    sfVertexArray_append(map->part[i].array, vertex2);
    sfVertexArray_append(map->part[i].array, vertex3);
    sfVertexArray_append(map->part[i].array, vertex4);
}

void particules(map_t *map, dwd_t *dwd)
{
    for (int i = 0; i < 8; i = i + 1) {
        sfVertexArray_clear(map->part[i].array);
        if (map->part[i].scd > 0.06)
            move_particules(map, i);
        set_vertex(map, i);
        clock_part(map, i);
    }
    display_map(map, dwd);
    for (int i = 0; i < 8; i = i + 1)
        if (map->part[i].pos_b.y < 292 || map->part[i].pos_b.x <= 1620
            || map->part[i].pos_b.x >= 1808)
            sfRenderWindow_drawVertexArray(dwd->window,
                                            map->part[i].array, NULL);
}
