/*
** EPITECH PROJECT, 2019
** hitbox_shop.c
** File description:
** create my hitbox for my items
*/

#include "my.h"

int general_hitboxfunc(dwd_t *dwd, sfVector2f posmin,
                       sfVector2f posmax, sfSprite *sprite)
{
    sfVector2f mouse = dwd->mouse.pos;

    if (mouse.x > posmin.x && mouse.x < posmax.x &&
        mouse.y > posmin.y && mouse.y < posmax.y) {
        sfSprite_setPosition(sprite, posmin);
        sfRenderWindow_drawSprite(dwd->window, sprite, NULL);
        return (1);
    }
    return (0);
}

void change_rect_and_text(fight_t *f, int i, int *left)
{
    *left = 557 * i;
    sfText_setString(f->shop.text[0], cut_str(f->shop.text_item[i + 1]));
    sfText_setString(f->shop.text[1], get_cut_str(f->shop.text_item[i + 1]));
    sfText_setString(f->shop.text[2], get_and_str(f->shop.text_item[i + 1]));
    sfText_setString(f->shop.text[3], return_price(f->shop.text_item[i + 1]));
}

void handle_item_bar(fight_t *f, int left, int *nb)
{
    static sfIntRect rect = {0, 0, 480, 480};
    int stock = 0;

    for (; left > 0; left = left - 557)
        stock++;
    rect.left = 480 * stock;
    if (stock >= 3) {
        sfSprite_setTextureRect(f->shop.item[*nb], rect);
        add_buff_item(f, stock + 1);
        (*nb)++;
    }
    else {
        sfSprite_setTextureRect(f->shop.popo, rect);
        add_buff_item(f, stock + 1);
    }
}

int buy_function(dwd_t *dwd, fight_t *f, int *buy)
{
    static sfIntRect rect = {0, 0, 247, 80};
    sfVector2f pos = dwd->mouse.pos;

    sfRenderWindow_drawSprite(dwd->window, f->shop.buy, NULL);
    if (pos.x > 1175 && pos.x < 1412 &&
        pos.y > 818 && pos.y < 892) {
        rect.left = 248;
        if (dwd->event.type == sfEvtMouseButtonPressed) {
            f->cait.spe[8] = f->cait.spe[8] - *buy;
            *buy = 0;
            return (1);
        }
    }
    else
        rect.left = 0;
    sfSprite_setTextureRect(f->shop.buy, rect);
    return (0);
}

void check_hitbox(dwd_t *dwd, fight_t *f)
{
    static sfIntRect rect = {0, 0, 557, 830};
    static int buy = 0;

    sfRenderWindow_drawSprite(dwd->window, f->shop.zoom, NULL);
    for (int i = 0; i != 13; i++)
        if (general_hitboxfunc(dwd, f->shop.posmin[i],
                               f->shop.posmax[i], f->shop.hover_item) == 1) {
            change_rect_and_text(f, i, &rect.left);
            sfSprite_setTextureRect(f->shop.zoom, rect);
            check_price(f, i, &buy);
        }
    if (f->shop.nb_item < 6 && buy != 0 && buy_function(dwd, f, &buy) == 1)
        handle_item_bar(f, rect.left, &f->shop.nb_item);
    for (int i = 0; i != 4; i++)
        sfRenderWindow_drawText(dwd->window, f->shop.text[i], NULL);
    print_money(dwd, f, 1);
    handle_item(dwd, f, 1);
}
