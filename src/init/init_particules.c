/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** init particules
*/

#include "my.h"

void init_particules_bcl(map_t *map)
{
    for (int i = 0; i < 8; i = i + 1) {
        map->part[i].array = sfVertexArray_create();
        sfVertexArray_setPrimitiveType(map->part[i].array, 4);
        map->part[i].clock = sfClock_create();
        map->part[i].scd = 0;
        map->part[i].pos_b.x = map->part[i].pos_a.x;
        map->part[i].pos_b.y = map->part[i].pos_a.y;
        map->part[i].color = sfYellow;
        map->part[i].pos_c.y = map->part[i].pos_b.y + 8;
        map->part[i].pos_c.x = map->part[i].pos_b.x;
        map->part[i].pos_d.y = map->part[i].pos_b.y;
        map->part[i].pos_d.x = map->part[i].pos_b.x + 8;
        map->part[i].pos_e.y = map->part[i].pos_b.y + 8;
        map->part[i].pos_e.x = map->part[i].pos_b.x + 8;
    }
}

void init_particules_scd(map_t *map)
{
    map->part[0].pos_a.x = 1517;
    map->part[0].pos_a.y = 4;
    map->part[0].way = 0;
    map->part[1].pos_a.x = 1908;
    map->part[1].pos_a.y = 4;
    map->part[1].way = 1;
    map->part[2].pos_a.x = 1908;
    map->part[2].pos_a.y = 292;
    map->part[2].way = 2;
    map->part[3].pos_a.x = 1517;
    map->part[3].pos_a.y = 292;
    map->part[3].way = 3;
    map->part[4].pos_a.x = 1712;
    map->part[4].pos_a.y = 4;
    map->part[4].way = 0;
    map->part[5].pos_a.x = 1712;
    map->part[5].pos_a.y = 292;
    map->part[5].way = 2;
}

void init_particules(map_t *map)
{
    map->part = malloc(sizeof(part_t) * 8);
    init_particules_scd(map);
    map->part[6].pos_a.x = 1517;
    map->part[6].pos_a.y = 148;
    map->part[6].way = 3;
    map->part[7].pos_a.x = 1908;
    map->part[7].pos_a.y = 148;
    map->part[7].way = 1;
    init_particules_bcl(map);
}
