/*
** EPITECH PROJECT, 2019
** anime_menu.c
** File description:
** anime my menu
*/

#include "my.h"

void cond_anime_menu(dwd_t *dwd, int *loop)
{
    if (*loop != 3 && dwd->menu.rect_menu.left > 14000) {
        (*loop)++;
        dwd->menu.rect_menu.left = 0;
        dwd->menu.rect_menu.top += 1080;
        }
    if (*loop == 2 && dwd->menu.rect_menu.left > 12500) {
        *loop = 0;
        dwd->menu.rect_menu.left = 0;
        dwd->menu.rect_menu.top = 202;
    }
    if (*loop != 2 && dwd->menu.rect_menu.left < 14000)
        dwd->menu.rect_menu.left += 1200;
    if (*loop == 2 && dwd->menu.rect_menu.left < 12500)
        dwd->menu.rect_menu.left += 1200;
}

void anime_second_menu(dwd_t *dwd)
{
    static sfTime time;
    static float sec;

    if (dwd->background == 2) {
        time = sfClock_getElapsedTime(dwd->menu.clock2);
        sec = time.microseconds / 1000000.0;
        if (sec > 0.068) {
            dwd->menu.rect_menu2.left += 500;
            dwd->menu.rect_menu2.left > 15500 ?
                dwd->menu.rect_menu2.left = 0 : 0;
            sfSprite_setTextureRect(dwd->menu.menu2, dwd->menu.rect_menu2);
            sfClock_restart(dwd->menu.clock2);
        }
        sfRenderWindow_drawSprite(dwd->window, dwd->menu.menu2, NULL);
    }
}

void anime_menu(dwd_t *dwd)
{
    static sfTime time;
    static float sec;
    static int loop = 0;

    if (dwd->background == 1) {
        time = sfClock_getElapsedTime(dwd->menu.clock);
        sec = time.microseconds / 1000000.0;
        if (sec > 0.068) {
            cond_anime_menu(dwd, &loop);
            sfSprite_setTextureRect(dwd->menu.menu, dwd->menu.rect_menu);
            sfClock_restart(dwd->menu.clock);
        }
        sfRenderWindow_drawSprite(dwd->window, dwd->menu.menu, NULL);
    }
    anime_second_menu(dwd);
}
