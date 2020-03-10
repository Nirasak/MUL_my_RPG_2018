/*
** EPITECH PROJECT, 2019
** init_spawn.c
** File description:
** init my spawn in game
*/

#include "my.h"

void init_punct(dwd_t *dwd)
{
    char **path;

    extract_data_file("./src/menu/.spawn", &path);
    dwd->quest.s_excla = f_sprite_create("EXCLA", path, -1000, -1000);
    dwd->quest.s_inter = f_sprite_create("INTER", path, -1000, -1000);
    dwd->quest.garen = f_sprite_create("GAREN", path, 1100, 480);
    dwd->quest.rammus = f_sprite_create("RAMMUS", path, 450, 430);
    dwd->quest.c_garen = sfClock_create();
    dwd->quest.c_rammus = sfClock_create();
    change_scale(dwd->quest.s_excla, 5, 5);
    change_scale(dwd->quest.garen, 1.7, 1.7);
}

int init_spr_spawn(fight_t *f)
{
    char **path;

    if (extract_data_file("./src/menu/.spawn", &path) == 84)
        return (84);
    f->spawn.bg = f_sprite_create("BACKGROUND", path, 0, 0);
    f->spawn.rock = f_sprite_create("ROCK", path, 0, 0);
    f->spawn.bush = f_sprite_create("BUSH", path, 0, 0);
    f->spawn.poro = f_sprite_create("PORO", path, 1310, 680);
    f->spawn.rporo = f_sprite_create("RPORO", path, 1000, 630);
    f->spawn.tamo = f_sprite_create("TAMO", path, 2000, 480);
    f->shop.shop = f_sprite_create("SHOP", path, 0, 0);
    f->shop.close_hover = f_sprite_create("CLOSE_SHOP", path, 1545, 77);
    f->shop.karma = f_sprite_create("KARMA", path, 1500, 440);
    f->shop.hover_item = f_sprite_create("HOVER_ITEM", path, 0, 0);
    f->shop.zoom = f_sprite_create("ZOOM", path, 1015, 139);
    f->shop.buy = f_sprite_create("BUY", path, 1170, 817);
    f->shop.gnar = f_sprite_create("GNAR", path, 0, 780);
    init_else_spawn(f);
    init_hitbox_shop(f);
    return (0);
}

void init_else_spawn(fight_t *f)
{
    static sfIntRect rect = {0, 0, 0, 0};

    sfSprite_setTextureRect(f->shop.zoom, rect);
    sfSprite_setTextureRect(f->shop.buy, rect);
    change_scale(f->spawn.poro, 0.9, 0.9);
    change_scale(f->spawn.rporo, 0.3, 0.3);
    change_scale(f->spawn.tamo, 0.2, 0.2);
    change_scale(f->shop.karma, 0.8, 0.8);
    f->spawn.clock = malloc(sizeof(sfClock *) * 4);
    f->spawn.clock[0] = sfClock_create();
    f->spawn.clock[1] = sfClock_create();
    f->spawn.clock[2] = sfClock_create();
    f->spawn.shoot = 0;
    f->spawn.clocke = sfClock_create();
    f->shop.clock_karma = sfClock_create();
    f->shop.clock_gnar = sfClock_create();
}
