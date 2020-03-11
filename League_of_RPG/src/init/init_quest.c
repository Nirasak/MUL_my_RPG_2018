/*
** EPITECH PROJECT, 2019
** RPG
** File description:
** init_quest
*/

#include "my.h"

void fourth_disp(dwd_t *dwd, fight_t *f, char *str)
{
    if (f->quest == 10) {
        str = extract_string_value("10", dwd->menu.data);
        sfText_setString(dwd->quest.text_champ, str);
    }
    if (f->quest == 11) {
        str = extract_string_value("11", dwd->menu.data);
        sfText_setString(dwd->quest.text_champ, str);
    }
}

void third_disp(dwd_t *dwd, fight_t *f, char *str)
{
    if (f->quest == 7) {
        str = extract_string_value("7", dwd->menu.data);
        sfText_setString(dwd->quest.text_champ, str);
    }
    if (f->quest == 8) {
        str = extract_string_value("8", dwd->menu.data);
        sfText_setString(dwd->quest.text_champ, str);
    }
    if (f->quest == 9) {
        str = extract_string_value("9", dwd->menu.data);
        sfText_setString(dwd->quest.text_champ, str);
    }
    fourth_disp(dwd, f, str);
}

void sec_disp(dwd_t *dwd, fight_t *f, char *str)
{
    if (f->quest == 4) {
        str = extract_string_value("4", dwd->menu.data);
        sfText_setString(dwd->quest.text_champ, str);
    }
    if (f->quest == 5) {
        str = extract_string_value("5", dwd->menu.data);
        sfText_setString(dwd->quest.text_champ, str);
    }
    if (f->quest == 6) {
        str = extract_string_value("6", dwd->menu.data);
        sfText_setString(dwd->quest.text_champ, str);
    }
    third_disp(dwd, f, str);
}

void display_text(dwd_t *dwd, fight_t *f)
{
    char *str;

    if (f->quest == 0.5) {
        str = extract_string_value("0.5", dwd->menu.data);
        sfText_setString(dwd->quest.text_champ, str);
    }
    if (f->quest == 2) {
        str = extract_string_value("2", dwd->menu.data);
        sfText_setString(dwd->quest.text_champ, str);
    }
    if (f->quest == 3) {
        str = extract_string_value("3", dwd->menu.data);
        sfText_setString(dwd->quest.text_champ, str);
    }
    sec_disp(dwd, f, str);
}

int init_quest(dwd_t *dwd)
{
    char *my_font = extract_string_value("font", dwd->menu.data);

    dwd->quest.background = f_sprite_create("BG_QUEST", dwd->menu.data, 0, 0);
    dwd->quest.quest = create_button_text(my_font, "Quest", 100, sfWhite);
    pos_text(dwd->quest.quest, 900, 140);
    dwd->quest.text_champ = create_button_text(my_font, "fill", 45, sfWhite);
    pos_text(dwd->quest.text_champ, 560, 350);
    return (0);
}
