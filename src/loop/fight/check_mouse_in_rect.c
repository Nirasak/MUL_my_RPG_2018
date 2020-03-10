/*
** EPITECH PROJECT, 2019
** check_mouse_in_rect
** File description:
** check if my mouse is in my rectenemy
*/

#include "my.h"

int check_mouse_in_rect(dwd_t *dwd, fight_t *f)
{
    sfIntRect rect = sfSprite_getTextureRect(f->enemy.enemy);
    sfVector2f pos = sfSprite_getPosition(f->enemy.enemy);

    if (dwd->mouse.pos.x > pos.x && dwd->mouse.pos.x < pos.x + rect.width * 2 &&
        dwd->mouse.pos.y > pos.y && dwd->mouse.pos.y < pos.y + rect.height * 2)
        return (0);
    return (1);
}
