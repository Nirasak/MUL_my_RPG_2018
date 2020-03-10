/*
** EPITECH PROJECT, 2019
** anime_mob_spawn.c
** File description:
** anime all my mob on my spawn
*/

#include "my.h"

void anime_poro(fight_t *f)
{
    static sfTime time;
    static float sec;
    static sfIntRect rect = {0, 0, 288, 288};

    time = sfClock_getElapsedTime(f->spawn.clock[0]);
    sec = time.microseconds / 1000000.0;
    if (sec > 0.1) {
        rect.left = rect.left + 288;
        sfSprite_setTextureRect(f->spawn.poro, rect);
        sfClock_restart(f->spawn.clock[0]);
        if (rect.left >= 3168)
            rect.left = 0;
    }
}

void anime_rporo(fight_t *f)
{
    static sfTime time;
    static float sec;
    static sfIntRect rect = {0, 0, 500, 500};

    time = sfClock_getElapsedTime(f->spawn.clock[1]);
    sec = time.microseconds / 1000000.0;
    if (sec > 0.1) {
        rect.left = rect.left + 500;
        sfSprite_setTextureRect(f->spawn.rporo, rect);
        sfClock_restart(f->spawn.clock[1]);
        if (rect.left >= 2500)
            rect.left = 0;
    }
}

void anime_tamo(fight_t *f)
{
    static sfTime time;
    static float sec;
    static sfIntRect rect = {0, 0, 1200, 1200};

    time = sfClock_getElapsedTime(f->spawn.clock[2]);
    sec = time.microseconds / 1000000.0;
    if (sec > 0.1) {
        rect.left = rect.left + 1200;
        sfSprite_setTextureRect(f->spawn.tamo, rect);
        sfClock_restart(f->spawn.clock[2]);
        if (rect.left >= 8400)
            rect.left = 0;
    }
}
