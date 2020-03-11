/*
** EPITECH PROJECT, 2019
** unlock_abilities.c
** File description:
** create a function who unlock all my abilities
*/

#include "my.h"

void put_unlock_pos(fight_t *f)
{
    sfVector2f pos;

    pos.x = 732;
    pos.y = 843;
    sfSprite_setPosition(f->spell.unlock[0], pos);
    pos.x = 811;
    pos.y = 843;
    sfSprite_setPosition(f->spell.unlock[1], pos);
    pos.x = 890;
    pos.y = 843;
    sfSprite_setPosition(f->spell.unlock[2], pos);
    pos.x = 965;
    pos.y = 843;
    sfSprite_setPosition(f->spell.unlock[3], pos);
}

void put_on_red(dwd_t *dwd, fight_t *f, sfSprite *sprite, int i)
{
    static sfIntRect rect = {0, 0, 48, 40};
    sfVector2f pos = dwd->mouse.pos;
    sfVector2f posi;

    posi = sfSprite_getPosition(sprite);
    if (pos.x >= posi.x && pos.x <= posi.x + 55 &&
        pos.y >= posi.y  && pos.y <= posi.y + 55) {
        sfSprite_setTextureRect(sprite, rect);
        if (dwd->event.type == sfEvtMouseButtonPressed) {
            f->spell.unlock_spell[i] = 1;
            pos.x = 722;
            pos.y = 900;
            if (check_gainabi(f) != 1)
                sfSprite_setPosition(f->spell.select_abi, pos);
        }
    }
}

int check_gainabi(fight_t *f)
{
    static int *s = 0;
    static int a = 0;

    if (a == 0) {
        s = malloc(sizeof(int) * 5);
    }
    for (int i = 0; i != 4; i++)
        s[i] = f->spell.unlock_spell[i];
    if (f->cait.spe[6] > s[0] + s[1] + s[2] + s[3] &&
        s[0] + s[1] + s[2] + s[3] <= 3) {
        s[0] = 0;
        s[1] = 0;
        s[2] = 0;
        s[3] = 0;
        return (1);
    }
    return (0);
}

void unlock_abi(dwd_t *dwd, fight_t *f)
{
    static sfIntRect rect = {48, 0, 48, 40};

    put_unlock_pos(f);
    if (check_gainabi(f) == 1 && move_unlock_bar(f) == 0) {
        for (int i = 0; i != 4; i++) {
            if (f->spell.unlock_spell[i] != 1) {
                sfRenderWindow_drawSprite(dwd->window,
                                        f->spell.unlock[i], NULL);
                sfSprite_setTextureRect(f->spell.unlock[i], rect);
                put_on_red(dwd, f, f->spell.unlock[i], i);
            }
        }
    }
}

int move_unlock_bar(fight_t *f)
{
    static sfTime time;
    static float sec;
    static sfVector2f pos;

    pos = sfSprite_getPosition(f->spell.select_abi);
    time = sfClock_getElapsedTime(f->spell.cunlock);
    sec = time.microseconds / 1000000.0;
    if (sec > 0.02) {
        pos.y = pos.y - 4;
        if (pos.y >= 836) {
            sfSprite_setPosition(f->spell.select_abi, pos);
        }
        else
            return (0);
        sfClock_restart(f->spell.cunlock);
    }
    return (1);
}
