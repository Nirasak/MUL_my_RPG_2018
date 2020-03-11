/*
** EPITECH PROJECT, 2019
** reset_cooldown.c
** File description:
** reset all my cooldowns
*/

#include "my.h"

void reset_cooldown(fight_t *f)
{
    f->spell.cooldown[0] = 0;
    f->spell.cooldown[1] = 0;
    f->spell.cooldown[2] = 0;
    f->spell.cooldown[3] = 0;
    f->spell.cooldown[4] = 0;
}

void decrease_when_popo(fight_t *f)
{
    if (f->spell.cooldown[1] > 0)
        f->spell.cooldown[1] = f->spell.cooldown[1] - 1;
    if (f->spell.cooldown[0] > 0)
        f->spell.cooldown[0] = f->spell.cooldown[0] - 1;
    if (f->spell.cooldown[3] > 0)
        f->spell.cooldown[3] = f->spell.cooldown[3] - 1;
    if (f->spell.cooldown[2] > 0)
        f->spell.cooldown[2] = f->spell.cooldown[2] - 1;
}
