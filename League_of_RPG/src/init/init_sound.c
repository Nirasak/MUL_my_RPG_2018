/*
** EPITECH PROJECT, 2019
** init_sound.c
** File description:
** init all my sounds
*/

#include "my.h"

sfMusic *f_sound_create(char *obj, char **tab, sfBool i, int volume)
{
    sfMusic *s;
    char *path = find_obj(tab, obj);

    if (path == NULL)
        return (NULL);
    s = sfMusic_createFromFile(path);
    sfMusic_setVolume(s, volume);
    sfMusic_setLoop(s, i);
    return (s);
}

int init_sound(dwd_t *dwd, fight_t *f)
{
    char **path;

    dwd->sound.music_vol = extract_saved_value("mus.vol", dwd->menu.data);
    dwd->sound.effect_vol = extract_saved_value("sound.vol", dwd->menu.data);
    if (extract_data_file("./src/menu/.sound", &path) == 84)
        return (84);
    f->cait.shot_sound = f_sound_create
        ("SHOT", path, sfFalse, dwd->sound.effect_vol);
    f->cait.lvlup = f_sound_create("UP", path, sfFalse, dwd->sound.effect_vol);
    dwd->sound.menu = f_sound_create
        ("MENU", path, sfTrue, dwd->sound.music_vol);
    dwd->sound.boss = f_sound_create
        ("BOSS", path, sfTrue, dwd->sound.music_vol);
    dwd->sound.fight = f_sound_create
        ("FIGHT", path, sfTrue, dwd->sound.music_vol);
    dwd->sound.map = f_sound_create
        ("MAP", path, sfTrue, dwd->sound.music_vol);
    dwd->sound.click = f_sound_create
        ("CLICK", path, sfFalse, dwd->sound.effect_vol);
    return (0);
}
