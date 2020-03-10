/*
** EPITECH PROJECT, 2019
** RPG
** File description:
** music_bar
*/

#include "my.h"

static void active_effect(dwd_t *dwd, sfVector2f ps, fight_t *f)
{
    dwd->sound.effect_vol = ((dwd->mouse.mouse_pos.x - ps.x) / 2.3) / 4.7;
    if (dwd->sound.effect_vol > 100)
        dwd->sound.effect_vol = 100;
    if (dwd->sound.effect_vol < 0)
        dwd->sound.effect_vol = 0;
    sfMusic_setVolume(dwd->sound.click, dwd->sound.effect_vol);
    sfMusic_setVolume(f->cait.lvlup, dwd->sound.effect_vol);
    sfMusic_setVolume(f->cait.shot_sound, dwd->sound.effect_vol);
    sfMusic_play(dwd->sound.click);
}

static void active_music(dwd_t *dwd, sfVector2f ps)
{
    dwd->sound.music_vol = ((dwd->mouse.mouse_pos.x - ps.x) / 2.3) / 4.7;
    if (dwd->sound.music_vol > 100)
        dwd->sound.music_vol = 100;
    if (dwd->sound.music_vol < 0)
        dwd->sound.music_vol = 0;
    sfMusic_setVolume(dwd->sound.menu, dwd->sound.music_vol);
    sfMusic_setVolume(dwd->sound.boss, dwd->sound.music_vol);
    sfMusic_setVolume(dwd->sound.fight, dwd->sound.music_vol);
    sfMusic_setVolume(dwd->sound.map, dwd->sound.music_vol);
}

void active_music_bar(sfSprite *sprite, dwd_t *dwd)
{
    sfVector2f ps = sfSprite_getPosition(sprite);
    sfIntRect rect = {0, 0, 407, 19};
    static int push = 0;

    if (dwd->event.type == sfEvtMouseButtonReleased)
        push = 0;
    if (dwd->event.type == sfEvtMouseButtonPressed &&
        dwd->mouse.pos.x > ps.x &&
        dwd->mouse.pos.x < ps.x + 936.1 &&
        dwd->mouse.pos.y > ps.y &&
        dwd->mouse.pos.y < ps.y + 43.7) {
        push = 1;
    }
    if (push == 1) {
        rect.width = (dwd->mouse.mouse_pos.x - ps.x) / 2.3;
        rect.width < 0 ? rect.width = 0 : 0;
        rect.width > 407 ? rect.width = 407 : 0;
        sfSprite_setTextureRect(sprite, rect);
        active_music(dwd, ps);
    }
}

void active_sound_bar(sfSprite *sprite, dwd_t *dwd, fight_t *f)
{
    sfVector2f ps = sfSprite_getPosition(sprite);
    sfIntRect rect = {0, 0, 407, 19};
    static int push = 0;

    if (dwd->event.type == sfEvtMouseButtonReleased)
        push = 0;
    if (dwd->event.type == sfEvtMouseButtonPressed &&
        dwd->mouse.pos.x > ps.x &&
        dwd->mouse.pos.x < ps.x + 936.1 &&
        dwd->mouse.pos.y > ps.y &&
        dwd->mouse.pos.y < ps.y + 43.7) {
        push = 1;
    }
    if (push == 1) {
        rect.width = (dwd->mouse.mouse_pos.x - ps.x) / 2.3;
        rect.width < 0 ? rect.width = 0 : 0;
        rect.width > 407 ? rect.width = 407 : 0;
        sfSprite_setTextureRect(sprite, rect);
        active_effect(dwd, ps, f);
    }
}
