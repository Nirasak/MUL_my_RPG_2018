/*
** EPITECH PROJECT, 2019
** RPG
** File description:
** init_mouse
*/

#include "my.h"

int init_mouse(dwd_t *dwd)
{
    sfVector2f origin_mouse = {33, 22};
    sfVector2f origin_s_mouse = {32, 32};
    sfVector2f scl = {1.7, 1.7};

    dwd->mouse.is_clicked = 0;
    sfRenderWindow_setMouseCursorVisible(dwd->window, sfFalse);
    dwd->mouse.rect_fmouse.left = 0;
    dwd->mouse.rect_fmouse.top = 0;
    dwd->mouse.rect_fmouse.width = 100;
    dwd->mouse.rect_fmouse.height = 105;
    if ((dwd->mouse.which_mouse = extract_saved_value("curs", dwd->menu.data))
        == 84)
        return (84);
    dwd->mouse.f_mouse = f_sprite_create("CURS1", dwd->menu.data, 0, 0);
    dwd->mouse.s_mouse = f_sprite_create("CURS2", dwd->menu.data, 0, 0);
    sfSprite_setScale(dwd->mouse.s_mouse, scl);
    sfSprite_setTextureRect(dwd->mouse.f_mouse, dwd->mouse.rect_fmouse);
    sfSprite_setOrigin(dwd->mouse.f_mouse, origin_mouse);
    sfSprite_setOrigin(dwd->mouse.s_mouse, origin_s_mouse);
    return (0);
}
