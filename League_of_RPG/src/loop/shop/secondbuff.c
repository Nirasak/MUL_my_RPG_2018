/*
** EPITECH PROJECT, 2019
** secondbuff.c
** File description:
** create my second buff function
*/

#include "my.h"

void buff_crit(fight_t *f, char *s)
{
    int i = my_atoi(s);

    if (f->cait.spe[1] < 100)
        f->cait.spe[1] = f->cait.spe[1] + i;
    if (f->cait.spe[1] > 100)
        f->cait.spe[1] = 100;
    sfText_setColor(f->spell.text[1], sfGreen);
}

void buff_extra_turn(fight_t *f, char *s)
{
    int i = my_atoi(s);

    if (f->cait.spe[2] < 100)
        f->cait.spe[2] = f->cait.spe[2] + i;
    sfText_setColor(f->spell.text[2], sfGreen);
}
