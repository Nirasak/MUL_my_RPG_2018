/*
1;4803;0c** EPITECH PROJECT, 2019
** RPG
** File description:
** discution
*/

#include "my.h"

static void act_button(dwd_t *dwd, fight_t *f)
{
    static int a = 0;

    if (active_button(dwd->menu.button.confirm, dwd->menu.button.confirm_t,
        sfRed, dwd) == 1) {
        dwd->is_open = SHOP;
        if (a == 0) {
            f->quest = f->quest + 1.5;
            a++;
        }
        else if (f->quest == 2)
            f->quest = 3;
        if (f->quest == 9)
            f->quest = 10;
        if (f->quest == 8)
            f->quest = 9;
        if (f->quest == 11)
            f->quest = 12;
    }
}

void discution(dwd_t *dwd, fight_t *f)
{
    display_text(dwd, f);
    while (dwd->is_open == QUEST_DISCUT) {
        while (sfRenderWindow_pollEvent(dwd->window, &dwd->event)) {
            mouse(dwd);
            act_button(dwd, f);
        }
        sfRenderWindow_drawSprite(dwd->window, dwd->quest.background, NULL);
        sfRenderWindow_drawSprite(dwd->window, dwd->menu.board, NULL);
        sfRenderWindow_drawText(dwd->window, dwd->quest.quest, NULL);
        sfRenderWindow_drawText(dwd->window, dwd->quest.text_champ, NULL);
        sfRenderWindow_drawSprite(dwd->window, dwd->menu.button.confirm, NULL);
        sfRenderWindow_drawText(dwd->window, dwd->menu.button.confirm_t, NULL);
        disp_mouse(dwd);
        sfRenderWindow_display(dwd->window);
    }
}
