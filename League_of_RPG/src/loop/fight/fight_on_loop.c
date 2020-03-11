/*
** EPITECH PROJECT, 2019
** fight_on_loop.c
** File description:
** put things on my fight loop
*/

#include "my.h"

void put_fight_loop(dwd_t *dwd, sfSprite *back, fight_t *f)
{
    sfRenderWindow_drawSprite(dwd->window, back, NULL);
    draw_enemy(dwd, f);
    loop_fight(dwd, f);
    anime_enemy(f);
    draw_interface(dwd, f);
    sfRenderWindow_drawSprite(dwd->window, f->spell.abilities[1], NULL);
    sfRenderWindow_drawSprite(dwd->window, f->spell.abilities[3], NULL);
}
