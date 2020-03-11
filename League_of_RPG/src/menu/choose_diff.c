/*
** EPITECH PROJECT, 2019
** RPG
** File description:
** choose_dif
*/

#include "my.h"

static void act_button(dwd_t *dwd)
{
    if (active_button(dwd->menu.diff.easy, dwd->menu.diff.easy_t,
        sfRed, dwd) == 1) {
        dwd->is_open = GAME_MAP;
        dwd->menu.profile.difficulty = 1;
        sfClock_restart(dwd->clock_key);
    }
    if (active_button(dwd->menu.diff.medium, dwd->menu.diff.medium_t,
        sfRed, dwd) == 1) {
        dwd->is_open = GAME_MAP;
        dwd->menu.profile.difficulty = 2;
        sfClock_restart(dwd->clock_key);
    }
    if (active_button(dwd->menu.diff.hard, dwd->menu.diff.hard_t,
        sfRed, dwd) == 1) {
        dwd->is_open = GAME_MAP;
        dwd->menu.profile.difficulty = 3;
        sfClock_restart(dwd->clock_key);
    }
}

void choose_diff_menu(dwd_t *dwd)
{
    while (dwd->is_open == DIFFICULTY && dwd->menu.profile.played != 1) {
        while (sfRenderWindow_pollEvent(dwd->window, &dwd->event)) {
            act_button(dwd);
            mouse(dwd);
        }
        anime_menu(dwd);
        sfRenderWindow_drawSprite(dwd->window, dwd->menu.diff.easy, NULL);
        sfRenderWindow_drawSprite(dwd->window, dwd->menu.diff.medium, NULL);
        sfRenderWindow_drawSprite(dwd->window, dwd->menu.diff.hard, NULL);
        sfRenderWindow_drawText(dwd->window, dwd->menu.diff.easy_t, NULL);
        sfRenderWindow_drawText(dwd->window, dwd->menu.diff.medium_t, NULL);
        sfRenderWindow_drawText(dwd->window, dwd->menu.diff.hard_t, NULL);
        disp_mouse(dwd);
        sfRenderWindow_display(dwd->window);
    }
    if (dwd->is_open == DIFFICULTY)
        dwd->is_open = GAME_MAP;
}
