/*
** EPITECH PROJECT, 2019
** RPG
** File description:
** active button
*/

#include "my.h"

int push_button
(sfSprite *button, sfVector2f ps, sfText *text, dwd_t *dwd)
{
    sfIntRect rect_button = {0, 0, 310, 160};

    if (dwd->mouse.pos.x < ps.x || dwd->mouse.pos.x > ps.x
        + 465 || dwd->mouse.pos.y < ps.y || dwd->mouse.pos.y > ps.y + 178.5)
        dwd->menu.button.bt_clicked = 0;
    if (dwd->event.type == sfEvtMouseButtonReleased &&
        dwd->mouse.pos.x > ps.x && dwd->mouse.pos.x < ps.x
        + 465 && dwd->mouse.pos.y > ps.y &&
        dwd->mouse.pos.y < ps.y + 178.5) {
        dwd->menu.button.bt_clicked = 0;
        sfSprite_setTextureRect(button, rect_button);
        sfText_setColor(text, sfWhite);
        return (1);
    }
    return (0);
}

int active_button(sfSprite *button, sfText *text, sfColor color, dwd_t *dwd)
{
    sfIntRect rect_button = {0, 0, 310, 160};
    sfVector2i posi = sfMouse_getPositionRenderWindow(dwd->window);
    sfVector2f ps = sfSprite_getPosition(button);

    dwd->mouse.pos.x = posi.x;
    dwd->mouse.pos.y = posi.y;
    if (dwd->event.type == sfEvtMouseButtonPressed &&
        dwd->mouse.pos.x > ps.x && dwd->mouse.pos.x < ps.x + 465 &&
        dwd->mouse.pos.y > ps.y && dwd->mouse.pos.y < ps.y + 178.5) {
        dwd->menu.button.bt_clicked = 1;
        sfMusic_play(dwd->sound.click);
    }
    if (dwd->mouse.pos.x > ps.x && dwd->mouse.pos.x < ps.x + 465 &&
        dwd->mouse.pos.y > ps.y && dwd->mouse.pos.y < ps.y + 178.5) {
        rect_button.left = 389;
        dwd->menu.button.bt_clicked == 0 ? sfText_setColor(text, sfWhite) : 0;
        dwd->menu.button.bt_clicked == 1 ? sfText_setColor(text, color) : 0;
    }
    sfSprite_setTextureRect(button, rect_button);
    return (push_button(button, ps, text, dwd));
}

int active_option_button(sfSprite *button, int *change_value, dwd_t *dwd)
{
    sfVector2i posi = sfMouse_getPositionRenderWindow(dwd->window);
    sfVector2f ps = sfSprite_getPosition(button);

    dwd->mouse.pos.x = posi.x;
    dwd->mouse.pos.y = posi.y;
    if (dwd->event.type == sfEvtMouseButtonPressed &&
        dwd->mouse.pos.x > ps.x && dwd->mouse.pos.x < ps.x + 38 &&
        dwd->mouse.pos.y > ps.y && dwd->mouse.pos.y < ps.y + 37)
        sfMusic_play(dwd->sound.click);
    if (dwd->event.type == sfEvtMouseButtonReleased &&
        dwd->mouse.pos.x > ps.x && dwd->mouse.pos.x < ps.x + 38 &&
        dwd->mouse.pos.y > ps.y && dwd->mouse.pos.y < ps.y + 37) {
        if (*change_value == 0)
            *change_value = 1;
        else
            *change_value = 0;
        return (1);
    }
    return (0);
}

int re_active_option_button(sfSprite *button, dwd_t *dwd)
{
    sfVector2i posi = sfMouse_getPositionRenderWindow(dwd->window);
    sfVector2f ps = sfSprite_getPosition(button);

    dwd->mouse.pos.x = posi.x;
    dwd->mouse.pos.y = posi.y;
    if (dwd->event.type == sfEvtMouseButtonPressed &&
        dwd->mouse.pos.x > ps.x && dwd->mouse.pos.x < ps.x + 38 &&
        dwd->mouse.pos.y > ps.y && dwd->mouse.pos.y < ps.y + 37)
        sfMusic_play(dwd->sound.click);
    if (dwd->event.type == sfEvtMouseButtonReleased &&
        dwd->mouse.pos.x > ps.x && dwd->mouse.pos.x < ps.x + 38 &&
        dwd->mouse.pos.y > ps.y && dwd->mouse.pos.y < ps.y + 37)
        return (1);
    return (0);
}
