/*
** EPITECH PROJECT, 2019
** createsprites.c
** File description:
** create my sprites function
*/

#include "my.h"

sfSprite *create_sprite(char *path, float x, float y)
{
    sfSprite *sprite;
    sfTexture *text;
    sfVector2f pos;

    if (!path)
        return (NULL);
    pos.x = x;
    pos.y = y;
    text = sfTexture_createFromFile(path, NULL);
    sprite = sfSprite_create();
    sfSprite_setTexture(sprite, text, sfTrue);
    sfSprite_setPosition(sprite, pos);
    return (sprite);
}
