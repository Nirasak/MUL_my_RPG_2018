/*
** EPITECH PROJECT, 2019
** init_stat.c
** File description:
** init all my stat for my game
*/

#include "my.h"

void annex_create_stat(fight_t *f, sfFont *font, sfVector2f pos)
{
    for (int i = 0; i != 11; i++) {
        f->cait.spe[i] = 0;
        f->spell.text[i] = sfText_create();
        sfText_setFont(f->spell.text[i], font);
        sfText_setColor(f->spell.text[i], sfWhite);
        sfText_setPosition(f->spell.text[i], pos);
        sfText_setCharacterSize(f->spell.text[i], 25);
        pos.y = pos.y + 23;
    }
}

void create_stat(fight_t *f)
{
    sfFont *font;
    sfVector2f pos;

    font = sfFont_createFromFile("./assets/cara/font.otf");
    f->spawn.text = sfText_create();
    sfText_setFont(f->spawn.text, font);
    sfText_setColor(f->spawn.text, sfBlack);
    sfText_setCharacterSize(f->spawn.text, 50);
    f->cait.spe = malloc(sizeof(int) * 12);
    f->spell.text = malloc(sizeof(sfText *) * 11);
    annex_create_stat(f, font, pos);
    pos.x = 160;
    pos.y = 922;
    annex_create_stat(f, font, pos);
    sfText_setColor(f->spell.text[8], sfYellow);
}

void init_second_stat(fight_t *f)
{
    f->cait.spe[5] = change_basic_stat_enemy("MAGICRESIST",
                                            "./src/menu/.stat_cait");
    f->cait.spe[6] = change_basic_stat_enemy("LEVEL",
                                            "./src/menu/.stat_cait");
    f->cait.spe[8] = change_basic_stat_enemy("GOLD",
                                            "./src/menu/.stat_cait");
    f->cait.spe[9] = change_basic_stat_enemy("HP",
                                            "./src/menu/.stat_cait");
    f->cait.spe[10] = change_basic_stat_enemy("HPMAX",
                                            "./src/menu/.stat_cait");
}

void init_stat(fight_t *f)
{
    create_stat(f);
    f->cait.spe[0] = change_basic_stat_enemy("ATK",
                                            "./src/menu/.stat_cait");
    f->cait.spe[1] = change_basic_stat_enemy("CRIT",
                                            "./src/menu/.stat_cait");
    f->cait.spe[2] = change_basic_stat_enemy("ADDTURN",
                                            "./src/menu/.stat_cait");
    f->cait.spe[3] = change_basic_stat_enemy("MOVESPEED",
                                            "./src/menu/.stat_cait");
    f->cait.spe[4] = change_basic_stat_enemy("ARMOR",
                                            "./src/menu/.stat_cait");
    f->shop.life_popo = 100;
    f->shop.nb_item = 0;
    f->cait.life_steal = 0;
    init_second_stat(f);
}
