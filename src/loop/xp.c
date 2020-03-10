/*
** EPITECH PROJECT, 2019
** xp.c
** File description:
** create my xp for my cara
*/

#include "my.h"

int anime_lvlup(fight_t *f)
{
    static sfIntRect rect = {0, 0, 300, 300};
    static sfTime time;
    static float sec;

    time = sfClock_getElapsedTime(f->spell.clvlup);
    sec = time.microseconds / 1000000.0;
    if (sec > 0.07) {
        rect.left = rect.left + 300;
        sfSprite_setTextureRect(f->spell.lvlup, rect);
        sfClock_restart(f->spell.clvlup);
        if (rect.left >= 7200) {
            rect.left = 0;
            return (0);
        }
    }
    return (1);
}

void anime_xpbar(dwd_t *dwd, fight_t *f)
{
    static sfIntRect rect = {0, 0, 108, 29};
    static int i = 0;
    float live = f->cait.spe[7];
    float live2 = f->cait.spe[6] * 100;
    float result = 0;

    sfRenderWindow_drawSprite(dwd->window, f->cait.xp, NULL);
    sfRenderWindow_drawSprite(dwd->window, f->spell.lvlup, NULL);
    result = (live / live2) * 108;
    rect.width = (float)result;
    sfSprite_setTextureRect(f->cait.xp, rect);
    if (f->cait.spe[7] >= f->cait.spe[6] * 100) {
        i = 1;
    }
    if (i == 1)
        level_up(f, &i);
}

void level_up(fight_t *f, int *i)
{
    static int a = 0;
    int stock =  f->cait.spe[7] - f->cait.spe[6] * 100;

    if (a == 0) {
        sfMusic_play(f->cait.lvlup);
        f->cait.spe[0] = f->cait.spe[0] + 20;
        f->cait.spe[4] = f->cait.spe[4] + 2;
        f->cait.spe[5] = f->cait.spe[5] + 1;
        f->cait.spe[6] = f->cait.spe[6] + 1;
        stock >= 0 ? f->cait.spe[7] = stock : 0;
        f->cait.spe[9] = f->cait.spe[9] + 100;
        f->cait.spe[10] = f->cait.spe[10] + 100;
        a++;
    }
    if (anime_lvlup(f) == 0) {
        *i = 0;
        a = 0;
    }
}
