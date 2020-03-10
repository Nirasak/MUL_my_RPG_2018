/*
** EPITECH PROJECT, 2019
** fight_loop.c
** File description:
** create my loop of fights for my game
*/

#include "my.h"

void reset_shield(fight_t *f)
{
    static int i = 0;

    if (f->spell.cooldown[2] != 2)
        i = 0;
    if (i == 0 && f->spell.cooldown[2] == 2)
        delete_buff_shield(f, &i);
}

void cait_turn_again(dwd_t *dwd, fight_t *f, int *i)
{
    if (handle_espell(dwd, f) == 0) {
        decrease_when_espell(f);
        *i = 2;
        f->spell.cooldown[2] = 4;
    }
    if (handle_ult(dwd, f) == 0) {
        decrease_when_rspell(f);
        *i = 2;
        f->spell.cooldown[3] = 6;
    }
    if (gain_life(dwd, f) == 0) {
        decrease_when_popo(f);
        *i = 2;
        f->spell.cooldown[4] = 3;
    }
}

void cait_turn(dwd_t *dwd, fight_t *f, int *i)
{
    if (normal_attack(dwd, f) == 0) {
        decrease_cooldown(f);
        *i = 2;
    }
    if (handle_qspell(dwd, f) == 0) {
        decrease_when_qspell(f);
        f->spell.cooldown[0] = 2;
        *i = 2;
    }
    if (handle_trap(dwd, f) == 0) {
        decrease_when_zspell(f);
        f->stun = 1;
        f->spell.cooldown[1] = 3;
    }
    reset_shield(f);
    cait_turn_again(dwd, f, i);
}

void loop_fight(dwd_t *dwd, fight_t *f)
{
    static int player = 1;

    if (player == 1) {
        cait_turn(dwd, f, &player);
    }
    if (player == 2) {
        f->stun = 0;
        wait_loop(f);
        enemy_turn(f, &player);
    }
    move_text_hit(f);
    if (f->stun == 1) {
        anime_stun(dwd, f);
    }
}
