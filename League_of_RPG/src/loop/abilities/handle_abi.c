/*
** EPITECH PROJECT, 2019
** handle_abi.c
** File description:
** handle all my abilities
*/

#include "my.h"

int handle_trap(dwd_t *dwd, fight_t *f)
{
    if (anime_trap(dwd, f) == 1) {
        no_crit_shot(f, (f->cait.spe[0] / 2) -
                    f->enemy.defense, &f->enemy.actual_life);
        put_text_on_enemy(f);
        return (0);
    }
    return (1);
}

int handle_qspell(dwd_t *dwd, fight_t *f)
{
    static int active = 0;
    static sfVector2f pos;

    for (int i = 0; i != 12; i++)
    if (f->spell.unlock_spell[0] == 1 &&
        sfKeyboard_isKeyPressed(dwd->option.key.keybind[4][0])
        && f->spell.cooldown[0] == 0) {
        if (active == 0) {
            pos.x = 300;
            pos.y = 600;
        }
        active = 1;
    }
    if (active == 1)
        return (first_spell(dwd, f, &pos, &active));
    return (1);
}

int handle_espell(dwd_t *dwd, fight_t *f)
{
    static int active = 0;

    if (f->spell.unlock_spell[2] == 1 &&
        sfKeyboard_isKeyPressed(dwd->option.key.keybind[6][0])
        && f->spell.cooldown[2] == 0) {
        active = 1;
    }
    if (active == 1) {
        if (third_spell(dwd, f) == 0) {
            active = 0;
            return (0);
        }
    }
    return (1);
}

int handle_ult(dwd_t *dwd, fight_t *f)
{
    static int active = 0;
    sfVector2f pos = pos_cait_corp(f);

    if (f->spell.unlock_spell[3] == 1 &&
        sfKeyboard_isKeyPressed(dwd->option.key.keybind[7][0])
        && f->spell.cooldown[3] == 0) {
        sfSprite_setPosition(f->spell.abilities[3], pos);
        active = 1;
    }
    if (active == 1) {
        if (last_spell(f) == 0) {
            active = 0;
            return (0);
        }
    }
    sfRenderWindow_drawSprite(dwd->window, f->spell.abilities[3], NULL);
    return (1);
}
