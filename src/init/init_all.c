/*
** EPITECH PROJECT, 2019
** init_all.c
** File description:
** init all in my game
*/

#include "my.h"

void set_frame_rate(dwd_t *dwd)
{
    if (dwd->option.utils.fps_value == 1)
        sfRenderWindow_setFramerateLimit(dwd->window, 30);
    else if (dwd->option.utils.fps_value == 2)
        sfRenderWindow_setFramerateLimit(dwd->window, 60);
    else
        sfRenderWindow_setFramerateLimit(dwd->window, 120);
}

int init_options(dwd_t *dwd, fight_t *f)
{
    f->quest = 0.5;
    init_sound(dwd, f);
    ini_option(dwd);
    init_option(dwd);
    if (init_lore(dwd) == 84)
        return (84);
    if (init_profiles(dwd) == 84)
        return (84);
    init_choose_diff(dwd);
    init_pause(dwd);
    init_keybinding(dwd);
    init_htp(dwd);
    init_report(dwd, f);
    init_rdm_explo(f);
    return (0);
}

void init_map(map_t *map, dwd_t *dwd)
{
    map->tab = create_my_map(map);
    create_my_perso(map);
    create_my_instance(map);
    create_my_minimap(map);
    create_my_markquest(map);
    init_particules(map);
    init_punct(dwd);
    init_quest(dwd);
}

int init_all(dwd_t *dwd, fight_t *f, map_t *map)
{
    if (init_menu(dwd) == 84)
        return (84);
    init_options(dwd, f);
    ini_window(dwd, dwd->option.screen);
    init_spr_spawn(f);
    init_cara(f);
    init_button(dwd);
    init_stat(f);
    init_enemy(f);
    init_abilities(f);
    init_bg_fight(f);
    init_animation(dwd);
    if (init_mouse(dwd) == 84)
        return (84);
    init_cooldown(f);
    init_shop_item(f);
    set_frame_rate(dwd);
    sfMusic_play(dwd->sound.menu);
    init_map(map, dwd);
    return (0);
}
