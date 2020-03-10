/*
** EPITECH PROJECT, 2019
** impact effect
** File description:
** handle my impact effect
*/

#include "my.h"

void reduce_impact(fight_t *f)
{
    static sfTime time;
    static float sec;
    static sfVector2f scl;

    scl = sfSprite_getScale(f->cait.impact);
    time = sfClock_getElapsedTime(f->cait.cimpact);
    sec = time.microseconds / 1000000.0;
    if (sec > 0.02 && scl.x > 0) {
        scl.x = scl.x - 0.002;
        scl.y = scl.y - 0.002;
        change_scale(f->cait.impact, scl.x, scl.y);
        sfClock_restart(f->cait.cimpact);
    }
}

void put_impact(fight_t *f)
{
    sfVector2f pos;
    int a = randomm(1, 4);

    if (a == 1) {
        pos.x = 1430;
        pos.y = 690;
    }
    if (a == 2) {
        pos.x = 1420;
        pos.y = 675;
    }
    if (a == 3) {
        pos.x = 1420;
        pos.y = 715;
    }
    if (a == 4) {
        pos.x = 1460;
        pos.y = 660;
    }
    sfSprite_setPosition(f->cait.impact, pos);
}
