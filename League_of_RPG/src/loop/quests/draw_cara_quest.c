/*
** EPITECH PROJECT, 2019
** draw_cara_quest.c
** File description:
** draw my cara who gives quest
*/

#include "my.h"

void anime_garen(dwd_t *dwd)
{
    static sfTime time;
    static float sec;
    static sfIntRect rect = {0, 0, 200, 200};

    time = sfClock_getElapsedTime(dwd->quest.c_garen);
    sec = time.microseconds / 1000000.0;
    if (sec > 0.15) {
        rect.left = rect.left + 200;
        sfSprite_setTextureRect(dwd->quest.garen, rect);
        sfClock_restart(dwd->quest.c_garen);
        if (rect.left >= 1400)
            rect.left = 0;
    }
}

void anime_rammus(dwd_t *dwd)
{
    static sfTime time;
    static float sec;
    static sfIntRect rect = {0, 0, 375, 300};

    time = sfClock_getElapsedTime(dwd->quest.c_rammus);
    sec = time.microseconds / 1000000.0;
    if (sec > 0.2) {
        rect.left = rect.left + 375;
        sfSprite_setTextureRect(dwd->quest.rammus, rect);
        sfClock_restart(dwd->quest.c_rammus);
        if (rect.left >= 1875)
            rect.left = 0;
    }
}

void draw_cara_quest(dwd_t *dwd, fight_t *f)
{
    anime_rammus(dwd);
    anime_garen(dwd);
    sfRenderWindow_drawSprite(dwd->window, dwd->quest.garen, NULL);
    sfRenderWindow_drawSprite(dwd->window, dwd->quest.rammus, NULL);
    print_quest(dwd, f);
}
