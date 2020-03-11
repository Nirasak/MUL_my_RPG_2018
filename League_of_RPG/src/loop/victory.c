/*
** EPITECH PROJECT, 2019
** victory.c
** File description:
** create my victory condition
*/

#include "my.h"

void victory_condi(dwd_t *dwd, fight_t *f)
{
    static sfTime time;
    static float sec;
    
    if (f->quest >= 12) {
        sfRenderWindow_drawSprite(dwd->window, f->report.victory, NULL);
        time = sfClock_getElapsedTime(f->spawn.clock[0]);
        sec = time.microseconds / 1000000.0;
        if (sec > 5) {
            dwd->is_open = LEAVE;
            sfRenderWindow_close(dwd->window);
        }
    }
}
