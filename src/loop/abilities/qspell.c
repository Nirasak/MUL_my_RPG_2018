/*
** EPITECH PROJECT, 2019
** qspell.c
** File description:
** create my qspell
*/

#include "my.h"

void anime_qspell(fight_t *f)
{
    static sfTime time;
    static float sec;
    static sfIntRect rect = {0, 0, 550, 550};

    time = sfClock_getElapsedTime(f->spell.clock_qspell);
    sec = time.microseconds / 1000000.0;
    if (sec > 0.1) {
        rect.left = rect.left + 550;
        sfSprite_setTextureRect(f->spell.qspell, rect);
        sfClock_restart(f->spell.clock_qspell);
        if (rect.left >= 6050)
            rect.left = 0;
    }
}

static float clock(fight_t *f)
{
    static sfTime time;
    static float sec;

    time = sfClock_getElapsedTime(f->spell.move_qspell);
    sec = time.microseconds / 1000000.0;
    return (sec);
}

void explo_qspell(fight_t *f)
{
    sfVector2f pos = sfSprite_getPosition(f->enemy.enemy);
    sfIntRect rect = sfSprite_getTextureRect(f->enemy.enemy);

    pos.x = pos.x + 40;
    pos.y = pos.y + rect.height / 2 + 40;
    f->explo[0].direct = 0;
    set_pos_explo(pos, f, sfRed);
}

int move_qspell(fight_t *f, sfVector2f *pos, int *reset)
{
    float sec = clock(f);

    if (sec > 0.02) {
        if (pos->x + 50 < sfSprite_getPosition(f->enemy.enemy).x)
            pos->x = pos->x + 16;
        else {
            headshoot(f, (f->cait.spe[0] * 2) -
                    f->enemy.defense, &f->enemy.actual_life);
            put_text_on_enemy(f);
            explo_qspell(f);
            pos->y = -1500;
            pos->x = -1500;
            *reset = 0;
            sfSprite_setPosition(f->spell.qspell, *pos);
            return (0);
        }
        sfSprite_setPosition(f->spell.qspell, *pos);
    }
    return (1);
}

int first_spell(dwd_t *dwd, fight_t *f, sfVector2f *pos, int *active)
{
    anime_qspell(f);
    sfRenderWindow_drawSprite(dwd->window, f->spell.qspell, NULL);
    return (move_qspell(f, pos, active));
}
