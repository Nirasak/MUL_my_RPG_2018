/*
** EPITECH PROJECT, 2019
** RPG
** File description:
** init_option
*/

#include "my.h"

static void init_more_option_sprite(dwd_t *dwd)
{
    dwd->option.bt_option = malloc(sizeof(sfSprite *) * 3);
    dwd->option.bt_option[0] = f_sprite_create
        ("BT_OPTION", dwd->menu.data, 1005, 313);
    dwd->option.bt_option[1] = f_sprite_create
        ("BT_OPTION", dwd->menu.data, 1480, 313);
    dwd->option.bt_option[2] = f_sprite_create
        ("BT_OPTION", dwd->menu.data, 1020, 613);
    dwd->option.f_cursor = f_sprite_create("CURS1", dwd->menu.data, 1250, 600);
    dwd->option.s_cursor = f_sprite_create("CURS2", dwd->menu.data, 1550, 615);
}

static void init_option_sprite(dwd_t *dwd)
{
    sfIntRect rect_fcursor = {123, 22, 57, 83};
    sfIntRect rect_scursor = {30, 30, 34, 34};
    sfIntRect rect_clicable = {0, 0, 38, 37};
    sfVector2f scl = {1.7, 1.7};
    sfVector2f scl2 = {1.3, 1.3};

    init_more_option_sprite(dwd);
    sfSprite_setTextureRect(dwd->option.f_cursor, rect_fcursor);
    sfSprite_setTextureRect(dwd->option.s_cursor, rect_scursor);
    sfSprite_setScale(dwd->option.s_cursor, scl);
    for (int i = 0; i < 3; i++) {
        sfSprite_setScale(dwd->option.bt_option[i], scl2);
        sfSprite_setTextureRect(dwd->option.bt_option[i], rect_clicable);
    }
}

static void init_pos_displayable(dwd_t *dwd)
{
    pos_text(dwd->option.option, 825, 135);
    pos_text(dwd->option.f_screen, 700, 275);
    pos_text(dwd->option.particle, 1250, 275);
    pos_text(dwd->option.qwerty, 700, 575);
    pos_text(dwd->option.music, 535, 370);
    pos_text(dwd->option.effect, 520, 470);
    pos_text(dwd->option.confirm_screen, 1015, 275);
    pos_text(dwd->option.confirm_particle, 1490, 275);
}

static void init_option_text(dwd_t *dwd)
{
    char *my_font = extract_string_value("font", dwd->menu.data);

    dwd->option.f_screen = create_button_text
        (my_font, "Full screen", 75, sfWhite);
    dwd->option.particle = create_button_text(my_font, "Particle", 75, sfWhite);
    dwd->option.music = create_button_text(my_font, "Music", 65, sfWhite);
    dwd->option.effect = create_button_text(my_font, "Effect", 65, sfWhite);
    dwd->option.qwerty = create_button_text(my_font, "Keybinding", 75, sfWhite);
    dwd->option.confirm_screen = create_button_text
        (my_font, "x", 75, sfRed);
    dwd->option.confirm_particle = create_button_text
        (my_font, "x", 75, sfRed);
    dwd->option.screen = extract_saved_value("fullscreen", dwd->menu.data);
    dwd->option.parti = extract_saved_value("particle", dwd->menu.data);
    dwd->option.option = create_button_text(my_font, "Option", 100, sfWhite);
}

void ini_option(dwd_t *dwd)
{
    init_option_sprite(dwd);
    init_option_text(dwd);
    init_pos_displayable(dwd);
    init_utils(dwd, 2, 7);
}
