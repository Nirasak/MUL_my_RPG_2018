/*
** EPITECH PROJECT, 2019
** shop.c
** File description:
** create all my functions for my shop
*/

#include "my.h"

int display_shop(dwd_t *dwd, fight_t *f)
{
    sfVector2f pos = dwd->mouse.pos;
    static sfIntRect rect = {0, 0, 381, 184};

    if (pos.x >= 214 && pos.x <= 359 && pos.y >= 1032 && pos.y < 1070) {
        rect.left = 382;
        sfSprite_setTextureRect(f->spell.inventory, rect);
        if (dwd->event.type == sfEvtMouseButtonPressed)
            return (0);
    }
    if (dwd->event.key.code == dwd->option.key.keybind[9][0])
        return (0);
    else
        rect.left = 0;
    sfSprite_setTextureRect(f->spell.inventory, rect);
    return (1);
}

int check_return(dwd_t *dwd, fight_t *f)
{
    sfVector2f pos = dwd->mouse.pos;

    if (pos.x >= 1544 && pos.x <= 1585 && pos.y > 75 && pos.y < 120) {
        sfRenderWindow_drawSprite(dwd->window, f->shop.close_hover, NULL);
        if (dwd->event.type == sfEvtMouseButtonPressed)
            return (0);
    }
    return (1);
}

void print_money(dwd_t *dwd, fight_t *f, int i)
{
    sfVector2f pos;

    if (i == 1) {
        pos.x = 990;
        pos.y = 66;
        sfText_setPosition(f->spell.text[8], pos);
        sfText_setCharacterSize(f->spell.text[8], 50);
    }
    if (i == 2) {
        pos.x = 275;
        pos.y = 1037;
        sfText_setPosition(f->spell.text[8], pos);
        sfText_setCharacterSize(f->spell.text[8], 25);
    }
    sfText_setString(f->spell.text[8], my_itoa(f->cait.spe[8]));
    sfRenderWindow_drawText(dwd->window, f->spell.text[8], NULL);
}

void draw_and_anime_shop(dwd_t *dwd, fight_t *f)
{
    anime_karma(f);
    anime_gnar(f);
    sfRenderWindow_drawSprite(dwd->window, f->shop.shop, NULL);
    sfRenderWindow_drawSprite(dwd->window, f->shop.karma, NULL);
    sfRenderWindow_drawSprite(dwd->window, f->shop.gnar, NULL);
}

void shop_loop(dwd_t *dwd, fight_t *f)
{
    if (display_shop(dwd, f) != 0)
        return;
    while (sfRenderWindow_isOpen(dwd->window)) {
        draw_and_anime_shop(dwd, f);
        check_hitbox(dwd, f);
        while (sfRenderWindow_pollEvent(dwd->window, &dwd->event)) {
            mouse(dwd);
            if (dwd->event.key.code == sfKeyEscape)
                return;
        }
        if (check_return(dwd, f) == 0)
            break;
        disp_mouse(dwd);
        sfRenderWindow_display(dwd->window);
    }
}
