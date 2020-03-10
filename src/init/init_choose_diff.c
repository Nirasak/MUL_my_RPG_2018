/*
** EPITECH PROJECT, 2019
** RPG
** File description:
** init_choose_diff
*/

#include "my.h"

static void init_text(dwd_t *dwd)
{
    char *selected_font = extract_string_value("font", dwd->menu.data);

    dwd->menu.diff.easy_t = create_button_text
        (selected_font, "Easy", 125, sfWhite);
    dwd->menu.diff.medium_t = create_button_text
        (selected_font, "Medium", 125, sfWhite);
    dwd->menu.diff.hard_t = create_button_text
        (selected_font, "Hard", 125, sfWhite);
    pos_button_text(&dwd->menu.diff.easy_t, dwd->menu.diff.easy, "Easy");
    pos_button_text
        (&dwd->menu.diff.medium_t, dwd->menu.diff.medium, "Medium");
    pos_button_text(&dwd->menu.diff.hard_t, dwd->menu.diff.hard, "Easy");
}

void init_choose_diff(dwd_t *dwd)
{
    sfVector2f scl = {1.5, 1.5};
    sfIntRect rect = {0, 0, 310, 160};

    dwd->menu.diff.easy = f_sprite_create
        ("DIFF1", dwd->menu.data, 100, 540);
    dwd->menu.diff.medium = f_sprite_create
        ("DIFF2", dwd->menu.data, 700, 540);
    dwd->menu.diff.hard = f_sprite_create
        ("DIFF3", dwd->menu.data, 1300, 540);
    sfSprite_setScale(dwd->menu.diff.easy, scl);
    sfSprite_setScale(dwd->menu.diff.medium, scl);
    sfSprite_setScale(dwd->menu.diff.hard, scl);
    sfSprite_setTextureRect(dwd->menu.diff.easy, rect);
    sfSprite_setTextureRect(dwd->menu.diff.medium, rect);
    sfSprite_setTextureRect(dwd->menu.diff.hard, rect);
    init_text(dwd);
}
