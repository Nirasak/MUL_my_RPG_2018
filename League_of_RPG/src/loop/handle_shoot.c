/*
** EPITECH PROJECT, 2019
** handle_shoot.c
** File description:
** handle my shot
*/

#include "my.h"

void headshoot(fight_t *f, int dmg, int *life)
{
    sfVector2f pos = {1440, 630};

    f->enemy.resetscl = 80;
    dmg < 0 ? dmg = 0 : 0;
    sfSprite_setPosition(f->cait.impact, pos);
    sfText_setCharacterSize(f->spawn.text, f->enemy.resetscl);
    if ((*life) - dmg * 2 > 0)
        (*life) = *(life) - dmg * 2;
    else
        (*life) = 0;
    sfText_setColor(f->spawn.text, sfRed);
    sfText_setString(f->spawn.text, my_itoa(dmg * 2));
}

void no_crit_shot(fight_t *f, int dmg, int *life)
{
    dmg < 0 ? dmg = 0 : 0;
    f->enemy.resetscl = 50;
    if ((*life) - dmg > 0)
        (*life) = (*life) - dmg;
    else
        (*life) = 0;
    sfText_setString(f->spawn.text, my_itoa(dmg));
    sfText_setCharacterSize(f->spawn.text, f->enemy.resetscl);
    sfText_setColor(f->spawn.text, sfWhite);
}

void handle_shoot(fight_t *f, int dmg, int *life)
{
    if (randomm(0, 100) < f->cait.spe[1])
        headshoot(f, dmg, life);
    else
        no_crit_shot(f, dmg, life);
    if (f->cait.life_steal != 0)
        f->cait.spe[9] = f->cait.spe[9] + (f->cait.spe[10] *
                                        f->cait.life_steal) / 1000;
}

void move_text(fight_t *f, sfVector2f *pos, int *i)
{
    pos->y = pos->y - 10;
    anime_text(f->spawn.text, i);
    if (pos->y < 400) {
        pos->y = -1500;
        *i = 0;
        sfText_setPosition(f->spawn.text, *pos);
    }
    sfText_setPosition(f->spawn.text, *pos);
    sfClock_restart(f->spawn.clocke);
}
