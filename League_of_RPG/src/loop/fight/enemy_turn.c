/*
** EPITECH PROJECT, 2019
** enemy_turn.c
** File description:
** create my enemy turn
*/

#include "my.h"

void big_attack(fight_t *f, int *turn, int *wich, int *a)
{
    if (enemy_second_attack(f) == 0) {
        *wich = 1;
        *turn = 3;
        *a = 0;
    }
}

void enemy_turn(fight_t *f, int *i)
{
    static int a = 0;
    static int wich = 0;
    static int turn = 3;

    if (a == 0) {
        wich = randomm(1, 3);
        a = 1;
    }
    if (wich == 2 && turn <= 0)
        big_attack(f, &turn, &wich, &a);
    else
        if (enemy_basic_attack(f) == 0) {
            *i = 1;
            turn--;
            a = 0;
        }
}
