/*
** EPITECH PROJECT, 2019
** loop.c
** File description:
** create my_gameloop.c
*/

#include "my.h"

void events(dwd_t *dwd)
{
    if (dwd->event.type == sfEvtKeyReleased &&
        dwd->event.key.code == sfKeyEscape) {
        dwd->is_open = PAUSE;
        dwd->last_open = GAMEPLAY;
    }
    mouse(dwd);
}

sfSprite *check_bg(fight_t *f)
{
    if (f->quest != 7)
        return (f->bgf.jungle);
    return (f->bgf.cave);
}

void spawn_loop(dwd_t *dwd, fight_t *f)
{
    while (dwd->is_open != LEAVE && dwd->menu.profile.played == 0 &&
           anime_animation(dwd) != 1);
    while (dwd->is_open == SHOP) {
        dwd->shop_back = SHOP;
        while (sfRenderWindow_pollEvent(dwd->window, &dwd->event)) {
            if (active_button(dwd->menu.button.map, dwd->menu.button.map_t,
                sfRed, dwd) == 1) {
                dwd->is_open = GAME_MAP;
            }
            events(dwd);
        }
        draw_spawn(dwd, f);
        disp_mouse(dwd);
        main_pause(dwd, f);
        sfRenderWindow_display(dwd->window);
    }
    dwd->shop_back = LEAVE;
}

void gameplay_loop(dwd_t *dwd, fight_t *f, map_t *map)
{
    int x = 1;

    while (dwd->is_open != LEAVE && dwd->menu.profile.played == 0 &&
           anime_animation(dwd) != 1);
    while (dwd->is_open == GAMEPLAY) {
        while (sfRenderWindow_pollEvent(dwd->window, &dwd->event))
            events(dwd);
        x = fight(dwd, f, check_bg(f));
        if (x == 0)
            win_fight(dwd, f, map);
        if (x == 2)
            lose_fight(dwd, f, map);
        disp_mouse(dwd);
        main_pause(dwd, f);
        explo_left(f, dwd->window);
        explo_right(f, dwd->window);
        sfRenderWindow_display(dwd->window);
    }
}
