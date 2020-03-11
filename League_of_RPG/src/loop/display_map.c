/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** display
*/

#include "my.h"

void display_map(map_t *map, dwd_t *dwd)
{
    sfRenderWindow_drawSprite(dwd->window, map->s_map, NULL);
    sfRenderWindow_drawSprite(dwd->window, map->s_mark, NULL);
    sfRenderWindow_drawSprite(dwd->window, map->perso.s_perso, NULL);
    sfRenderWindow_drawSprite(dwd->window, map->s_mini, NULL);
    sfRenderWindow_drawSprite(dwd->window, map->s_circle, NULL);
    sfRenderWindow_drawSprite(dwd->window, map->s_markmin, NULL);
}
