/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** particules
*/

#include "my.h"

void clock_explo(fight_t *map, int i)
{
    map->explo[i].time = sfClock_getElapsedTime(map->explo[i].clock);
    map->explo[i].scd = map->explo[i].time.microseconds / 100000.0f;
    map->explo[i].time_part = sfClock_getElapsedTime(map->explo[i].clock_part);
    map->explo[i].scd_part = map->explo[i].time_part.microseconds / 100000.0f;
}

void move_explo(fight_t *map, int i)
{
    map->explo[i].pos_a.x = map->explo[i].pos_a.x - map->explo[i].x;
    map->explo[i].pos_a.y = map->explo[i].pos_a.y - map->explo[i].y;
    map->explo[i].pos_b.x = map->explo[i].pos_a.x + 2.5;
    map->explo[i].pos_b.y = map->explo[i].pos_a.y + 2.5;
    map->explo[i].pos_c.x = map->explo[i].pos_a.x - 2.5;
    map->explo[i].pos_c.y = map->explo[i].pos_a.y + 2.5;
    map->explo[i].pos_d.x = map->explo[i].pos_a.x + 0;
    map->explo[i].pos_d.y = map->explo[i].pos_a.y + 5;
    sfClock_restart(map->explo[i].clock);
}

void set_vertex_explo(fight_t *map, int i)
{
    sfVector2f direct = {0, 0};
    sfVertex vertex = {map->explo[i].pos_a, map->explo[i].color, direct};
    sfVertex vertex2 = {map->explo[i].pos_b, map->explo[i].color, direct};
    sfVertex vertex3 = {map->explo[i].pos_c, map->explo[i].color , direct};
    sfVertex vertex4 = {map->explo[i].pos_d, map->explo[i].color, direct};

    sfVertexArray_append(map->explo[i].array, vertex);
    sfVertexArray_append(map->explo[i].array, vertex2);
    sfVertexArray_append(map->explo[i].array, vertex3);
    sfVertexArray_append(map->explo[i].array, vertex4);
}

void explo_left(fight_t *map, sfRenderWindow *wdw)
{
    if (map->explo[0].direct != 0)
        return;
    for (int i = 0; i < 99; i = i + 1) {
        if (map->explo[i].scd > 0.1)
            move_explo(map, i);
        sfVertexArray_clear(map->explo[i].array);
        set_vertex_explo(map, i);
        clock_explo(map, i);
        if (map->explo[i].scd_part < 4 && map->explo[i].scd_part > 0.3)
            sfRenderWindow_drawVertexArray(wdw, map->explo[i].array, NULL);
    }
}

void explo_right(fight_t *map, sfRenderWindow *wdw)
{
    if (map->explo[0].direct != 1)
        return;
    for (int i = 0; i < 99; i = i + 1) {
        if (map->explo[i].x > 0)
            map->explo[i].x = -map->explo[i].x;
        if (map->explo[i].scd > 0.1)
            move_explo(map, i);
        sfVertexArray_clear(map->explo[i].array);
        set_vertex_explo(map, i);
        clock_explo(map, i);
        if (map->explo[i].scd_part < 4 && map->explo[i].scd_part > 0.2)
            sfRenderWindow_drawVertexArray(wdw, map->explo[i].array, NULL);
    }
}
