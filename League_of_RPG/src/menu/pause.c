/*
** EPITECH PROJECT, 2019
** RPG
** File description:
** pause
*/

#include "my.h"

static void anime_pause_champ(dwd_t *dwd)
{
    static sfTime time;
    static float sec;
    static sfIntRect rect = {0, 0, 260, 288};

    time = sfClock_getElapsedTime(dwd->menu.pause.clock_pause);
    sec = time.microseconds / 1000000.0;
    if (sec > 0.08) {
        rect.left += 288;
        if (rect.left > 3260)
            rect.left = 0;
        sfSprite_setTextureRect(dwd->menu.pause.pause_champ, rect);
        sfClock_restart(dwd->menu.pause.clock_pause);
    }
    sfRenderWindow_drawSprite(dwd->window, dwd->menu.pause.pause_champ, NULL);
}

static void more_act_button(dwd_t *dwd, int prev_open)
{
    if (active_button(dwd->menu.pause.resume, dwd->menu.pause.resume_t,
        sfRed, dwd) == 1) {
        if (dwd->shop_back == SHOP) {
            dwd->is_open = SHOP;
            dwd->shop_back = LEAVE;
            return;
        }
        dwd->is_open = prev_open;
    }
    if (active_button(dwd->menu.pause.option, dwd->menu.pause.option_t,
        sfRed, dwd) == 1) {
        dwd->is_open = OPTION;
        dwd->last_open = PAUSE;
    }
}

static void act_button(dwd_t *dwd, int prev_open)
{
    more_act_button(dwd, prev_open);
    if (active_button(dwd->menu.pause.menu, dwd->menu.pause.menu_t,
        sfRed, dwd) == 1)
        dwd->is_open = MENU;
    if (active_button(dwd->menu.pause.leave, dwd->menu.pause.leave_t,
        sfRed, dwd) == 1) {
        dwd->is_open = LEAVE;
        sfRenderWindow_close(dwd->window);
    }
    if (dwd->event.type == sfEvtKeyReleased &&
        dwd->event.key.code == sfKeyEscape)
        dwd->is_open = dwd->last_open;
}

void display_pause(dwd_t *dwd)
{
    sfRenderWindow_drawSprite(dwd->window, dwd->menu.board, NULL);
    sfRenderWindow_drawSprite(dwd->window, dwd->menu.pause.resume, NULL);
    sfRenderWindow_drawSprite(dwd->window, dwd->menu.pause.option, NULL);
    sfRenderWindow_drawSprite(dwd->window, dwd->menu.pause.save, NULL);
    sfRenderWindow_drawSprite(dwd->window, dwd->menu.pause.menu, NULL);
    sfRenderWindow_drawSprite(dwd->window, dwd->menu.pause.leave, NULL);
    sfRenderWindow_drawText(dwd->window, dwd->menu.pause.resume_t, NULL);
    sfRenderWindow_drawText(dwd->window, dwd->menu.pause.option_t, NULL);
    sfRenderWindow_drawText(dwd->window, dwd->menu.pause.save_t, NULL);
    sfRenderWindow_drawText(dwd->window, dwd->menu.pause.menu_t, NULL);
    sfRenderWindow_drawText(dwd->window, dwd->menu.pause.leave_t, NULL);
    sfRenderWindow_drawText(dwd->window, dwd->menu.pause.pause, NULL);
}

void main_pause(dwd_t *dwd, fight_t *f)
{
    static int prev_open = 0;

    dwd->is_open == PAUSE ? prev_open = dwd->last_open : 0;
    while (dwd->is_open == PAUSE) {
        while (sfRenderWindow_pollEvent(dwd->window, &dwd->event)) {
            mouse(dwd);
            act_button(dwd, prev_open);
        }
        anime_menu(dwd);
        display_pause(dwd);
        anime_pause_champ(dwd);
        main_option(dwd, f);
        disp_mouse(dwd);
        sfRenderWindow_display(dwd->window);
    }
}
