/*
** EPITECH PROJECT, 2019
** karma.c
** File description:
** handle my karma on shop
*/

#include "my.h"

void anime_karma(fight_t *f)
{
    static sfTime time;
    static float sec;
    static sfIntRect rect = {0, 0, 583, 800};

    time = sfClock_getElapsedTime(f->shop.clock_karma);
    sec = time.microseconds / 1000000.0;
    if (sec > 0.08) {
        rect.left = rect.left + 583;
        sfSprite_setTextureRect(f->shop.karma, rect);
        sfClock_restart(f->shop.clock_karma);
        if (rect.left >= 13992)
            rect.left = 0;
    }
}

void anime_gnar(fight_t *f)
{
    static sfTime time;
    static float sec;
    static sfIntRect rect = {0, 0, 400, 300};

    time = sfClock_getElapsedTime(f->shop.clock_gnar);
    sec = time.microseconds / 1000000.0;
    if (sec > 0.1) {
        rect.left = rect.left + 400;
        sfSprite_setTextureRect(f->shop.gnar, rect);
        sfClock_restart(f->shop.clock_gnar);
        if (rect.left >= 7200)
            rect.left = -400;
    }
}
