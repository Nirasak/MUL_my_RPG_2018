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
    sfMusic_destroy(f->cait.shot_sound);
    sfMusic_destroy(f->cait.lvlup);
    sfMusic_destroy(dwd->sound.click);
    sfMusic_destroy(dwd->sound.map);
    sfMusic_destroy(dwd->sound.boss);
    sfMusic_destroy(dwd->sound.fight);
}

void destroy_all(dwd_t *dwd, fight_t *f)
{
    destroy_music(dwd, f);
}
