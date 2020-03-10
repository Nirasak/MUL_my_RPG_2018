/*
** EPITECH PROJECT, 2019
** RPG
** File description:
** display_option
*/

#include "my.h"

static void draw_utils(dwd_t *dwd)
{
    for (int i = 0; i != 3; i++)
        sfRenderWindow_drawSprite
            (dwd->window, dwd->option.utils.bt_fps[i], NULL);
    if (dwd->is_open == OPTION) {
        for (int i = 0; i != 2; i++)
            sfRenderWindow_drawSprite
                (dwd->window, dwd->option.utils.bt_bg[i], NULL);
        sfRenderWindow_drawText
            (dwd->window, dwd->option.utils.background[0], NULL);
        sfRenderWindow_drawText
            (dwd->window, dwd->option.utils.background[dwd->background], NULL);
    }
    for (int i = 0; i != 4; i++)
        sfRenderWindow_drawText
            (dwd->window, dwd->option.utils.fps[i], NULL);
    sfRenderWindow_drawText
        (dwd->window, dwd->option.utils.fps[dwd->option.utils.fps_value + 3],
        NULL);
}

static void draw_enable(dwd_t *dwd)
{
    if (dwd->option.screen == 1)
        sfRenderWindow_drawText
            (dwd->window, dwd->option.confirm_screen, NULL);
    if (dwd->option.parti == 1)
        sfRenderWindow_drawText
            (dwd->window, dwd->option.confirm_particle, NULL);
    sfRenderWindow_drawSprite(dwd->window, dwd->option.htp, NULL);
    sfRenderWindow_drawText(dwd->window, dwd->option.htp_t, NULL);
}

void draw_all(dwd_t *dwd)
{
    sfRenderWindow_drawSprite(dwd->window, dwd->menu.board, NULL);
    sfRenderWindow_drawSprite(dwd->window, dwd->sound.under_music, NULL);
    sfRenderWindow_drawSprite(dwd->window, dwd->sound.under_sound, NULL);
    sfRenderWindow_drawSprite(dwd->window, dwd->sound.music_bar, NULL);
    sfRenderWindow_drawSprite(dwd->window, dwd->sound.sound_bar, NULL);
    sfRenderWindow_drawSprite(dwd->window, dwd->menu.button.back, NULL);
    sfRenderWindow_drawText(dwd->window, dwd->menu.button.back_t, NULL);
    for (int i = 0; i < 3; i++)
        sfRenderWindow_drawSprite(dwd->window, dwd->option.bt_option[i], NULL);
    sfRenderWindow_drawText(dwd->window, dwd->option.f_screen, NULL);
    sfRenderWindow_drawText(dwd->window, dwd->option.particle, NULL);
    sfRenderWindow_drawText(dwd->window, dwd->option.music, NULL);
    sfRenderWindow_drawText(dwd->window, dwd->option.effect, NULL);
    sfRenderWindow_drawText(dwd->window, dwd->option.qwerty, NULL);
    draw_enable(dwd);
    sfRenderWindow_drawText(dwd->window, dwd->option.option, NULL);
    sfRenderWindow_drawSprite(dwd->window, dwd->option.f_cursor, NULL);
    sfRenderWindow_drawSprite(dwd->window, dwd->option.s_cursor, NULL);
    draw_utils(dwd);
}
