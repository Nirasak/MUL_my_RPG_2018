/*
** EPITECH PROJECT, 2019
** text_hit.c
** File description:
** create my text when i'm hit
*/

#include "my.h"

int anime_text(sfText *text, int *i)
{
    static int size;

    if (*i == 0) {
        size = sfText_getCharacterSize(text);
    }
    if ((*i) <= size) {
        sfText_setCharacterSize(text, size - (*i));
        (*i)++;
    }
    else
        return (1);
    return (0);
}

void move_text_hit(fight_t *f)
{
    static sfTime time;
    static float sec;
    static int i = 0;
    sfVector2f pos = sfText_getPosition(f->spawn.text);

    time = sfClock_getElapsedTime(f->spawn.clocke);
    sec = time.microseconds / 1000000.0;
    if (sec > 0.02) {
        move_text(f, &pos, &i);
    }
}

void put_text_on_enemy(fight_t *f)
{
    sfVector2f pos;
    sfVector2f scl = sfSprite_getScale(f->enemy.enemy);

    sfText_setCharacterSize(f->spawn.text, f->enemy.resetscl);
    pos = sfSprite_getPosition(f->enemy.enemy);
    pos.x = pos.x + ((float)f->enemy.rect.width / 2) * scl.x;
    pos.y = pos.y + ((float)f->enemy.rect.height / 2) * scl.y;
    sfText_setPosition(f->spawn.text, pos);
}
