/*
** EPITECH PROJECT, 2019
** move_cara_spawn.c
** File description:
** move my cara on my spawn
*/

#include "my.h"

void move_rporo(dwd_t *dwd, fight_t *f)
{
    static sfVector2f *posi;
    static int a = 0;

    if (a == 0) {
        posi = malloc(sizeof(sfVector2f) * 4);
        posi[0] = sfSprite_getPosition(f->spawn.rporo);
        posi[1] = sfSprite_getPosition(f->spawn.rporo);
        posi[2] = sfSprite_getPosition(f->spawn.rporo);
        posi[1].x = posi[0].x + 150;
        posi[2].x = posi[1].x + 150;
        posi[1].y = posi[0].y + 50;
        posi[2].y = posi[1].y + 150;
        a++;
    }
    for (int i = 0; i < 3; i++) {
        sfSprite_setPosition(f->spawn.rporo, posi[i]);
        posi[i].x = posi[i].x - 3;
        sfRenderWindow_drawSprite(dwd->window, f->spawn.rporo, NULL);
    }
}

void move_tamo(fight_t *f)
{
    sfVector2f posi = sfSprite_getPosition(f->spawn.tamo);
    sfVector2f pos;

    pos.x = posi.x - 2;
    pos.y = posi.y;
    sfSprite_setPosition(f->spawn.tamo, pos);
}
