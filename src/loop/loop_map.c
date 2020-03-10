/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** road trip on map
*/

#include "my.h"

void move_map(map_t *map, dwd_t *dwd, fight_t *fight)
{
    sfVector2f pos_player;

    map->time = sfClock_getElapsedTime(map->clock);
    map->scd = map->time.microseconds / 30000.0f;
    if (sfKeyboard_isKeyPressed(dwd->option.key.keybind[3][0]))
        move_map_right(map, fight);
    if (sfKeyboard_isKeyPressed(dwd->option.key.keybind[2][0]))
        move_map_left(map, fight);
    if (sfKeyboard_isKeyPressed(dwd->option.key.keybind[0][0]))
        move_map_up(map, fight);
    if (sfKeyboard_isKeyPressed(dwd->option.key.keybind[1][0]))
        move_map_down(map, fight);
    set_mark(map, dwd, fight);
    pos_player.x = map->perso.p_perso.x + map->perso.mid_screen.x;
    pos_player.y = map->perso.p_perso.y + map->perso.mid_screen.y;
    sfSprite_setPosition(map->perso.s_perso, pos_player);
    sfSprite_setOrigin(map->s_map, map->origin);
}

void events_map(map_t *map, dwd_t *dwd, sfEvent event)
{
    if (event.type == sfEvtKeyReleased
        && (event.key.code == dwd->option.key.keybind[0][0]
            || event.key.code == dwd->option.key.keybind[1][0]
            || event.key.code == dwd->option.key.keybind[2][0]
            || event.key.code == dwd->option.key.keybind[3][0]))
        map->perso.mvmt = 0;
    if (event.type == sfEvtKeyReleased && event.key.code == sfKeyEscape) {
        dwd->is_open = PAUSE;
        dwd->last_open = GAME_MAP;
    }
}

void draw_interface_on_map(dwd_t *dwd, fight_t *f)
{
    sfRenderWindow_drawSprite(dwd->window, f->spell.inventory, NULL);
    sfText_setString(f->spell.text[1], my_itoa_crit(f->cait.spe[1]));
    sfText_setString(f->spell.text[2], my_itoa_crit(f->cait.life_steal));
    for (int i = 0; i != 9; i++) {
        if (i != 1 && i != 2)
            sfText_setString(f->spell.text[i], my_itoa(f->cait.spe[i]));
        sfRenderWindow_drawText(dwd->window, f->spell.text[i], NULL);
    }
    print_money(dwd, f, 2);
    handle_item_map(dwd, f, 2);
    anime_xpbar(dwd, f);
}

void put_on_gameplay_map(map_t *map, dwd_t *dwd, fight_t *fight)
{
    spawn_loop(dwd, fight);
    move_map(map, dwd, fight);
    move_perso(map);
    particules(map, dwd);
    gameplay_loop(dwd, fight, map);
    draw_interface_on_map(dwd, fight);
    victory_condi(dwd, fight);
}

void gameplay_map(map_t *map, dwd_t *dwd, fight_t *fight)
{
    sfEvent event;

    sfMusic_play(dwd->sound.map);
    sfMusic_pause(dwd->sound.menu);
    while (dwd->is_open == GAME_MAP) {
        while (sfRenderWindow_pollEvent(dwd->window, &event))
            events_map(map, dwd, event);
        main_pause(dwd, fight);
        init_quest_one(map, fight);
        if (check_instance_spawn(map) == 0) {
            change_enemy(fight, "TRAIN");
            addapt_to_difficult(dwd, fight);
            dwd->is_open = SHOP;
        }
        put_on_gameplay_map(map, dwd, fight);
        sfRenderWindow_display(dwd->window);
    }
}
