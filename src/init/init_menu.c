/*
** EPITECH PROJECT, 2019
** init_menu.c
** File description:
** create my menu
*/

#include "my.h"
#include <time.h>

void init_before_menu(dwd_t *dwd)
{
    sfVector2f pos_pseudo = {1600, 60};
    int len = my_strlen(dwd->pseudo);

    if (len != 1)
        pos_pseudo.x -= len * 9;
    sfText_setCharacterSize(dwd->pseudo_t, 50);
    sfText_setPosition(dwd->pseudo_t, pos_pseudo);
}

void init_rect_menu(dwd_t *dwd)
{
    dwd->menu.rect_menu.left = 0;
    dwd->menu.rect_menu.top = 202;
    dwd->menu.rect_menu.width = 1200;
    dwd->menu.rect_menu.height = 878;
    dwd->menu.rect_menu2.left = 0;
    dwd->menu.rect_menu2.top = 0;
    dwd->menu.rect_menu2.width = 500;
    dwd->menu.rect_menu2.height = 255;
    dwd->menu.menu = f_sprite_create("MENU", dwd->menu.data, 0, 0);
    dwd->menu.menu2 = f_sprite_create("MENU2", dwd->menu.data, 0, 0);
    sfSprite_setTextureRect(dwd->menu.menu, dwd->menu.rect_menu);
    sfSprite_setTextureRect(dwd->menu.menu, dwd->menu.rect_menu2);
    change_scale(dwd->menu.menu, 1.6, 1.6);
    change_scale(dwd->menu.menu2, 4.0, 4.3);
}

int init_menu(dwd_t *dwd)
{
    char *my_font;

    if (extract_data_file("src/menu/.loading_menu", &dwd->menu.data) == 84)
        return (84);
    my_font = extract_string_value("font", dwd->menu.data);
    dwd->pseudo = extract_string_value("pseudo", dwd->menu.data);
    dwd->menu.board = f_sprite_create("BOARD", dwd->menu.data, 0, -50);
    dwd->user = extract_saved_value("user", dwd->menu.data);
    dwd->menu.profile.difficulty = extract_saved_value("diff", dwd->menu.data);
    dwd->menu.profile.played = extract_saved_value("played", dwd->menu.data);
    if (my_strcmp(dwd->pseudo, "123456789") != 0)
        dwd->pseudo_t = create_button_text(my_font, dwd->pseudo, 100, sfWhite);
    init_rect_menu(dwd);
    dwd->menu.clock = sfClock_create();
    dwd->menu.clock2 = sfClock_create();
    dwd->is_open = MENU;
    dwd->shop_back = LEAVE;
    return (0);
}
