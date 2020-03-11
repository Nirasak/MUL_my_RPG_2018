/*
** EPITECH PROJECT, 2019
** RPG
** File description:
** annex for option
*/

#include "my.h"

static void last_init(dwd_t *dwd)
{
    char *my_font = extract_string_value("font", dwd->menu.data);

    dwd->option.htp = f_sprite_create
        ("BT_HTP", dwd->menu.data, 1400, 700);
    dwd->option.htp_t = create_button_text
        (my_font, "How to play", 50, sfRed);
    change_scale(dwd->option.htp, 0.3, 0.3);
    pos_text(dwd->option.htp_t, 1407.5, 780);
}

static void set_postion(dwd_t *dwd)
{
    pos_text(dwd->option.utils.background[0], 260, 380);
    pos_text(dwd->option.utils.fps[0], 300, 800);
    pos_text(dwd->option.utils.fps[1], 450, 875);
    pos_text(dwd->option.utils.fps[2], 550, 875);
    pos_text(dwd->option.utils.fps[3], 650, 875);
    pos_text(dwd->option.utils.background[1], 275, 463);
    pos_text(dwd->option.utils.background[2], 425, 463);
    pos_text(dwd->option.utils.fps[4], 460, 787);
    pos_text(dwd->option.utils.fps[5], 560, 787);
    pos_text(dwd->option.utils.fps[6], 660, 787);
    last_init(dwd);
}

static void another_more_utils(dwd_t *dwd, sfIntRect rect, sfVector2f scl)
{
    int k = 265;

    for (int i = 0; i != 2; i++, k += 150) {
        dwd->option.utils.bt_bg[i] = f_sprite_create
            ("BT_OPTION", dwd->menu.data, k, 500);
        sfSprite_setScale(dwd->option.utils.bt_bg[i], scl);
        sfSprite_setTextureRect(dwd->option.utils.bt_bg[i], rect);
    }
    k = 450;
    for (int i = 0; i != 3; i++, k += 100) {
        dwd->option.utils.bt_fps[i] = f_sprite_create
            ("BT_OPTION", dwd->menu.data, k, 825);
        sfSprite_setScale(dwd->option.utils.bt_fps[i], scl);
        sfSprite_setTextureRect(dwd->option.utils.bt_fps[i], rect);
    }
    dwd->background = extract_saved_value("background", dwd->menu.data);
    dwd->option.utils.fps_value = extract_saved_value("fps", dwd->menu.data);
}

static void more_init_utils(dwd_t *dwd, char *my_font)
{
    sfIntRect rect = {0, 0, 38, 37};
    sfVector2f scl = {1.3, 1.3};

    for (int i = 4; i != 7; i++)
        dwd->option.utils.fps[i] = create_button_text
            (my_font, "x", 75, sfRed);
    another_more_utils(dwd, rect, scl);
    set_postion(dwd);
}

void init_utils(dwd_t *dwd, int nb1, int nb2)
{
    char *my_font = extract_string_value("font", dwd->menu.data);

    dwd->option.utils.background = malloc(sizeof(sfText *) * (nb1 + 1));
    dwd->option.utils.fps = malloc(sizeof(sfText *) * (nb2 + 1));
    dwd->option.utils.bt_bg = malloc(sizeof(sfSprite *) * nb1);
    dwd->option.utils.bt_fps = malloc(sizeof(sfSprite *) * 3);
    dwd->option.utils.background[0] = create_button_text
        (my_font, "Background", 50, sfWhite);
    for (int i = 1; i != 3; i++)
        dwd->option.utils.background[i] = create_button_text
            (my_font, "x", 75, sfRed);
    dwd->option.utils.fps[0] = create_button_text
        (my_font, "FPS", 75, sfWhite);
    dwd->option.utils.fps[1] = create_button_text
        (my_font, "30", 50, sfWhite);
    dwd->option.utils.fps[2] = create_button_text
        (my_font, "60", 50, sfWhite);
    dwd->option.utils.fps[3] = create_button_text
        (my_font, "120", 50, sfWhite);
    more_init_utils(dwd, my_font);
}
