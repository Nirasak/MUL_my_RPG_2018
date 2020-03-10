/*
** EPITECH PROJECT, 2019
** RPG
** File description:
** init_button
*/

#include "my.h"

void annex_init_button_text(dwd_t *dwd, char *selected_font)
{
    sfVector2f scl = {1.5, 1.5};

    sfSprite_setScale(dwd->menu.button.play, scl);
    sfSprite_setScale(dwd->menu.button.lore, scl);
    sfSprite_setScale(dwd->menu.button.option, scl);
    sfSprite_setScale(dwd->menu.button.leave, scl);
    sfSprite_setScale(dwd->menu.button.back, scl);
    dwd->menu.button.confirm_t = create_button_text
        (selected_font, "Confirm", 125, sfWhite);
    pos_button_text
        (&dwd->menu.button.confirm_t, dwd->menu.button.confirm, "Confirm");
}

void init_button_text(dwd_t *dwd)
{
    char *selected_font = extract_string_value("font", dwd->menu.data);

    dwd->menu.button.play_t = create_button_text
        (selected_font, "Play", 125, sfWhite);
    dwd->menu.button.lore_t = create_button_text
        (selected_font, "Lore", 125, sfWhite);
    dwd->menu.button.option_t = create_button_text
        (selected_font, "Option", 125, sfWhite);
    dwd->menu.button.leave_t = create_button_text
        (selected_font, "Leave", 125, sfWhite);
    dwd->menu.button.back_t = create_button_text
        (selected_font, "Return", 125, sfWhite);
    pos_button_text(&dwd->menu.button.play_t, dwd->menu.button.play, "Play");
    pos_button_text(&dwd->menu.button.lore_t, dwd->menu.button.lore, "Lore");
    pos_button_text
        (&dwd->menu.button.option_t, dwd->menu.button.option, "Option");
    pos_button_text(&dwd->menu.button.leave_t, dwd->menu.button.leave, "Leave");
    pos_button_text(&dwd->menu.button.back_t, dwd->menu.button.back, "Return");
    annex_init_button_text(dwd, selected_font);
}

void init_rect(dwd_t *dwd)
{
    sfIntRect rect = {0, 0, 310, 160};
    sfIntRect profile_rect = {0, 0, 280, 126};
    sfIntRect name_rect = {0, 120, 187, 72};
    sfIntRect icon_rect = {0, 212, 72, 78};

    sfSprite_setTextureRect(dwd->menu.button.play, rect);
    sfSprite_setTextureRect(dwd->menu.button.lore, rect);
    sfSprite_setTextureRect(dwd->menu.button.option, rect);
    sfSprite_setTextureRect(dwd->menu.button.leave, rect);
    sfSprite_setTextureRect(dwd->menu.button.back, rect);
    sfSprite_setTextureRect(dwd->menu.button.confirm, rect);
    sfSprite_setTextureRect(dwd->menu.profile.profile_board, profile_rect);
    sfSprite_setTextureRect(dwd->menu.profile.name_board, name_rect);
    sfSprite_setTextureRect(dwd->menu.profile.icon_board, icon_rect);
}

void annex_init_button(dwd_t *dwd)
{
    sfVector2f scl = {1.5, 1.5};

    dwd->menu.button.confirm = f_sprite_create
        ("CONFIRM", dwd->menu.data, 715, 735);
    sfSprite_setScale(dwd->menu.button.confirm, scl);
    scl.x = 1.6;
    dwd->menu.profile.profile_board = f_sprite_create
        ("PROFILE", dwd->menu.data, 1450, 10);
    sfSprite_setScale(dwd->menu.profile.profile_board, scl);
    dwd->menu.profile.name_board = f_sprite_create
        ("PROFILE", dwd->menu.data, 1465, 30);
    sfSprite_setScale(dwd->menu.profile.name_board, scl);
    dwd->menu.profile.icon_board = f_sprite_create
        ("PROFILE", dwd->menu.data, 1760, 32);
    sfSprite_setScale(dwd->menu.profile.icon_board, scl);
}

void init_button(dwd_t *dwd)
{
    dwd->menu.button.bt_clicked = 0;
    dwd->menu.button.play = f_sprite_create
        ("PLAY", dwd->menu.data, 200, 100);
    dwd->menu.button.lore = f_sprite_create
        ("LORE", dwd->menu.data, 200, 350);
    dwd->menu.button.option = f_sprite_create
        ("OPTION", dwd->menu.data, 200, 600);
    dwd->menu.button.leave = f_sprite_create
        ("LEAVE", dwd->menu.data, 200, 850);
    dwd->menu.button.back = f_sprite_create
        ("BACK", dwd->menu.data, 850, 735);
    annex_init_button(dwd);
    init_profile_icon(dwd);
    init_rect(dwd);
    init_button_text(dwd);
}
