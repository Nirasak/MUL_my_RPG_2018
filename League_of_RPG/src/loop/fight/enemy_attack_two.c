/*
** EPITECH PROJECT, 2019
** enemy_attack_two.c
** File description:
** create my second enemy attack 
*/

#include "my.h"

void anime_attacktwo_enemy(fight_t *f)
{
    static sfTime time;
    static float sec;

    time = sfClock_getElapsedTime(f->enemy.anime_attacktwo);
    sec = time.microseconds / 1000000.0;
    if (sec > f->enemy.sec_attacktwo) {
        f->enemy.attack_recttwo.left = f->enemy.attack_recttwo.left +
            f->enemy.left_attacktwo;
        sfSprite_setTextureRect(f->enemy.attacksprtwo, f->enemy.attack_recttwo);
        sfClock_restart(f->enemy.anime_attacktwo);
        if (f->enemy.attack_recttwo.left >= f->enemy.max_left_attacktwo)
            f->enemy.attack_recttwo.left = 0 - f->enemy.left_attacktwo;
    }
}

void cait_touchedtwo(fight_t *f, sfVector2f *pos, sfVector2f cait, int *reset)
{
    pos->y = -1500;
    sfSprite_setPosition(f->enemy.attacksprtwo, *pos);
    *reset = 0;
    sfText_setPosition(f->spawn.text, cait);
    headshoot(f, f->enemy.attack - f->cait.spe[4], &f->cait.spe[9]);
}

int move_attacktwo_enemy(fight_t *f, sfVector2f *pos, int *reset)
{
    static sfTime time;
    static float sec;
    sfVector2f cait = pos_cait_corp(f);

    time = sfClock_getElapsedTime(f->enemy.move_attacktwo);
    sec = time.microseconds / 1000000.0;
    if (sec > 0.04) {
        pos->x = pos->x -
            (calcul_dist(cait.x, sfSprite_getPosition(f->enemy.enemy).x) / 30)
            - f->enemy.speed_attacktwo.x;
        pos->y = pos->y - (calcul_dist(cait.y, pos->y) / 30);
        if (pos->x < cait.x) {
            cait_touchedtwo(f, pos, cait, reset);
            return (0);
          }
        sfSprite_setPosition(f->enemy.attacksprtwo, *pos);
        sfClock_restart(f->enemy.move_attacktwo);
    }
    return (1);
}
