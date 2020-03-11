/*
** EPITECH PROJECT, 2019
** item.c
** File description:
** handle all my items
*/

#include "my.h"

void draw_item_on_bar(fight_t *f, int stat)
{
    sfVector2f pos = {363, 930};

    for (int i = 0; stat == 1 && i != 6; i++) {
        change_scale(f->shop.item[i], 0.12, 0.12);
        sfSprite_setPosition(f->shop.item[i], pos);
        pos.x = pos.x + 65;
    }
    pos.x = 212;
    pos.y = 928;
    for (int i = 0; stat == 2 &&  i != 6; i++) {
        if (i == 3) {
            pos.x = 212;
            pos.y = 980;
        }
        change_scale(f->shop.item[i], 0.10, 0.10);
        sfSprite_setPosition(f->shop.item[i], pos);
        pos.x = pos.x + 52;
    }
}

void handle_item(dwd_t *dwd, fight_t *f, int status)
{
    draw_item_on_bar(f, status);
    for (int i = 0; i < 6 && i != f->shop.nb_item; i++) {
        sfRenderWindow_drawSprite(dwd->window, f->shop.item[i], NULL);
    }
    if (status == 2 && f->spell.cooldown[4] == 0)
        sfRenderWindow_drawSprite(dwd->window, f->shop.popo, NULL);
}

void handle_item_map(dwd_t *dwd, fight_t *f, int status)
{
    draw_item_on_bar(f, status);
    for (int i = 0; i < 6 && i != f->shop.nb_item; i++) {
        sfRenderWindow_drawSprite(dwd->window, f->shop.item[i], NULL);
    }
}

void add_buff_item(fight_t *f, int item)
{
    if (item <= 3)
        buff_popo(f, return_stat_item(f->shop.text_item[item]));
    if (item > 3 && item <= 7)
        buff_speed(f, return_stat_item(f->shop.text_item[item]));
    if (item == 10 || item == 8)
        buff_crit(f, return_stat_item(f->shop.text_item[item]));
    if (item == 11)
        buff_lifesteal(f, return_stat_item(f->shop.text_item[item]));
    if (item == 12 || item == 13)
        buff_dmg(f, return_stat_item(f->shop.text_item[item]));
    if (item == 9)
        buff_extra_turn(f, return_stat_item(f->shop.text_item[item]));
}
