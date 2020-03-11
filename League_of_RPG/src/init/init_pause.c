/*
** EPITECH PROJECT, 2019
** RPG
** File description:
** init_pause
*/

#include "my.h"

static void init_champ_sprite(dwd_t *dwd)
{
    sfIntRect rect = {0, 0, 300, 300};

    dwd->menu.pause.clock_pause = sfClock_create();
    dwd->menu.pause.pause_champ = f_sprite_create
        ("CHAMP_PAUSE", dwd->menu.data, 215, 325);
    sfSprite_setTextureRect(dwd->menu.pause.pause_champ, rect);
}

static void init_pos_text(dwd_t *dwd)
{
    pos_button_text
        (&dwd->menu.pause.resume_t, dwd->menu.pause.resume, "Resume");
    pos_button_text
        (&dwd->menu.pause.option_t, dwd->menu.pause.option, "Option");
    pos_button_text(&dwd->menu.pause.save_t, dwd->menu.pause.save, "Save");
    pos_button_text(&dwd->menu.pause.menu_t, dwd->menu.pause.menu, "Menu");
    pos_button_text(&dwd->menu.pause.leave_t, dwd->menu.pause.leave, "Leave");
}

static void init_text_and_rect(dwd_t *dwd)
{
    char *my_font = extract_string_value("font", dwd->menu.data);
    sfIntRect rect = {0, 0, 310, 160};

    dwd->menu.pause.pause = create_button_text(my_font, "Pause", 100, sfWhite);
    pos_text(dwd->menu.pause.pause, 950, 140);
    dwd->menu.pause.resume_t = create_button_text
        (my_font, "Resume", 125, sfWhite);
    dwd->menu.pause.option_t = create_button_text
        (my_font, "Option", 125, sfWhite);
    dwd->menu.pause.save_t = create_button_text
        (my_font, "Save", 125, sfWhite);
    dwd->menu.pause.menu_t = create_button_text
        (my_font, "Menu", 125, sfWhite);
    dwd->menu.pause.leave_t = create_button_text
        (my_font, "Leave", 125, sfWhite);
    sfSprite_setTextureRect(dwd->menu.pause.resume, rect);
    sfSprite_setTextureRect(dwd->menu.pause.option, rect);
    sfSprite_setTextureRect(dwd->menu.pause.save, rect);
    sfSprite_setTextureRect(dwd->menu.pause.menu, rect);
    sfSprite_setTextureRect(dwd->menu.pause.leave, rect);
}

void init_pause(dwd_t *dwd)
{
    sfVector2f scl = {1.5, 1.5};

    dwd->menu.pause.resume = f_sprite_create
        ("RESUME", dwd->menu.data, 550, 300);
    dwd->menu.pause.option = f_sprite_create
        ("OPTION_PAUSE", dwd->menu.data, 1150, 300);
    dwd->menu.pause.save = f_sprite_create
        ("SAVE", dwd->menu.data, 825, 500);
    dwd->menu.pause.menu = f_sprite_create
        ("MENU_PAUSE", dwd->menu.data, 550, 700);
    dwd->menu.pause.leave = f_sprite_create
        ("LEAVE_PAUSE", dwd->menu.data, 1150, 700);
    sfSprite_setScale(dwd->menu.pause.resume, scl);
    sfSprite_setScale(dwd->menu.pause.option, scl);
    sfSprite_setScale(dwd->menu.pause.save, scl);
    sfSprite_setScale(dwd->menu.pause.menu, scl);
    sfSprite_setScale(dwd->menu.pause.leave, scl);
    init_text_and_rect(dwd);
    init_pos_text(dwd);
    init_champ_sprite(dwd);
}
