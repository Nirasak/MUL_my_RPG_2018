/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** destroy
*/

#include "my.h"

/* void destroy_sprites_fight_thrd(fight_t *fight) */
/* { */
/*     sfSprite_destroy(fight->shop.buy); */
/*     sfSprite_destroy(fight->shop.gnar); */
/*     sfSprite_destroy(fight->shop.popo); */
/*     sfSprite_destroy(fight->shop.heal); */
/*     for (int i = 0; i < 5; i = i + 1) */
/*         sfSprite_destroy(fight->shop.item[i]); */
/* } */

/* void destroy_sprites_fight_scd(fight_t *fight) */
/* { */
/*     sfSprite_destroy(fight->spell.select_abi); */
/*     for (int i = 0; i < 4; i = i + 1) { */
/*         sfSprite_destroy(fight->spell.icon_abi[i]); */
/*         sfSprite_destroy(fight->spell.unlock[i]); */
/*         sfSprite_destroy(fight->spell.abilities[i]); */
/*     } */
/*     sfSprite_destroy(fight->spell.stun); */
/*     sfSprite_destroy(fight->spell.qspell); */
/*     sfSprite_destroy(fight->spell.espell); */
/*     sfSprite_destroy(fight->enemy.enemy); */
/*     sfSprite_destroy(fight->enemy.life_enemy); */
/*     sfSprite_destroy(fight->enemy.life_enemy_back); */
/*     sfSprite_destroy(fight->enemy.attackspr); */
/*     sfSprite_destroy(fight->shop.shop); */
/*     sfSprite_destroy(fight->shop.karma); */
/*     sfSprite_destroy(fight->shop.hover_item); */
/*     sfSprite_destroy(fight->shop.zoom); */
/*     sfSprite_destroy(fight->shop.close_hover); */
/*     destroy_sprites_fight_thrd(fight); */
/* } */

/* void destroy_sprites_fight(fight_t *fight) */
/* { */
/*     sfSprite_destroy(fight->report.background); */
/*     sfSprite_destroy(fight->report.board); */
/*     sfSprite_destroy(fight->cait.sprite); */
/*     sfSprite_destroy(fight->cait.shot); */
/*     sfSprite_destroy(fight->cait.impact); */
/*     sfSprite_destroy(fight->cait.xp); */
/*     sfSprite_destroy(fight->spawn.bg); */
/*     sfSprite_destroy(fight->spawn.rock); */
/*     sfSprite_destroy(fight->spawn.bush); */
/*     sfSprite_destroy(fight->spawn.poro); */
/*     sfSprite_destroy(fight->spawn.rporo); */
/*     sfSprite_destroy(fight->spawn.tamo); */
/*     sfSprite_destroy(fight->spawn.bag); */
/*     sfSprite_destroy(fight->bgf.jungle); */
/*     sfSprite_destroy(fight->bgf.cave); */
/*     sfSprite_destroy(fight->spell.life); */
/*     sfSprite_destroy(fight->spell.interface); */
/*     sfSprite_destroy(fight->spell.inventory); */
/*     destroy_sprites_fight_scd(fight); */
/* } */

void destroy_sprites_game(map_t *map)
{
    sfSprite_destroy(map->s_map);
    sfSprite_destroy(map->s_mini);
    sfSprite_destroy(map->s_circle);
    sfSprite_destroy(map->s_markmin);
    sfSprite_destroy(map->s_mark);
    sfSprite_destroy(map->perso.s_perso);
    sfSprite_destroy(map->inst.s_black);
}
