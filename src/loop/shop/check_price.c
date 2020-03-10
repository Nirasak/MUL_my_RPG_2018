/*
** EPITECH PROJECT, 2019
** check_price.c
** File description:
** check if the price of my item is lower than my budget
*/

#include "my.h"

void check_price(fight_t *f, int i, int *buy)
{
    if (my_atoi(return_price(f->shop.text_item[i + 1]))
        <= f->cait.spe[8])
        *buy = my_atoi(return_price(f->shop.text_item[i + 1]));
    else
        *buy = 0;
}
