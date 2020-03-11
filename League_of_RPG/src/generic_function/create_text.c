/*
** EPITECH PROJECT, 2019
** RPG
** File description:
** create_text
*/

#include "my.h"

void pos_button_text(sfText **text, sfSprite *button, char *obj)
{
    sfVector2f pos_sprite = sfSprite_getPosition(button);
    int len = my_strlen(obj);

    for (int i = 0; obj[i] != '\0'; i++) {
        if (obj[i] == 'm' || obj[i] == 'w') {
            pos_sprite.x -= 20;
            break;
        }
    }
    if (my_strcmp("Lore", obj) == 0 || my_strcmp("Play", obj) == 0) {
        pos_sprite.x += 150 - ((len - 3) * 16);
        sfText_setPosition(*text, pos_sprite);
        return;
    }
    pos_sprite.x += 150;
    (len > 3 && len < 6) ? pos_sprite.x -= ((len - 3) * 20) : 0;
    (len == 4) ? pos_sprite.x -= 20 : 0;
    (len >= 6) ? pos_sprite.x -= ((len - 3) * 25) : 0;
    sfText_setPosition(*text, pos_sprite);
}

sfText *create_button_text(char *my_font, char *my_text,
                            int size, sfColor color)
{
    sfFont *font = sfFont_createFromFile(my_font);
    sfText *text = sfText_create();

    sfText_setFont(text, font);
    sfText_setColor(text, color);
    sfText_setCharacterSize(text, size);
    sfText_setString(text, my_text);
    return (text);
}

void pos_text(sfText *text, int x, int y)
{
    sfVector2f pos_text;

    pos_text.x = x;
    pos_text.y = y;
    sfText_setPosition(text, pos_text);
}
