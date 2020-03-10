/*
** EPITECH PROJECT, 2019
** handle_stun.c
** File description:
** create a function who handle my stun
*/

#include "my.h"

void anime_stun(dwd_t *dwd, fight_t *f)
{
    static sfIntRect rect = {0, 0, 960, 600};
    static sfTime time;
    static float sec;

    time = sfClock_getElapsedTime(f->spell.clock_stun);
    sec = time.microseconds / 1000000.0;
    if (sec > 0.2) {
        rect.left = rect.left + 960;
        sfSprite_setTextureRect(f->spell.stun, rect);
        sfClock_restart(f->spell.clock_stun);
        if (rect.left >= 8640)
            rect.left = 0;
    }
    sfRenderWindow_drawSprite(dwd->window, f->spell.stun, NULL);
}

int end_trap(fight_t *f, int *use, sfIntRect *rect)
{
    if (rect->top > 300) {
        *use = 0;
        rect->top = -100;
        sfSprite_setTextureRect(f->spell.abilities[1], *rect);
        return (1);
    }
    return (0);
}

int anime_trap(dwd_t *dwd, fight_t *f)
{
    static sfIntRect rect = {0, -100, 200, 100};
    static sfTime time;
    static float sec;
    static int use = 0;

    time = sfClock_getElapsedTime(f->spell.clock_abi[1]);
    sec = time.microseconds / 1000000.0;
    if (sfKeyboard_isKeyPressed(dwd->option.key.keybind[5][0])
        && f->spell.unlock_spell[1] == 1 && f->spell.cooldown[1] == 0)
        use = 1;
    if (use == 1 && sec > 0.07 && rect.top <= 300) {
        rect.top = rect.top + 100;
        sfSprite_setTextureRect(f->spell.abilities[1], rect);
        sfClock_restart(f->spell.clock_abi[1]);
    }
    sfRenderWindow_drawSprite(dwd->window, f->spell.abilities[1], NULL);
    return (end_trap(f, &use, &rect));
}
