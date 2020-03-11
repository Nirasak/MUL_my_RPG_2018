/*
** EPITECH PROJECT, 2019
** RPG
** File description:
** init_profiles
*/

#include "my.h"

void more_more_init(dwd_t *dwd, char *save3)
{
    char *selected_font = extract_string_value("font", dwd->menu.data);

    if (my_strcmp(save3, "123456789") != 0) {
        dwd->save.save3_t = create_button_text
            (selected_font, save3, 125, sfWhite);
        pos_button_text(&dwd->save.save3_t, dwd->save.save3_bt, save3);
    }
}

void more_init_text(dwd_t *dwd, char *save1, char *save2, char *save3)
{
    char *selected_font = extract_string_value("font", dwd->menu.data);

    if (my_strcmp(save3, "123456789") == 0) {
        dwd->save.save3_t = create_button_text
            (selected_font, "Save3", 125, sfWhite);
        pos_button_text(&dwd->save.save3_t, dwd->save.save3_bt, "Save3");
    }
    if (my_strcmp(save1, "123456789") != 0) {
        dwd->save.save1_t = create_button_text
            (selected_font, save1, 125, sfWhite);
        pos_button_text(&dwd->save.save1_t, dwd->save.save1_bt, save1);
    }
    if (my_strcmp(save2, "123456789") != 0) {
        dwd->save.save2_t = create_button_text
            (selected_font, save2, 125, sfWhite);
        pos_button_text(&dwd->save.save2_t, dwd->save.save2_bt, save2);
    }
    more_more_init(dwd, save3);
}

void init_text(dwd_t *dwd)
{
    char *selected_font = extract_string_value("font", dwd->menu.data);
    char *save1 = extract_string_value("pseudo", dwd->save.data_save1);
    char *save2 = extract_string_value("pseudo", dwd->save.data_save2);
    char *save3 = extract_string_value("pseudo", dwd->save.data_save3);

    if (my_strcmp(save1, "123456789") == 0) {
        dwd->save.save1_t = create_button_text
            (selected_font, "Save1", 125, sfWhite);
        pos_button_text(&dwd->save.save1_t, dwd->save.save1_bt, "Save1");
    }
    if (my_strcmp(save2, "123456789") == 0) {
        dwd->save.save2_t = create_button_text
            (selected_font, "Save2", 125, sfWhite);
        pos_button_text(&dwd->save.save2_t, dwd->save.save2_bt, "Save2");
    }
    more_init_text(dwd, save1, save2, save3);
}

static void init_rect(dwd_t *dwd)
{
    sfIntRect rect = {0, 0, 310, 160};

    sfSprite_setTextureRect(dwd->save.save1_bt, rect);
    sfSprite_setTextureRect(dwd->save.save2_bt, rect);
    sfSprite_setTextureRect(dwd->save.save3_bt, rect);
}

int init_profiles(dwd_t *dwd)
{
    sfVector2f scl = {1.5, 1.5};

    if (extract_data_file("src/.save1", &dwd->save.data_save1) == 84 ||
        extract_data_file("src/.save2", &dwd->save.data_save2) == 84 ||
        extract_data_file("src/.save3", &dwd->save.data_save3) == 84)
        return (84);
    dwd->save.save1_bt = f_sprite_create
        ("SAVE1", dwd->menu.data, 100, 540);
    dwd->save.save2_bt = f_sprite_create
        ("SAVE2", dwd->menu.data, 700, 540);
    dwd->save.save3_bt = f_sprite_create
        ("SAVE3", dwd->menu.data, 1300, 540);
    sfSprite_setScale(dwd->save.save1_bt, scl);
    sfSprite_setScale(dwd->save.save2_bt, scl);
    sfSprite_setScale(dwd->save.save3_bt, scl);
    init_text(dwd);
    init_rect(dwd);
    return (0);
}
