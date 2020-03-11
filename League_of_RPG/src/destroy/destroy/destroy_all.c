/*
** EPITECH PROJECT, 2019
** destroy_all.c
** File description:
** destroy all i have create before
*/

#include "my.h"

void destroy_music(dwd_t *dwd, fight_t *f)
{
    sfMusic_destroy(dwd->sound.menu);
    sfMusic_destroy(dwd->sound.menu2);
    sfMusic_destroy(f->cait.shot_sound);
    sfMusic_destroy(f->cait.lvlup);
    sfMusic_destroy(dwd->sound.click);
}

void destroy_all(dwd_t *dwd, fight_t *f, map_t *map)
{
    destroy_music(dwd, f);
    destroy_sprites_menu(dwd);
    destroy_sprites_game(map);
//    destroy_sprites_fight(fight);
    destroy_menu(dwd);
}
