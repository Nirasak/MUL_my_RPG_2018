/*
** EPITECH PROJECT, 2019
** decrease_cooldown.c
** File description:
** decrease all my cooldown
*/

#include "my.h"

void decrease_cooldown(fight_t *f)
{
    if (f->spell.cooldown[0] > 0)
        f->spell.cooldown[0] = f->spell.cooldown[0] - 1;
    if (f->spell.cooldown[1] > 0)
        f->spell.cooldown[1] = f->spell.cooldown[1] - 1;
    if (f->spell.cooldown[2] > 0)
        f->spell.cooldown[2] = f->spell.cooldown[2] - 1;
    if (f->spell.cooldown[3] > 0)
        f->spell.cooldown[3] = f->spell.cooldown[3] - 1;
    if (f->spell.cooldown[4] > 0)
        f->spell.cooldown[4] = f->spell.cooldown[4] - 1;
}

void decrease_when_qspell(fight_t *f)
{
    if (f->spell.cooldown[1] > 0)
        f->spell.cooldown[1] = f->spell.cooldown[1] - 1;
    if (f->spell.cooldown[2] > 0)
        f->spell.cooldown[2] = f->spell.cooldown[2] - 1;
    if (f->spell.cooldown[3] > 0)
        f->spell.cooldown[3] = f->spell.cooldown[3] - 1;
    if (f->spell.cooldown[4] > 0)
        f->spell.cooldown[4] = f->spell.cooldown[4] - 1;
}

void decrease_when_zspell(fight_t *f)
{
    if (f->spell.cooldown[0] > 0)
        f->spell.cooldown[0] = f->spell.cooldown[0] - 1;
    if (f->spell.cooldown[2] > 0)
        f->spell.cooldown[2] = f->spell.cooldown[2] - 1;
    if (f->spell.cooldown[3] > 0)
        f->spell.cooldown[3] = f->spell.cooldown[3] - 1;
    if (f->spell.cooldown[4] > 0)
        f->spell.cooldown[4] = f->spell.cooldown[4] - 1;
}

void decrease_when_espell(fight_t *f)
{
    if (f->spell.cooldown[1] > 0)
        f->spell.cooldown[1] = f->spell.cooldown[1] - 1;
    if (f->spell.cooldown[0] > 0)
        f->spell.cooldown[0] = f->spell.cooldown[0] - 1;
    if (f->spell.cooldown[3] > 0)
        f->spell.cooldown[3] = f->spell.cooldown[3] - 1;
    if (f->spell.cooldown[4] > 0)
        f->spell.cooldown[4] = f->spell.cooldown[4] - 1;
}

void decrease_when_rspell(fight_t *f)
{
    if (f->spell.cooldown[1] > 0)
        f->spell.cooldown[1] = f->spell.cooldown[1] - 1;
    if (f->spell.cooldown[2] > 0)
        f->spell.cooldown[2] = f->spell.cooldown[2] - 1;
    if (f->spell.cooldown[0] > 0)
        f->spell.cooldown[0] = f->spell.cooldown[0] - 1;
    if (f->spell.cooldown[4] > 0)
        f->spell.cooldown[4] = f->spell.cooldown[4] - 1;
}
