/*
** EPITECH PROJECT, 2019
** RPG
** File description:
** init_button_annex
*/

#include "my.h"

void scale_option(dwd_t *dwd)
{
    char *selected_font = extract_string_value("font", dwd->menu.data);
    sfIntRect rect = {0, 0, 310, 160};
    sfVector2f scl = {2.3, 2.3};
    sfVector2f scl2 = {1.5, 1.5};

    sfSprite_setScale(dwd->sound.music_bar, scl);
    sfSprite_setScale(dwd->sound.sound_bar, scl);
    sfSprite_setScale(dwd->sound.under_music, scl);
    sfSprite_setScale(dwd->sound.under_sound, scl);
    dwd->menu.button.map = f_sprite_create
        ("MAP", dwd->menu.data, 1400, 900);
    sfSprite_setScale(dwd->menu.button.map, scl2);
    sfSprite_setTextureRect(dwd->menu.button.map, rect);
    dwd->menu.button.map_t = create_button_text
        (selected_font, "Map", 125, sfWhite);
    pos_button_text(&dwd->menu.button.map_t, dwd->menu.button.map, "map");
}

void init_option(dwd_t *dwd)
{
    sfIntRect f_rect = {0, 0, 407, 19};
    sfIntRect s_rect = {0, 43, 407, 19};

    dwd->sound.music_bar = f_sprite_create
        ("MUSICBAR", dwd->menu.data, 700, 400);
    dwd->sound.sound_bar = f_sprite_create
        ("MUSICBAR", dwd->menu.data, 700, 500);
    dwd->sound.under_music = f_sprite_create
        ("MUSICBAR", dwd->menu.data, 700, 400);
    dwd->sound.under_sound = f_sprite_create
        ("MUSICBAR", dwd->menu.data, 700, 500);
    f_rect.width = dwd->sound.music_vol * 4.7;
    sfSprite_setTextureRect(dwd->sound.music_bar, f_rect);
    f_rect.width = dwd->sound.effect_vol * 4.7;
    sfSprite_setTextureRect(dwd->sound.sound_bar, f_rect);
    f_rect.width = 407;
    sfSprite_setTextureRect(dwd->sound.under_music, s_rect);
    sfSprite_setTextureRect(dwd->sound.under_sound, s_rect);
    scale_option(dwd);
}

void rect_icon(dwd_t *dwd)
{
    sfVector2f scl = {0.27, 0.27};
    sfVector2f scl2 = {0.5, 0.5};
    sfVector2f spe_scl = {0.47, 0.47};

    sfSprite_setScale(dwd->menu.profile.icon[0], scl);
    sfSprite_setScale(dwd->menu.profile.icon[1], scl);
    sfSprite_setScale(dwd->menu.profile.icon[2], scl);
    sfSprite_setScale(dwd->menu.profile.icon[3], scl);
    sfSprite_setScale(dwd->menu.profile.icon[4], scl);
    sfSprite_setScale(dwd->menu.profile.icon[5], spe_scl);
    sfSprite_setScale(dwd->menu.profile.acon[0], scl2);
    sfSprite_setScale(dwd->menu.profile.acon[1], scl2);
    sfSprite_setScale(dwd->menu.profile.acon[2], scl2);
    sfSprite_setScale(dwd->menu.profile.acon[3], scl2);
    sfSprite_setScale(dwd->menu.profile.acon[4], scl2);
    scl2.x = 0.9;
    scl2.y = 0.9;
    sfSprite_setScale(dwd->menu.profile.acon[5], scl2);
    pos_text(dwd->menu.profile.option, 530, 135);
    pos_text(dwd->menu.profile.which_icon, 235, 300);
}

static void more_init_icon(dwd_t *dwd)
{
    char *my_font = extract_string_value("font", dwd->menu.data);
    char *option_text = extract_string_value("icon?", dwd->menu.data);

    dwd->menu.profile.acon[0] = f_sprite_create
        ("ICON1", dwd->menu.data, 600, 325);
    dwd->menu.profile.acon[1] = f_sprite_create
        ("ICON2", dwd->menu.data, 1000, 325);
    dwd->menu.profile.acon[2] = f_sprite_create
        ("ICON3", dwd->menu.data, 1400, 325);
    dwd->menu.profile.acon[3] = f_sprite_create
        ("ICON4", dwd->menu.data, 600, 550);
    dwd->menu.profile.acon[4] = f_sprite_create
        ("ICON5", dwd->menu.data, 1000, 550);
    dwd->menu.profile.acon[5] = f_sprite_create
        ("ICON6", dwd->menu.data, 1400, 550);
    dwd->menu.profile.option = create_button_text
        (my_font, option_text, 100, sfWhite);
    dwd->menu.profile.which_icon = create_button_text
        (my_font, "Your icon", 75, sfWhite);
}

void init_profile_icon(dwd_t *dwd)
{
    dwd->menu.profile.icon = malloc(sizeof(sfSprite *) * 6);
    dwd->menu.profile.acon = malloc(sizeof(sfSprite *) * 6);
    dwd->menu.profile.icon[0] = f_sprite_create
        ("ICON1", dwd->menu.data, 1775, 50);
    dwd->menu.profile.icon[1] = f_sprite_create
        ("ICON2", dwd->menu.data, 1775, 50);
    dwd->menu.profile.icon[2] = f_sprite_create
        ("ICON3", dwd->menu.data, 1775, 50);
    dwd->menu.profile.icon[3] = f_sprite_create
        ("ICON4", dwd->menu.data, 1775, 50);
    dwd->menu.profile.icon[4] = f_sprite_create
        ("ICON5", dwd->menu.data, 1775, 50);
    dwd->menu.profile.icon[5] = f_sprite_create
        ("ICON6", dwd->menu.data, 1775, 50);
    dwd->menu.profile.current_icon = extract_saved_value
        ("icon", dwd->menu.data);
    more_init_icon(dwd);
    rect_icon(dwd);
}
