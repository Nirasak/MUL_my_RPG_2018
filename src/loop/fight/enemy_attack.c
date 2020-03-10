/*
** EPITECH PROJECT, 2019
** enemy_attack.c
** File description:
** create my enemys attack
*/

#include "my.h"

void anime_attack_enemy(fight_t *f)
{
    static sfTime time;
    static float sec;

    time = sfClock_getElapsedTime(f->enemy.anime_attack);
    sec = time.microseconds / 1000000.0;
    if (sec > f->enemy.sec_attack) {
        f->enemy.attack_rect.left = f->enemy.attack_rect.left +
            f->enemy.left_attack;
        sfSprite_setTextureRect(f->enemy.attackspr, f->enemy.attack_rect);
        sfClock_restart(f->enemy.anime_attack);
        if (f->enemy.attack_rect.left >= f->enemy.max_left_attack)
            f->enemy.attack_rect.left = 0 - f->enemy.left_attack;
    }
}

sfVector2f pos_cait_corp(fight_t *f)
{
    sfVector2f pos = sfSprite_getPosition(f->cait.sprite);
    sfIntRect rect = sfSprite_getTextureRect(f->cait.sprite);

    pos.x = pos.x + rect.width / 2;
    pos.y = pos.y + rect.height / 2;
    return (pos);
}

float calcul_dist(float cait, float spell)
{
    float dist = spell - cait;
    return (dist);
}

void cait_touched(fight_t *f, sfVector2f *pos, sfVector2f cait, int *reset)
{
    pos->y = -1500;
    sfSprite_setPosition(f->enemy.attackspr, *pos);
    *reset = 0;
    sfText_setPosition(f->spawn.text, cait);
    no_crit_shot(f, f->enemy.attack - f->cait.spe[4], &f->cait.spe[9]);
}

int move_attack_enemy(fight_t *f, sfVector2f *pos, int *reset)
{
    static sfTime time;
    static float sec;
    sfVector2f cait = pos_cait_corp(f);

    time = sfClock_getElapsedTime(f->enemy.move_attack);
    sec = time.microseconds / 1000000.0;
    if (sec > 0.05) {
        pos->x = pos->x -
            (calcul_dist(cait.x, sfSprite_getPosition(f->enemy.enemy).x) / 30)
            - f->enemy.speed_attack.x;
        pos->y = pos->y - (calcul_dist(cait.y, pos->y) / 30);
        if (pos->x < cait.x) {
            cait_touched(f, pos, cait, reset);
            return (0);
        }
        sfSprite_setPosition(f->enemy.attackspr, *pos);
        sfClock_restart(f->enemy.move_attack);
    }
    return (1);
}
