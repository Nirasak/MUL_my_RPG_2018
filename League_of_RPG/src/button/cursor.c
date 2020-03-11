/*
** EPITECH PROJECT, 2019
** RPG
** File description:
** curosr
*/

#include "my.h"

int push_fcursor(sfSprite *sprite, dwd_t *dwd)
{
    sfIntRect rect = sfSprite_getTextureRect(sprite);
    sfVector2f ps = sfSprite_getPosition(sprite);

    if (dwd->event.type == sfEvtMouseButtonPressed &&
        dwd->mouse.pos.x > ps.x &&
        dwd->mouse.pos.x < ps.x + rect.width &&
        dwd->mouse.pos.y > ps.y &&
        dwd->mouse.pos.y < ps.y + rect.height) {
        return (1);
    }
    return (0);
}

int push_scursor(sfSprite *sprite, dwd_t *dwd)
{
    sfIntRect rect = sfSprite_getTextureRect(sprite);
    sfVector2f ps = sfSprite_getPosition(sprite);

    if (dwd->event.type == sfEvtMouseButtonPressed &&
        dwd->mouse.pos.x > ps.x &&
        dwd->mouse.pos.x < ps.x + rect.width + 30 &&
        dwd->mouse.pos.y > ps.y &&
        dwd->mouse.pos.y < ps.y + rect.height + 30) {
        return (1);
    }
    return (0);
}

int push_small_button(sfSprite *sprite, dwd_t *dwd, int x, int y)
{
    sfVector2f ps = sfSprite_getPosition(sprite);

    if (dwd->event.type == sfEvtMouseButtonPressed &&
        dwd->mouse.pos.x > ps.x &&
        dwd->mouse.pos.x < ps.x + x &&
        dwd->mouse.pos.y > ps.y &&
        dwd->mouse.pos.y < ps.y + y) {
        return (1);
    }
    return (0);
}
