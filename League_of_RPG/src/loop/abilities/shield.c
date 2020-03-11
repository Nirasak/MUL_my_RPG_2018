/*
** EPITECH PROJECT, 2019
** shield.c
** File description:
** buff shield.c
*/

#include "my.h"

void delete_buff_shield(fight_t *f, int *i)
{
    f->cait.spe[4] = f->cait.spe[4] - 30;
    sfText_setColor(f->spell.text[4], sfWhite);
    *i = 1;
}

void buff_shield(fight_t *f)
{
    f->cait.spe[4] = f->cait.spe[4] + 30;
    sfText_setColor(f->spell.text[4], sfGreen);
}

int anime_shield(fight_t *f)
{
    static sfTime time;
    static float sec;
    static sfIntRect rect = {0, 0, 190, 190};

    time = sfClock_getElapsedTime(f->spell.clock_espell);
    sec = time.microseconds / 1000000.0;
    if (sec > 0.12) {
        rect.left = rect.left + 190;
        sfSprite_setTextureRect(f->spell.espell, rect);
        sfClock_restart(f->spell.clock_espell);
        if (rect.left >= 3168) {
            buff_shield(f);
            rect.left = 0;
            return (0);
        }
    }
    return (1);
}

int third_spell(dwd_t *dwd, fight_t *f)
{
    sfRenderWindow_drawSprite(dwd->window, f->spell.espell, NULL);
    return (anime_shield(f));
}
