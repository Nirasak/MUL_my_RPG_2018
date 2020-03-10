/*
** EPITECH PROJECT, 2019
** RPG
** File description:
** init_keybinding_annex
*/

#include "my.h"

void check_text(dwd_t *dwd, char *str, int i)
{
    if (dwd->option.key.keybind[i][0] < 26)
        str[0] = dwd->option.key.keybind[i][0] + 'a';
    else
        str[0] = dwd->option.key.keybind[i][0] + 22;
    str[1] = '\0';
}

void init_key_text(dwd_t *dwd, int i, char *my_font, int first)
{
    char *str = malloc(2);
    int k = i;
    float l = 0;

    check_text(dwd, str, i);
    if (first == 1) {
        sfText_setString(dwd->option.key.key_t[i], str);
        free(str);
        return;
    }
    dwd->option.key.key_t[i] = create_button_text
        (my_font, str, 40, sfWhite);
    free(str);
    (i >= 4) ? k -= 4 : 0;
    (i >= 8) ? k -= 4 : 0;
    i >= 4 ? l = 1 : 0;
    i >= 8 ? l = 2.01 : 0;
    pos_text(dwd->option.key.key_t[i], 825 + l * 350, k * 100 + 310);
}

void reduce_to_csfml_key(dwd_t *dwd, int i)
{
    if (dwd->option.key.keybind[i][0] >= 'a' &&
        dwd->option.key.keybind[i][0] <= 'z')
        dwd->option.key.keybind[i][0] -= 'a';
    if (dwd->option.key.keybind[i][0] >= '0' &&
        dwd->option.key.keybind[i][0] <= '9')
        dwd->option.key.keybind[i][0] -= 22;
}

void init_keys(dwd_t *dwd)
{
    char *my_font = extract_string_value("font", dwd->menu.data);

    dwd->option.key.keybind[0] = extract_string_value("up", dwd->menu.data);
    dwd->option.key.keybind[1] = extract_string_value("down", dwd->menu.data);
    dwd->option.key.keybind[2] = extract_string_value("left", dwd->menu.data);
    dwd->option.key.keybind[3] = extract_string_value("right", dwd->menu.data);
    dwd->option.key.keybind[4] = extract_string_value("spell1", dwd->menu.data);
    dwd->option.key.keybind[5] = extract_string_value("spell2", dwd->menu.data);
    dwd->option.key.keybind[6] = extract_string_value("spell3", dwd->menu.data);
    dwd->option.key.keybind[7] = extract_string_value("spell4", dwd->menu.data);
    dwd->option.key.keybind[8] = extract_string_value("heal", dwd->menu.data);
    dwd->option.key.keybind[9] = extract_string_value("quest", dwd->menu.data);
    dwd->option.key.keybind[10] = extract_string_value("shop", dwd->menu.data);
    dwd->option.key.keybind[11] = extract_string_value
        ("instance", dwd->menu.data);
    for (int i = 0; i != 12; i++) {
        reduce_to_csfml_key(dwd, i);
        init_key_text(dwd, i, my_font, 0);
    }
}
