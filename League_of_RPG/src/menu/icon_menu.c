/*
** EPITECH PROJECT, 2019
** RPG
** File description:
** icon_menu
*/

#include "my.h"

static void activate_icon(dwd_t *dwd)
{
    sfVector2f scl = {0.27, 0.27};
    sfVector2f scl2 = {0.47, 0.47};
    sfVector2f pos = {1775, 50};

    for (int i = 0; i != 6; i++) {
        if (push_small_button(dwd->menu.profile.acon[i], dwd, 150, 150) == 1)
            dwd->menu.profile.current_icon = i;
    }
    if (active_button(dwd->menu.button.confirm, dwd->menu.button.confirm_t,
        sfRed, dwd) == 1) {
        for (int i = 0; i != 5; i++) {
            sfSprite_setScale(dwd->menu.profile.icon[i], scl);
            sfSprite_setPosition(dwd->menu.profile.icon[i], pos);
        }
        sfSprite_setScale(dwd->menu.profile.icon[5], scl2);
        sfSprite_setPosition(dwd->menu.profile.icon[5], pos);
        modify_data(dwd, "icon=", my_itoa(dwd->menu.profile.current_icon));
        update_saves(dwd);
        dwd->is_open = MENU;
    }
}

static void display_all(dwd_t *dwd)
{
    sfRenderWindow_drawSprite(dwd->window, dwd->menu.board, NULL);
    sfRenderWindow_drawSprite(dwd->window,
        dwd->menu.profile.icon[dwd->menu.profile.current_icon], NULL);
    for (int i = 0; i != 6; i++)
        sfRenderWindow_drawSprite
            (dwd->window, dwd->menu.profile.acon[i], NULL);
    sfRenderWindow_drawText(dwd->window, dwd->menu.profile.option, NULL);
    sfRenderWindow_drawText
        (dwd->window, dwd->menu.profile.which_icon, NULL);
    sfRenderWindow_drawSprite(dwd->window, dwd->menu.button.confirm, NULL);
    sfRenderWindow_drawText(dwd->window, dwd->menu.button.confirm_t, NULL);
}

void icon_menu(dwd_t *dwd)
{
    while (dwd->is_open == ICON) {
        while (sfRenderWindow_pollEvent(dwd->window, &dwd->event)) {
            mouse(dwd);
            activate_icon(dwd);
        }
        anime_menu(dwd);
        display_all(dwd);
        disp_mouse(dwd);
        sfRenderWindow_display(dwd->window);
    }
}
