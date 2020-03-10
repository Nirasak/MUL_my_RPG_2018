/*
** EPITECH PROJECT, 2019
** RPG
** File description:
** display_keybinding
*/

#include "my.h"

void display_all_keybinding(dwd_t *dwd)
{
    sfRenderWindow_drawSprite(dwd->window, dwd->menu.board, NULL);
    for (int i = 0; i != 12; i++) {
        sfRenderWindow_drawText
            (dwd->window, dwd->option.key.text_key[i], NULL);
        sfRenderWindow_drawSprite
            (dwd->window, dwd->option.key.key[i], NULL);
        sfRenderWindow_drawText
            (dwd->window, dwd->option.key.key_t[i], NULL);
    }
    sfRenderWindow_drawText(dwd->window, dwd->option.key.keybinding, NULL);
    sfRenderWindow_drawSprite(dwd->window, dwd->menu.button.confirm, NULL);
    sfRenderWindow_drawText(dwd->window, dwd->menu.button.confirm_t, NULL);
}
