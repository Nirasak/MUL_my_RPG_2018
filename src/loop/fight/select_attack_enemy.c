/*
1;4803;0c** EPITECH PROJECT, 2019
** select_attack_enemy.c
** File description:
** create my function for my diferents types of attack
*/

#include "my.h"

int enemy_basic_attack(fight_t *f)
{
    static int a = 0;
    static sfVector2f reset;

    if (a == 0) {
        reset = f->enemy.pos_attack;
        a++;
    }
    anime_attack_enemy(f);
    return (move_attack_enemy(f, &reset, &a));
}

int enemy_second_attack(fight_t *f)
{
    static int a = 0;
    static sfVector2f reset;

    if (a == 0) {
        reset = f->enemy.pos_attacktwo;
        a++;
    }
    anime_attacktwo_enemy(f);
    return (move_attacktwo_enemy(f, &reset, &a));
}
