/*
** EPITECH PROJECT, 2019
** RPG
** File description:
** how_to_play
*/

#include "my.h"

static void act_more_button(dwd_t *dwd, sfIntRect *rect)
{
    if (active_button(dwd->menu.htp.back_bt, dwd->menu.htp.back_t,
        sfRed, dwd) == 1) {
        rect->left = 0;
        rect->top = 100;
        rect->width = 1920;
        rect->height = 1080;
        dwd->is_open = OPTION;
    }
}

static void act_button(dwd_t *dwd)
{
    static sfIntRect rect = {0, 100, 1920, 1080};

    if (active_button(dwd->menu.htp.next_bt, dwd->menu.htp.next_t,
        sfRed, dwd) == 1) {
        rect.left += 1920;
        if (rect.left > 3840)
            rect.left = 3840;
    }
    if (active_button(dwd->menu.htp.prev_bt, dwd->menu.htp.prev_t,
        sfRed, dwd) == 1) {
        rect.left -= 1920;
        if (rect.left < 0)
            rect.left = 0;
    }
    act_more_button(dwd, &rect);
    sfSprite_setTextureRect(dwd->menu.htp.board_htp, rect);
}

static void anime_htp_champ(dwd_t *dwd)
{
    static sfTime time;
    static float sec;
    static sfIntRect rect = {0, 0, 288, 288};

    time = sfClock_getElapsedTime(dwd->menu.htp.clock_htp);
    sec = time.microseconds / 1000000.0;
    if (sec > 0.06) {
        rect.left += 288;
        if (rect.left > 3240)
            rect.left = 0;
        sfSprite_setTextureRect(dwd->menu.htp.champ_htp, rect);
        sfClock_restart(dwd->menu.htp.clock_htp);
    }
    sfRenderWindow_drawSprite(dwd->window, dwd->menu.htp.champ_htp, NULL);
}

static void disp_all(dwd_t *dwd)
{
    sfIntRect rect = sfSprite_getTextureRect(dwd->menu.htp.board_htp);

    sfRenderWindow_drawSprite(dwd->window, dwd->menu.htp.board_htp, NULL);
    if (rect.left < 3840) {
        sfRenderWindow_drawSprite(dwd->window, dwd->menu.htp.next_bt, NULL);
        sfRenderWindow_drawText(dwd->window, dwd->menu.htp.next_t, NULL);
    }
    if (rect.left > 0) {
        sfRenderWindow_drawSprite(dwd->window, dwd->menu.htp.prev_bt, NULL);
        sfRenderWindow_drawText(dwd->window, dwd->menu.htp.prev_t, NULL);
    }
    sfRenderWindow_drawSprite(dwd->window, dwd->menu.htp.back_bt, NULL);
    sfRenderWindow_drawText(dwd->window, dwd->menu.htp.back_t, NULL);
    sfRenderWindow_drawText(dwd->window, dwd->menu.htp.text_htp, NULL);
    anime_htp_champ(dwd);
}

void main_htp(dwd_t *dwd)
{
    while (dwd->is_open == HTP) {
        while (sfRenderWindow_pollEvent(dwd->window, &dwd->event)) {
            mouse(dwd);
            act_button(dwd);
        }
        anime_menu(dwd);
        disp_all(dwd);
        disp_mouse(dwd);
        sfRenderWindow_display(dwd->window);
    }
}
