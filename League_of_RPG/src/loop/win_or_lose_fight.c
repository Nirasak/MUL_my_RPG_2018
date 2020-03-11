/*
** EPITECH PROJECT, 2019
** win_or_lose_fight.c
** File description:
** check if i win or lose my fight
*/

#include "my.h"

void win_fight(dwd_t *dwd, fight_t *f, map_t *map)
{
    reset_shield(f);
    reset_cooldown(f);
    after_instance(map, dwd);
    f->quest = f->quest + 1;
    dwd->is_open = REPORT_FIGHT;
    f->report.success = 0;
    main_fight_report(dwd, f);
}

void lose_fight(dwd_t *dwd, fight_t *f, map_t *map)
{
    reset_shield(f);
    reset_cooldown(f);
    after_instance(map, dwd);
    map->origin.x = 5;
    map->origin.y = 1163;
    map->perso.p_perso.x = -360;
    map->perso.p_perso.y = 270;
    f->cait.spe[9] = f->cait.spe[10];
    dwd->is_open = REPORT_FIGHT;
    f->report.success = 1;
    main_fight_report(dwd, f);
}
