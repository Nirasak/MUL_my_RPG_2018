/*
** EPITECH PROJECT, 2019
** adapt_to_dificulty.c
** File description:
** adapt my monsters with my dificulty
*/

#include "my.h"

void addapt_to_difficult(dwd_t *dwd, fight_t *f)
{
    f->enemy.max_life = f->enemy.max_life * dwd->menu.profile.difficulty;
    f->enemy.attack = f->enemy.attack * dwd->menu.profile.difficulty;
    f->enemy.defense = f->enemy.defense * dwd->menu.profile.difficulty;
    f->enemy.actual_life = f->enemy.max_life;
}

