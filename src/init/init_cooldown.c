/*
** EPITECH PROJECT, 2019
** init_cooldown.c
** File description:
** init my cooldown
*/

#include "my.h"

void init_cooldown(fight_t *f)
{
    sfFont *font;
    sfVector2f pos = {750, 930};

    font = sfFont_createFromFile("./assets/cara/font.otf");
    f->spell.cooldown_text = malloc(sizeof(sfText *) * 6);
    f->spell.cooldown = malloc(sizeof(int) * 6);
    for (int i = 0; i != 5; i++) {
        f->spell.cooldown[i] = 0;
        f->spell.cooldown_text[i] = sfText_create();
        sfText_setFont(f->spell.cooldown_text[i], font);
        sfText_setColor(f->spell.cooldown_text[i], sfWhite);
        sfText_setPosition(f->spell.cooldown_text[i], pos);
        sfText_setCharacterSize(f->spell.cooldown_text[i], 40);
        pos.x = pos.x + 76;
    }
    sfText_setCharacterSize(f->spell.cooldown_text[4], 30);
    f->spell.cooldown[4] = 0;
    pos.x = pos.x - 60;
    pos.y = pos.y + 10;
    sfText_setPosition(f->spell.cooldown_text[4], pos);
}
