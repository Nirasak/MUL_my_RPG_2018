/*
** EPITECH PROJECT, 2019
** rspell.c
** File description:
** create my functions for my ult
*/

#include "my.h"

void anime_rspell(fight_t *f)
{
    sfVector2f scl = sfSprite_getScale(f->spell.abilities[3]);

    scl.x = scl.x + 0.01;
    scl.y = scl.y + 0.01;
    change_scale(f->spell.abilities[3], scl.x, scl.y);
}

sfVector2f pos_enemy_corp(fight_t *f)
{
    sfVector2f pos = sfSprite_getPosition(f->enemy.enemy);
    sfIntRect rect = sfSprite_getTextureRect(f->enemy.enemy);

    pos.x = pos.x + rect.width / 2 + 100;
    pos.y = pos.y + rect.height / 2;
    return (pos);
}

int rspell_touch(fight_t *f, sfVector2f pos)
{
    pos = pos_cait_corp(f);
    pos.y = pos.y + 70;
    headshoot(f, (f->enemy.max_life / 8) + f->cait.spe[0] * 2,
            &f->enemy.actual_life);
    put_text_on_enemy(f);
    pos.y = -1500;
    change_scale(f->spell.abilities[3], 0.01, 0.01);
    sfSprite_setPosition(f->spell.abilities[3], pos);
    return (0);
}

int move_rspell(fight_t *f)
{
    static sfTime time;
    static float sec;
    sfVector2f pos = sfSprite_getPosition(f->spell.abilities[3]);
    sfVector2f enemy = pos_enemy_corp(f);

    time = sfClock_getElapsedTime(f->spell.clock_ult);
    sec = time.microseconds / 1000000.0;
    if (sec > 0.01) {
        pos.x = pos.x +
            (calcul_dist(enemy.x,
                        sfSprite_getPosition(f->cait.sprite).x) * -1) / 200;
        pos.y = pos.y + (calcul_dist(enemy.y, pos.y) * -1) / 200;
        anime_rspell(f);
        sfSprite_setPosition(f->spell.abilities[3], pos);
        sfClock_restart(f->spell.clock_ult);
    }
    if (pos.x >= enemy.x)
        return (rspell_touch(f, pos));
    return (1);
}

int last_spell(fight_t *f)
{
    return (move_rspell(f));
}
