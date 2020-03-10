/*
** EPITECH PROJECT, 2019
** init_cara.c
** File description:
** init my cara
*/

#include "my.h"

void annex_init_cara(fight_t *f)
{
    sfIntRect rect = {1800, 0, 200, 200};

    sfSprite_setRotation(f->cait.shot, -140);
    f->cait.clock = sfClock_create();
    f->cait.cshot = sfClock_create();
    f->cait.cimpact = sfClock_create();
    sfSprite_setTextureRect(f->cait.sprite, rect);
}

int init_cara(fight_t *f)
{
    sfVector2f origin = {425 / 2, 374 / 2};
    char **path;

    if (extract_data_file("./src/menu/.cara", &path) == 84)
        return (84);
    f->cait.sprite = f_sprite_create("CAIT", path, 200, 550);
    f->cait.impact = f_sprite_create("IMPACT", path, 1420, 690);
    f->cait.shot = f_sprite_create("SHOT", path, 600, 846);
    f->cait.xp = f_sprite_create("XPBAR", path, 0, 1045);
    f->shop.heal = f_sprite_create("HEAL", path, 60, 390);
    f->shop.clock_heal = sfClock_create();
    change_scale(f->cait.xp, 1.2, 1.2);
    change_scale(f->cait.sprite, 1.5, 1.5);
    change_scale(f->cait.impact, 0.05, 0.05);
    change_scale(f->cait.shot, 0.5, 0.5);
    change_scale(f->shop.heal, 2.5, 2.5);
    sfSprite_setOrigin(f->cait.impact, origin);
    annex_init_cara(f);
    init_interface(f);
    return (0);
}

void annex_init_interface(fight_t *f)
{
    change_scale(f->spell.interface, 1.5, 1.5);
    change_scale(f->spell.life, 1.5, 1.5);
    change_scale(f->spell.select_abi, 1.3, 1.3);
    change_scale(f->spell.inventory, 1.2, 1.2);
}

int init_interface(fight_t *f)
{
    static sfIntRect rect = {0, 0, 0, 0};
    static sfIntRect reci = {0, 0, 381, 184};
    char **path;

    if (extract_data_file("./src/menu/.cara", &path) == 84)
        return (84);
    f->spell.interface = f_sprite_create("INTERFACE", path, 550, 880);
    f->spell.inventory = f_sprite_create("INVENTORY", path, 0, 858);
    f->spell.select_abi = f_sprite_create("SELECT", path, 722, 900);
    f->spell.cunlock = sfClock_create();
    f->spell.lvlup = f_sprite_create("LVLUP", path, 50, 700);
    f->spell.life = f_sprite_create("LIFE", path, 650, 1014);
    sfSprite_setTextureRect(f->spell.lvlup, rect);
    sfSprite_setTextureRect(f->cait.shot, rect);
    sfSprite_setTextureRect(f->spell.inventory, reci);
    sfSprite_setTextureRect(f->shop.heal, rect);
    f->spell.clvlup = sfClock_create();
    annex_init_interface(f);
    return (0);
}
