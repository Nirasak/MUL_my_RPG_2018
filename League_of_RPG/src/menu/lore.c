/*
** EPITECH PROJECT, 2019
** RPG
** File description:
** lore
*/

#include "my.h"

static void act_button(dwd_t *dwd)
{
    if (active_button(dwd->menu.button.back, dwd->menu.button.back_t,
        sfRed, dwd) == 1)
        dwd->is_open = MENU;
}

void anime_lore_champ(dwd_t *dwd)
{
    static sfTime time;
    static float sec;
    static sfIntRect rect = {0, 0, 260, 288};

    time = sfClock_getElapsedTime(dwd->menu.clock_lore);
    sec = time.microseconds / 1000000.0;
    if (sec > 0.06) {
        rect.left += 288;
        if (rect.left > 3240)
            rect.left = 0;
        sfSprite_setTextureRect(dwd->menu.lore_champ, rect);
        sfClock_restart(dwd->menu.clock_lore);
    }
    sfRenderWindow_drawSprite(dwd->window, dwd->menu.lore_champ, NULL);
}

void main_lore(dwd_t *dwd)
{
    while (dwd->is_open == LORE) {
        while (sfRenderWindow_pollEvent(dwd->window, &dwd->event)) {
            mouse(dwd);
            act_button(dwd);
        }
        anime_menu(dwd);
        sfRenderWindow_drawSprite(dwd->window, dwd->menu.board, NULL);
        sfRenderWindow_drawSprite(dwd->window, dwd->menu.button.back, NULL);
        sfRenderWindow_drawText(dwd->window, dwd->menu.button.back_t, NULL);
        for (int i = 0; dwd->menu.data_lore[i] != NULL; i++)
            sfRenderWindow_drawText(dwd->window, dwd->menu.lore[i], NULL);
        anime_lore_champ(dwd);
        disp_mouse(dwd);
        sfRenderWindow_display(dwd->window);
    }
}
