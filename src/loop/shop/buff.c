/*
** EPITECH PROJECT, 2019
** buff.c
** File description:
** create my buff
*/

#include "my.h"

void buff_dmg(fight_t *f, char *s)
{
    int i = my_atoi(s);

    f->cait.spe[0] = f->cait.spe[0] + i;
    sfText_setColor(f->spell.text[0], sfGreen);
}

void buff_lifesteal(fight_t *f, char *s)
{
    int i = my_atoi(s);

    f->cait.life_steal = i + f->cait.life_steal;
    if (f->cait.life_steal > 100)
        f->cait.life_steal = 100;
    sfText_setColor(f->spell.text[2], sfGreen);
}

void buff_popo(fight_t *f, char *s)
{
    int i = my_atoi(s);

    f->shop.life_popo = i;
}

void buff_speed(fight_t *f, char *s)
{
    int i = my_atoi(s);

    f->cait.spe[3] = f->cait.spe[3] + i;
    sfText_setColor(f->spell.text[3], sfGreen);
}
