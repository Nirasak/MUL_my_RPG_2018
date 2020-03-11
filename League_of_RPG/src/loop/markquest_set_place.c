/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** set place questmark
*/

#include "my.h"

void markquest_setplace(dwd_t *dwd, int x, int y)
{
    dwd->quest.p_excla.x = x;
    dwd->quest.p_excla.y = y;
    dwd->quest.p_inter.x = x;
    dwd->quest.p_inter.y = y;
    sfSprite_setPosition(dwd->quest.s_excla, dwd->quest.p_excla);
    sfSprite_setPosition(dwd->quest.s_inter, dwd->quest.p_inter);
}
