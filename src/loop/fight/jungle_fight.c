/*
** EPITECH PROJECT, 2019
** jungle_fight.c
** File description:
** create all my function for my ungle fight
*/

#include "my.h"

void anime_enemy(fight_t *f)
{
    static sfTime time;
    static float sec;

    time = sfClock_getElapsedTime(f->enemy.anime);
    sec = time.microseconds / 1000000.0;
    if (sec > f->enemy.sec) {
        f->enemy.rect.left = f->enemy.rect.left + f->enemy.left;
        sfSprite_setTextureRect(f->enemy.enemy, f->enemy.rect);
        sfClock_restart(f->enemy.anime);
        if (f->enemy.rect.left >= f->enemy.max_left)
            f->enemy.rect.left = 0 - f->enemy.left;
    }
}

void choose_music(dwd_t *dwd, fight_t *f)
{
    if (f->quest <= 7) {
        sfMusic_play(dwd->sound.fight);
        sfMusic_stop(dwd->sound.menu);
        sfMusic_stop(dwd->sound.map);
        sfMusic_stop(dwd->sound.boss);
    }
    else {
        sfMusic_play(dwd->sound.boss);
        sfMusic_stop(dwd->sound.menu);
        sfMusic_stop(dwd->sound.map);
        sfMusic_stop(dwd->sound.fight);
    }
}

void pre_fight(dwd_t *dwd, fight_t *f)
{
    choose_music(dwd, f);
    change_enemy(f, check_enemy(f));
    addapt_to_difficult(dwd, f);
    f->stun = 0;
}

void put_map_music(dwd_t *dwd)
{
    sfMusic_stop(dwd->sound.boss);
    sfMusic_stop(dwd->sound.menu);
    sfMusic_play(dwd->sound.map);
    sfMusic_stop(dwd->sound.fight);
}

int fight(dwd_t *dwd, fight_t *f, sfSprite *back)
{
    static int a = 0;

    if (a == 0) {
        pre_fight(dwd, f);
        a++;
    }
    put_fight_loop(dwd, back, f);
    if (f->enemy.actual_life <= 0) {
        a = 0;
        put_map_music(dwd);
        return (0);
    }
    if (f->cait.spe[9] <= 0) {
        a = 0;
        put_map_music(dwd);
        return (2);
    }
    sfRenderWindow_drawText(dwd->window, f->spawn.text, NULL);
    return (1);
}
