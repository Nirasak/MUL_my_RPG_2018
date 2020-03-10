/*
** EPITECH PROJECT, 2019
** anime_fighters.c
** File description:
** anime all my game fighters
*/

#include "my.h"

void shot_detected(fight_t *f, int *i)
{
    f->spawn.shoot = 1;
    change_scale(f->cait.impact, 0.05, 0.05);
    *i = 1;
    sfMusic_play(f->cait.shot_sound);
    put_impact(f);
    f->cait.spe[7] = f->cait.spe[7] + 5;
}

void anime_cait(fight_t *f)
{
    static sfTime time;
    static float sec;
    static sfIntRect rect = {0, 0, 200, 200};
    static int i = 0;

    reduce_impact(f);
    time = sfClock_getElapsedTime(f->cait.clock);
    sec = time.microseconds / 1000000.0;
    if (sec > 0.09) {
        rect.left = rect.left + 200;
        sfSprite_setTextureRect(f->cait.sprite, rect);
        sfClock_restart(f->cait.clock);
        if (rect.left == 2200)
            shot_detected(f, &i);
        if (rect.left >= 2400)
            rect.left = 0;
    }
}

int anime_shot(fight_t *f, int *shot)
{
    static sfTime time;
    static float sec;
    static sfIntRect rect = {12900, 0, 400, 400};

    time = sfClock_getElapsedTime(f->cait.cshot);
    sec = time.microseconds / 1000000.0;
    if (sec > 0.04 && *shot == 1) {
        rect.left = rect.left + 400;
        sfSprite_setTextureRect(f->cait.shot, rect);
        sfClock_restart(f->cait.cshot);
        if (rect.left >= 13300)
            rect.left = 0;
        if (rect.left == 8800) {
            rect.left = 12900;
            *shot = 0;
            return (0);
        }
    }
    return (1);
}
