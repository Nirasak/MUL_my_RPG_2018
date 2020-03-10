/*
** EPITECH PROJECT, 2019
** init_shop.c
** File description:
** init my shop
*/

#include "my.h"

void init_boots_pos(fight_t *f)
{
    f->shop.posmin[3].x = 365;
    f->shop.posmin[3].y = 415;
    f->shop.posmax[3].x = 429;
    f->shop.posmax[3].y = 485;
    f->shop.posmin[4].x = 460;
    f->shop.posmin[4].y = 415;
    f->shop.posmax[4].x = 526;
    f->shop.posmax[4].y = 485;
    f->shop.posmin[5].x = 556;
    f->shop.posmin[5].y = 415;
    f->shop.posmax[5].x = 623;
    f->shop.posmax[5].y = 485;
    f->shop.posmin[6].x = 653;
    f->shop.posmin[6].y = 415;
    f->shop.posmax[6].x = 721;
    f->shop.posmax[6].y = 485;
}

void init_attackspeed_pos(fight_t *f)
{
    f->shop.posmin[7].x = 364;
    f->shop.posmin[7].y = 560;
    f->shop.posmax[7].x = 430;
    f->shop.posmax[7].y = 631;
    f->shop.posmin[8].x = 460;
    f->shop.posmin[8].y = 560;
    f->shop.posmax[8].x = 524;
    f->shop.posmax[8].y = 630;
    f->shop.posmin[9].x = 556;
    f->shop.posmin[9].y = 560;
    f->shop.posmax[9].x = 623;
    f->shop.posmax[9].y = 630;
}

void init_dmg_pos(fight_t *f)
{
    f->shop.posmin[10].x = 365;
    f->shop.posmin[10].y = 706;
    f->shop.posmax[10].x = 428;
    f->shop.posmax[10].y = 771;
    f->shop.posmin[11].x = 461;
    f->shop.posmin[11].y = 706;
    f->shop.posmax[11].x = 522;
    f->shop.posmax[11].y = 771;
    f->shop.posmin[12].x = 557;
    f->shop.posmin[12].y = 706;
    f->shop.posmax[12].x = 621;
    f->shop.posmax[12].y = 772;
}

void init_hitbox_shop(fight_t *f)
{
    f->shop.posmin = malloc(sizeof(sfVector2f) * 14);
    f->shop.posmax = malloc(sizeof(sfVector2f) * 14);
    f->shop.posmin[0].x = 365;
    f->shop.posmin[0].y = 270;
    f->shop.posmax[0].x = 428;
    f->shop.posmax[0].y = 340;
    f->shop.posmin[1].x = 460;
    f->shop.posmin[1].y = 270;
    f->shop.posmax[1].x = 526;
    f->shop.posmax[1].y = 340;
    f->shop.posmin[2].x = 556;
    f->shop.posmin[2].y = 270;
    f->shop.posmax[2].x = 623;
    f->shop.posmax[2].y = 340;
    init_boots_pos(f);
    init_attackspeed_pos(f);
    init_dmg_pos(f);
}
