/*
** EPITECH PROJECT, 2019
** RPG
** File description:
** init_keybinding_second_annex
*/

#include "my.h"

int first_cond_check(dwd_t *dwd, char c)
{
    for (int i = 4; i != 8; i++) {
        if ((i != dwd->option.key.is_clicked &&
            c - 'a' == dwd->option.key.keybind[i][0]) ||
            c - 22 == dwd->option.key.keybind[i][0])
            return (1);
    }
    return (0);
}

int sec_cond_check(dwd_t *dwd, char c)
{
    for (int i = 0; i != 4; i++) {
        if ((i != dwd->option.key.is_clicked &&
            c - 'a' == dwd->option.key.keybind[i][0]) ||
            c - 22 == dwd->option.key.keybind[i][0])
            return (1);
    }
    for (int i = 8; i != 12; i++) {
        if ((i != dwd->option.key.is_clicked &&
            c - 'a' == dwd->option.key.keybind[i][0]) ||
            c - 22 == dwd->option.key.keybind[i][0])
            return (1);
    }
    return (0);
}

int check_no_existing_key(dwd_t *dwd, char c)
{
    if (dwd->option.key.is_clicked >= 4 && dwd->option.key.is_clicked <= 7) {
        if (first_cond_check(dwd, c) == 1)
            return (1);
    }
    else {
        if (sec_cond_check(dwd, c) == 1)
            return (1);
    }
    return (0);
}

void insert_key_annex(dwd_t *dwd, char *my_font)
{
    char c;
    char *str;

    if (dwd->option.key.is_clicked != -1 &&
        dwd->event.type == sfEvtTextEntered) {
        c = dwd->event.text.unicode;
        if (((c >= 'a' && c <= 'z') || (c >= '0' && c <= '9')) &&
            check_no_existing_key(dwd, c) == 0) {
            str = malloc(2);
            str[0] = c;
            str[1] = '\0';
            dwd->option.key.keybind[dwd->option.key.is_clicked] =
                my_strdup(str);
            reduce_to_csfml_key(dwd, dwd->option.key.is_clicked);
            init_key_text(dwd, dwd->option.key.is_clicked, my_font, 1);
            dwd->option.key.is_clicked = -1;
        }
    }
}

void insert_keys(dwd_t *dwd, sfSprite *sprite)
{
    sfVector2f pos = sfSprite_getPosition(sprite);
    sfIntRect rc = sfSprite_getTextureRect(sprite);
    int i;
    char *my_font = extract_string_value("font", dwd->menu.data);

    if (dwd->event.type == sfEvtMouseButtonReleased &&
        dwd->option.key.is_clicked == -1 &&
        dwd->mouse.pos.x > pos.x && dwd->mouse.pos.x < pos.x + rc.width &&
        dwd->mouse.pos.y > pos.y && dwd->mouse.pos.y < pos.y + rc.height) {
        i = pos.y / 100 - 3;
        if (pos.x == 1150)
            i += 4;
        if (pos.x > 1200)
            i += 8;
        sfText_setString(dwd->option.key.key_t[i], " ");
        dwd->option.key.is_clicked = i;
    }
    insert_key_annex(dwd, my_font);
}
