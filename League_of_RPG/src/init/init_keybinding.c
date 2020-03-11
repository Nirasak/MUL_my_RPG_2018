/*
** EPITECH PROJECT, 2019
** RPG
** File description:
** init_keybinding
*/

#include "my.h"

static void pos_each_text(dwd_t *dwd)
{
    pos_text(dwd->option.key.keybinding, 755, 135);
    for (int i = 0; i != 4; i++)
        pos_text(dwd->option.key.text_key[i], 600, i * 100 + 300);
    for (int i = 4; i != 8; i++)
        pos_text(dwd->option.key.text_key[i], 950, (i - 4) * 100 + 300);
    for (int i = 8; i != 12; i++)
        pos_text(dwd->option.key.text_key[i], 1300, (i - 8) * 100 + 300);
}

static void init_each_text(dwd_t *dwd, char *my_font)
{
    dwd->option.key.text_key[0] = create_button_text
        (my_font, "up", 50, sfWhite);
    dwd->option.key.text_key[1] = create_button_text
        (my_font, "down", 50, sfWhite);
    dwd->option.key.text_key[2] = create_button_text
        (my_font, "left", 50, sfWhite);
    dwd->option.key.text_key[3] = create_button_text
        (my_font, "right", 50, sfWhite);
    dwd->option.key.text_key[4] = create_button_text
        (my_font, "spell1", 50, sfWhite);
    dwd->option.key.text_key[5] = create_button_text
        (my_font, "spell2", 50, sfWhite);
    dwd->option.key.text_key[6] = create_button_text
        (my_font, "spell3", 50, sfWhite);
    dwd->option.key.text_key[7] = create_button_text
        (my_font, "spell4", 50, sfWhite);
    dwd->option.key.text_key[8] = create_button_text
        (my_font, "heal", 50, sfWhite);
    dwd->option.key.text_key[9] = create_button_text
        (my_font, "shop", 50, sfWhite);
}

static void init_text_board(dwd_t *dwd)
{
    sfIntRect icon_rect = {0, 212, 72, 78};
    sfVector2f pos = {800, 300};
    sfIntRect rect = {0, 0, 300, 300};

    for (int i = 0; i != 12; i++) {
        dwd->option.key.key[i] = f_sprite_create
            ("KEY_BOARD", dwd->menu.data, 0, 0);
        sfSprite_setTextureRect(dwd->option.key.key[i], icon_rect);
        sfSprite_setPosition(dwd->option.key.key[i], pos);
        pos.y += 100;
        if (pos.y > 600) {
            pos.y = 300;
            pos.x += 350;
        }
    }
    dwd->option.key.champ_key = f_sprite_create
        ("CHAMP_KEY", dwd->menu.data, 215, 365);
    sfSprite_setTextureRect(dwd->option.key.champ_key, rect);
    dwd->option.key.clock_key = sfClock_create();
}

void init_keybinding(dwd_t *dwd)
{
    char *my_font = extract_string_value("font", dwd->menu.data);

    dwd->option.key.keybind = malloc(sizeof(char *) * 12);
    dwd->option.key.text_key = malloc(sizeof(sfText *) * 12);
    dwd->option.key.key_t = malloc(sizeof(sfText *) * 12);
    dwd->option.key.key = malloc(sizeof(sfSprite *) * 12);
    dwd->option.key.keybinding = create_button_text
        (my_font, "Keybinding", 100, sfWhite);
    dwd->option.key.text_key[10] = create_button_text
        (my_font, "quest", 50, sfWhite);
    dwd->option.key.text_key[11] = create_button_text
        (my_font, "instance", 50, sfWhite);
    init_each_text(dwd, my_font);
    pos_each_text(dwd);
    init_text_board(dwd);
    init_keys(dwd);
    dwd->option.key.is_clicked = -1;
}
