/*
** EPITECH PROJECT, 2019
** caitlyn_fight.c
** File description:
** create all loop functionfor cait
*/

#include "my.h"

void attack(fight_t *f, sfIntRect *rect, int *i)
{
    static sfTime time;
    static float sec;
    static int left = 2000;

    if (*i == 1) {
        rect->left = left;
        *i = 2;
    }
    time = sfClock_getElapsedTime(f->cait.clock);
    sec = time.microseconds / 1000000.0;
    if (sec > 0.09 && *i != 0) {
        rect->left = rect->left + 200;
        sfClock_restart(f->cait.clock);
        if (rect->left >= 2600)
            rect->left = 0;
        if (rect->left == 1800)
            *i = 0;
    }
}

void wait_loop(fight_t *f)
{
    static sfTime time;
    static float sec;
    static sfIntRect rect;
    static int reset = 0;

    rect = sfSprite_getTextureRect(f->cait.sprite);
    time = sfClock_getElapsedTime(f->cait.clock);
    sec = time.microseconds / 1000000.0;
    if (sec > 0.13 && reset == 0) {
        rect.left = rect.left + 200;
        sfClock_restart(f->cait.clock);
        rect.left >= 2200 ? reset = 1 : 0;
    }
    if (sec > 0.13 && reset == 1) {
        rect.left = rect.left - 200;
        sfClock_restart(f->cait.clock);
        rect.left <= 0 ? reset = 0 : 0;
    }
    sfSprite_setTextureRect(f->cait.sprite, rect);
}

void wait(fight_t *f, sfIntRect *rect)
{
    static sfTime time;
    static float sec;
    static int reset = 0;

    time = sfClock_getElapsedTime(f->cait.clock);
    sec = time.microseconds / 1000000.0;
    if (sec > 0.13 && reset == 0) {
        rect->left = rect->left + 200;
        sfClock_restart(f->cait.clock);
        if (rect->left >= 2200)
            reset = 1;
    }
    if (sec > 0.13 && reset == 1) {
        rect->left = rect->left - 200;
        sfClock_restart(f->cait.clock);
        if (rect->left <= 0)
            reset = 0;
    }
}

void shot(fight_t *f)
{
    static int i = 0;

    if (i == 0)
        sfMusic_play(f->cait.shot_sound);
    handle_shoot(f, f->cait.spe[0] - f->enemy.defense, &f->enemy.actual_life);
}

int normal_attack(dwd_t *dwd, fight_t *f)
{
    static sfIntRect rect;
    static int i = 0;
    static int shoti = 0;

    rect = sfSprite_getTextureRect(f->cait.sprite);
    if (dwd->event.type == sfEvtMouseButtonPressed
        && (check_mouse_in_rect(dwd, f) == 0)) {
        i == 0 ? put_text_on_enemy(f) : 0;
        i++;
    }
    i == 0 ? wait(f, &rect) : 0;
    attack(f, &rect, &i);
    if (rect.left == 2200) {
        shoti == 0 ? shot(f) : 0;
        shoti = 1;
    }
    sfSprite_setTextureRect(f->cait.sprite, rect);
    return (anime_shot(f, &shoti));
}
