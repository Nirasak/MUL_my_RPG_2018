/*
** EPITECH PROJECT, 2019
** RPG
** File description:
** menu
*/

#include "my.h"

static void scale_icon(dwd_t *dwd)
{
    sfVector2f pos = {285, 425};
    sfVector2f scl = {0.5, 0.5};

    for (int i = 0; i != 5; i++) {
        sfSprite_setScale(dwd->menu.profile.icon[i], scl);
        sfSprite_setPosition(dwd->menu.profile.icon[i], pos);
    }
    scl.x = 0.9;
    scl.y = 0.9;
    sfSprite_setScale(dwd->menu.profile.icon[5], scl);
    sfSprite_setPosition(dwd->menu.profile.icon[5], pos);
}

static void display_menu_button(dwd_t *dwd)
{
    sfRenderWindow_drawSprite(dwd->window, dwd->menu.button.play, NULL);
    sfRenderWindow_drawSprite(dwd->window, dwd->menu.button.lore, NULL);
    sfRenderWindow_drawSprite(dwd->window, dwd->menu.button.option, NULL);
    sfRenderWindow_drawSprite(dwd->window, dwd->menu.button.leave, NULL);
    sfRenderWindow_drawSprite
        (dwd->window, dwd->menu.profile.profile_board, NULL);
    sfRenderWindow_drawSprite(dwd->window, dwd->menu.profile.name_board, NULL);
    sfRenderWindow_drawSprite(dwd->window, dwd->menu.profile.icon_board, NULL);
    sfRenderWindow_drawSprite(dwd->window,
        dwd->menu.profile.icon[dwd->menu.profile.current_icon], NULL);
    sfRenderWindow_drawText(dwd->window, dwd->menu.button.play_t, NULL);
    sfRenderWindow_drawText(dwd->window, dwd->menu.button.lore_t, NULL);
    sfRenderWindow_drawText(dwd->window, dwd->menu.button.option_t, NULL);
    sfRenderWindow_drawText(dwd->window, dwd->menu.button.leave_t, NULL);
    sfRenderWindow_drawText(dwd->window, dwd->pseudo_t, NULL);
}

static void more_action(dwd_t *dwd)
{
    if (active_button(dwd->menu.button.leave, dwd->menu.button.leave_t,
        sfRed, dwd) == 1) {
        dwd->is_open = LEAVE;
        sfRenderWindow_close(dwd->window);
    }
    if (push_small_button(dwd->menu.profile.icon
        [dwd->menu.profile.current_icon], dwd, 80, 80) == 1) {
        dwd->is_open = ICON;
        scale_icon(dwd);
    }
    if (push_small_button(dwd->menu.profile.name_board, dwd, 285, 100) == 1)
        dwd->is_open = NEW_PROF;
}

static void act_button(dwd_t *dwd, map_t *map)
{
    if (active_button(dwd->menu.button.play, dwd->menu.button.play_t,
        sfRed, dwd) == 1) {
        dwd->is_open = DIFFICULTY;
        reini_instance_before(map);
        reinit_instance(map);
        sfClock_restart(dwd->clock_key);
    }
    if (active_button(dwd->menu.button.lore, dwd->menu.button.lore_t,
        sfRed, dwd))
        dwd->is_open = LORE;
    if (active_button
        (dwd->menu.button.option, dwd->menu.button.option_t, sfRed, dwd) == 1) {
        dwd->is_open = OPTION;
        dwd->last_open = MENU;
    }
    more_action(dwd);
}

void main_menu(dwd_t *dwd, fight_t *f, map_t *map)
{
    init_before_menu(dwd);
    while (dwd->is_open == MENU) {
        anime_menu(dwd);
        display_menu_button(dwd);
        while (sfRenderWindow_pollEvent(dwd->window, &dwd->event)) {
            act_button(dwd, map);
            mouse(dwd);
        }
        disp_mouse(dwd);
        main_option(dwd, f);
        main_lore(dwd);
        icon_menu(dwd);
        main_changement_profile(dwd);
        choose_diff_menu(dwd);
        sfRenderWindow_display(dwd->window);
    }
}
