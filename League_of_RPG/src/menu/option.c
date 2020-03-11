/*
** EPITECH PROJECT, 2019
** RPG
** File description:
** option
*/

#include "my.h"

static void fill_data(dwd_t *dwd)
{
    if (active_button(dwd->menu.button.back, dwd->menu.button.back_t,
        sfRed, dwd) == 1) {
        modify_data(dwd, "mus.vol=", my_itoa(dwd->sound.music_vol));
        modify_data(dwd, "sound.vol=", my_itoa(dwd->sound.effect_vol));
        modify_data(dwd, "fullscreen=", my_itoa(dwd->option.screen));
        modify_data(dwd, "particle=", my_itoa(dwd->option.parti));
        modify_data(dwd, "curs=", my_itoa(dwd->mouse.which_mouse));
        modify_data(dwd, "background=", my_itoa(dwd->background));
        modify_data(dwd, "fps=", my_itoa(dwd->option.utils.fps_value));
        dwd->is_open = dwd->last_open;
    }
}

static void cond_activation_button(dwd_t *dwd)
{
    if (re_active_option_button(dwd->option.utils.bt_bg[0], dwd) == 1 &&
        dwd->background != 1 && dwd->is_open == OPTION) {
            sfMusic_play(dwd->sound.menu);
            dwd->background = 1;
    }
    if (re_active_option_button(dwd->option.utils.bt_bg[1], dwd) == 1 &&
        dwd->background != 2 && dwd->is_open == OPTION) {
            sfMusic_stop(dwd->sound.menu);
            dwd->background = 2;
    }
    if (push_small_button(dwd->option.htp, dwd, 240, 240) == 1)
        dwd->is_open = HTP;
}

static void more_activation_button(dwd_t *dwd)
{
    cond_activation_button(dwd);
    if (re_active_option_button(dwd->option.utils.bt_fps[0], dwd) == 1)
        dwd->option.utils.fps_value = 1;
    if (re_active_option_button(dwd->option.utils.bt_fps[1], dwd) == 1)
        dwd->option.utils.fps_value = 2;
    if (re_active_option_button(dwd->option.utils.bt_fps[2], dwd) == 1)
        dwd->option.utils.fps_value = 3;
    if (dwd->option.utils.fps_value == 1)
        sfRenderWindow_setFramerateLimit(dwd->window, 30);
    if (dwd->option.utils.fps_value == 2)
        sfRenderWindow_setFramerateLimit(dwd->window, 60);
    if (dwd->option.utils.fps_value == 3)
        sfRenderWindow_setFramerateLimit(dwd->window, 120);
}

static void act_button(dwd_t *dwd, fight_t *f)
{
    fill_data(dwd);
    active_option_button
        (dwd->option.bt_option[0], &dwd->option.screen, dwd);
    active_option_button
        (dwd->option.bt_option[1], &dwd->option.parti, dwd);
    if (re_active_option_button(dwd->option.bt_option[2], dwd) == 1)
        dwd->is_open = KEYBINDING;
    active_music_bar(dwd->sound.music_bar, dwd);
    active_sound_bar(dwd->sound.sound_bar, dwd, f);
    if (push_fcursor(dwd->option.f_cursor, dwd) == 1)
        dwd->mouse.which_mouse = 1;
    if (push_scursor(dwd->option.s_cursor, dwd) == 1)
        dwd->mouse.which_mouse = 2;
    more_activation_button(dwd);
}

void main_option(dwd_t *dwd, fight_t *f)
{
    while (dwd->is_open == OPTION || dwd->is_open == PAUSE_OPTION) {
        while (sfRenderWindow_pollEvent(dwd->window, &dwd->event)) {
            mouse(dwd);
            act_button(dwd, f);
        }
        anime_menu(dwd);
        draw_all(dwd);
        disp_mouse(dwd);
        main_htp(dwd);
        main_keybinding(dwd);
        sfRenderWindow_display(dwd->window);
    }
}
