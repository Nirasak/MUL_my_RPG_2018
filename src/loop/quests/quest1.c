/*
** EPITECH PROJECT, 2019
** quest1.c
** File description:
** create my first quest
*/

#include "my.h"

void init_quest_four(map_t *map, fight_t *f, int *i)
{
    if (f->quest == 8 && *i == 8) {
        change_enemy(f, check_enemy(f));
        map->p_markmin.x = 1565;
        map->p_markmin.y = 255;
        map->p_mark.x = -120;
        map->p_mark.y = 2565;
        *i = 9;
    }
    if (f->quest == 10 && *i == 9) {
        change_enemy(f, "VEIGAR");
        map->p_markmin.x = 1815;
        map->p_markmin.y = 50;
        map->p_mark.x = 2850;
        map->p_mark.y = 220;
        *i = 10;
    }
}

void init_quest_three(map_t *map, fight_t *f, int *i)
{
    if (f->quest == 6 && *i == 7) {
        change_enemy(f, check_enemy(f));
        map->p_markmin.x = 1822;
        map->p_markmin.y = 225;
        map->p_mark.x = 2970;
        map->p_mark.y = 2200;
        *i = 12;
    }
    if (f->quest == 7 && *i == 12) {
        change_enemy(f, check_enemy(f));
        map->p_markmin.x = 1660;
        map->p_markmin.y = 90;
        map->p_mark.x = 1040;
        map->p_mark.y = 540;
        *i = 8;
    }
}

void init_quest_two(map_t *map, fight_t *f, int *i)
{
    if (f->quest == 4 && *i == 4) {
        change_enemy(f, check_enemy(f));
        map->p_markmin.x = 1710;
        map->p_markmin.y = 172;
        map->p_mark.x = 1610;
        map->p_mark.y = 1600;
        *i = 5;
    }
    if (f->quest == 5 && *i == 5) {
        change_enemy(f, check_enemy(f));
        map->p_markmin.x = 1765;
        map->p_markmin.y = 192;
        map->p_mark.x = 2310;
        map->p_mark.y = 1795;
        *i = 7;
    }
}

void init_quest_five(map_t *map, fight_t *f, int *i)
{
    if (f->quest == 11 && *i == 10) {
        map->p_markmin.x = 1565;
        map->p_markmin.y = 255;
        map->p_mark.x = -120;
        map->p_mark.y = 2565;
        *i = 11;
    }
    init_quest_two(map, f, i);
    init_quest_three(map, f, i);
    init_quest_four(map, f, i);
}

void init_quest_one(map_t *map, fight_t *f)
{
    static int i = 0;

    if (f->quest == 0.5 && i == 0) {
        map->p_markmin.x = 1565;
        map->p_markmin.y = 255;
        map->p_mark.x = -120;
        map->p_mark.y = 2565;
        i = 2;
    }
    if (f->quest == 3 && i == 2) {
        change_enemy(f, check_enemy(f));
        map->p_markmin.x = 1822;
        map->p_markmin.y = 225;
        map->p_mark.x = 2970;
        map->p_mark.y = 2200;
        i = 4;
    }
    init_quest_five(map, f, &i);
}
