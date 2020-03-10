/*
** EPITECH PROJECT, 2019
** RPG
** File description:
** mouse
*/

#include "my.h"

void detect_click(dwd_t *dwd)
{
    if (dwd->event.type == sfEvtMouseButtonPressed) {
        dwd->mouse.is_clicked = 1;
        return;
    }
    if (dwd->event.type == sfEvtMouseButtonReleased)
        dwd->mouse.is_clicked = 0;
}

void mouse(dwd_t *dwd)
{
    dwd->mouse.mouse_pos = sfMouse_getPositionRenderWindow(dwd->window);
    dwd->mouse.pos.x = dwd->mouse.mouse_pos.x;
    dwd->mouse.pos.y = dwd->mouse.mouse_pos.y;
    sfSprite_setPosition(dwd->mouse.f_mouse, dwd->mouse.pos);
    sfSprite_setPosition(dwd->mouse.s_mouse, dwd->mouse.pos);
    detect_click(dwd);
    if (dwd->mouse.which_mouse == 1) {
        if (dwd->mouse.is_clicked == 1) {
            dwd->mouse.rect_fmouse.left = 94;
            sfSprite_setTextureRect(dwd->mouse.f_mouse, dwd->mouse.rect_fmouse);
        }
        else {
            dwd->mouse.rect_fmouse.left = 0;
            sfSprite_setTextureRect(dwd->mouse.f_mouse, dwd->mouse.rect_fmouse);
        }
    }
}

void disp_mouse(dwd_t *dwd)
{
    if (dwd->mouse.which_mouse == 1)
        sfRenderWindow_drawSprite(dwd->window, dwd->mouse.f_mouse, NULL);
    if (dwd->mouse.which_mouse == 2)
        sfRenderWindow_drawSprite(dwd->window, dwd->mouse.s_mouse, NULL);
}
