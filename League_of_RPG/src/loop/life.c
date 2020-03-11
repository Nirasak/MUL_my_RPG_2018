/*
** EPITECH PROJECT, 2019
** life.c
** File description:
** handle my life
*/

#include "my.h"

int anime_healing(fight_t *f, int *i)
{
    static sfTime time;
    static float sec;
    static sfIntRect rect = {0, 0, 190, 190};

    time = sfClock_getElapsedTime(f->shop.clock_heal);
    sec = time.microseconds / 1000000.0;
    if (sec > 0.12) {
        rect.left = rect.left + 190;
        sfSprite_setTextureRect(f->shop.heal, rect);
        sfClock_restart(f->shop.clock_heal);
        if (rect.left >= 3168) {
            rect.left = 0;
            *i = 0;
            return (0);
        }
    }
    return (1);
}

int gain_life(dwd_t *dwd, fight_t *f)
{
    static int i = 0;

    if (sfKeyboard_isKeyPressed(dwd->option.key.keybind[8][0]) &&
        f->shop.life_popo != 0 && f->cait.spe[9] != f->cait.spe[10] && i == 0
        && f->spell.cooldown[4] == 0) {
        f->cait.spe[9] = f->cait.spe[9] + f->shop.life_popo;
        i++;
        if (f->cait.spe[9] > f->cait.spe[10])
            f->cait.spe[9] = f->cait.spe[10];
        f->spell.cooldown[4] = 3;
    }
    if (i == 1)
        return (anime_healing(f, &i));
    return (1);
}

void rect_life(sfSprite *spr, int got, int max)
{
    static sfIntRect rect = {0, 0, 407, 36};
    float live = got;
    float live2 = max;
    float result = 0;

    result = (live / live2) * 407;
    rect.width = (float)result;
    sfSprite_setTextureRect(spr, rect);
}

void draw_life(dwd_t *dwd, fight_t *f)
{
    sfVector2f pos1 = {900, 1020};
    sfVector2f pos2 = {980, 1020};

    if (f->cait.spe[9] >= f->cait.spe[10])
        f->cait.spe[9] = f->cait.spe[10];
    if (f->cait.spe[9] < f->cait.spe[10])
        sfText_setColor(f->spell.text[9], sfRed);
    else
        sfText_setColor(f->spell.text[9], sfWhite);
    sfText_setPosition(f->spell.text[9], pos1);
    sfText_setPosition(f->spell.text[10], pos2);
    sfText_setCharacterSize(f->spell.text[9], 40);
    sfText_setCharacterSize(f->spell.text[10], 40);
    rect_life(f->spell.life, f->cait.spe[9], f->cait.spe[10]);
    gain_life(dwd, f);
    sfRenderWindow_drawSprite(dwd->window, f->spell.life, NULL);
}

void draw_enemy_life(fight_t *f)
{
    rect_life(f->enemy.life_enemy, f->enemy.actual_life, f->enemy.max_life);
    if (f->enemy.actual_life >= f->enemy.max_life)
        f->enemy.actual_life = f->enemy.max_life;
}
