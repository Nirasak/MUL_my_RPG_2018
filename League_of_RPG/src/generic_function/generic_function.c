/*
** EPITECH PROJECT, 2019
** RPG
** File description:
** generic_function
*/

#include <time.h>
#include "my.h"

int randomm(int a, int b)
{
    srand(time(NULL));
    return (rand() % b + a);
}

void change_scale(sfSprite *sprite, float x, float y)
{
    sfVector2f scl;

    scl.x = x;
    scl.y = y;
    sfSprite_setScale(sprite, scl);
}
