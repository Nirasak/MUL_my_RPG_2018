/*
** EPITECH PROJECT, 2019
** RPG
** File description:
** init_htp
*/

#include "my.h"

static void init_rect(dwd_t *dwd, char *my_font)
{
    sfIntRect rect = {0, 0, 310, 160};
    sfVector2f scl = {1.5, 1.5};

    sfSprite_setScale(dwd->menu.htp.next_bt, scl);
    sfSprite_setScale(dwd->menu.htp.prev_bt, scl);
    sfSprite_setScale(dwd->menu.htp.back_bt, scl);
    sfSprite_setTextureRect(dwd->menu.htp.next_bt, rect);
    sfSprite_setTextureRect(dwd->menu.htp.prev_bt, rect);
    sfSprite_setTextureRect(dwd->menu.htp.back_bt, rect);
    pos_button_text(&dwd->menu.htp.next_t, dwd->menu.htp.next_bt, "Next");
    pos_button_text(&dwd->menu.htp.prev_t, dwd->menu.htp.prev_bt, "Prev");
    pos_button_text(&dwd->menu.htp.back_t, dwd->menu.htp.back_bt, "Return");
    dwd->menu.htp.text_htp = create_button_text
        (my_font, "How to play", 100, sfWhite);
    pos_text(dwd->menu.htp.text_htp, 715, 90);
    dwd->menu.htp.clock_htp = sfClock_create();
    dwd->menu.htp.champ_htp = f_sprite_create
        ("CHAMP_HTP", dwd->menu.data, 210, 350);
}

void init_htp(dwd_t *dwd)
{
    sfIntRect rect = {0, 100, 1920, 1080};
    char *selected_font = extract_string_value("font", dwd->menu.data);

    dwd->menu.htp.next_bt = f_sprite_create
        ("NEXT", dwd->menu.data, 1450, 900);
    dwd->menu.htp.prev_bt = f_sprite_create
        ("PREV", dwd->menu.data, 50, 900);
    dwd->menu.htp.back_bt = f_sprite_create
        ("BACK2", dwd->menu.data, 750, 900);
    dwd->menu.htp.board_htp = f_sprite_create
        ("BOARD_HTP", dwd->menu.data, 0, 0);
    dwd->menu.htp.next_t = create_button_text
        (selected_font, "Next", 125, sfWhite);
    dwd->menu.htp.prev_t = create_button_text
        (selected_font, "Prev", 125, sfWhite);
    dwd->menu.htp.back_t = create_button_text
        (selected_font, "Return", 125, sfWhite);
    sfSprite_setTextureRect(dwd->menu.htp.board_htp, rect);
    init_rect(dwd, selected_font);
}
