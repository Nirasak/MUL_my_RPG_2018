/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** particules
*/

#include "my.h"

void init_rdm_explo(fight_t *map)
{
    map->explo = malloc(sizeof(explo_t) * 100);
    for (int i = 0; i < 99; i = i + 1) {
        map->explo[i].array = sfVertexArray_create();
        sfVertexArray_setPrimitiveType(map->explo[i].array, 4);
        map->explo[i].clock = sfClock_create();
        map->explo[i].scd = 3;
        map->explo[i].clock_part = sfClock_create();
        map->explo[i].scd_part = 5;
        map->explo[i].pos_a.x = 2000;
        map->explo[i].pos_a.y = 2000;
        map->explo[i].direct = 2;
        map->explo[i].x = 0;
        map->explo[i].y = 0;
    }
}

void set_pos_explo(sfVector2f pos, fight_t *map, sfColor color)
{
    for (int i = 0; i < 99; i = i + 1) {
        map->explo[i].x = rand() % 15 + 5;
        map->explo[i].y = rand() % (20 + map->explo[i].x - 5) + 0;
        map->explo[i].y = map->explo[i].y - 10 - (map->explo[i].x - 5) / 2;
        map->explo[i].pos_a.x = pos.x;
        map->explo[i].pos_a.y = pos.y;
        sfClock_restart(map->explo[i].clock_part);
        sfClock_restart(map->explo[i].clock);
        map->explo[i].color = color;
    }
}
