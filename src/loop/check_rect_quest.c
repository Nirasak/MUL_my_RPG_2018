/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** check rect quest
*/

#include "my.h"

int check_rect_quest(sfSprite *sprite)
{
    sfVector2f pos = sfSprite_getPosition(sprite);
    sfVector2i pos_mouse = sfMouse_getPosition(NULL);
    sfIntRect rect = sfSprite_getTextureRect(sprite);

    if (pos_mouse.x >= pos.x && pos_mouse.x <= pos.x + rect.width / 2
        && pos_mouse.y >= pos.y && pos_mouse.y <= pos.y + rect.height)
        return (1);
    return (0);
}

void draw_ponct(float i, dwd_t *dwd)
{
    if (i == 2 || i == 9)
        sfRenderWindow_drawSprite(dwd->window, dwd->quest.s_excla, NULL);
    if (i == 0.5 || i == 8 || i == 11)
        sfRenderWindow_drawSprite(dwd->window, dwd->quest.s_inter, NULL);
}

void print_quest(dwd_t *dwd, fight_t *f)
{
    sfVector2f pos;

    if (f->quest <= 12) {
        draw_ponct(f->quest, dwd);
        pos = sfSprite_getPosition(dwd->quest.rammus);
        pos.x = pos.x + 50;
        pos.y = pos.y - 200;
        markquest_setplace(dwd, pos.x, pos.y);
        if (check_rect_quest(dwd->quest.rammus) == 1) {
            dwd->is_open = QUEST_DISCUT;
            discution(dwd, f);
        }
    }
}
