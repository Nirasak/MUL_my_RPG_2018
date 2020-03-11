/*
** EPITECH PROJECT, 2019
** change_enemy.c
** File description:
** create my generic function who change my caracteristics for my enemys
*/

#include "my.h"

void change_texture_enemy_and_rect(fight_t *f, char *enemy)
{
    sfVector2f scl = {1.2, 1.2};

    change_text_enemy(enemy, f->enemy.enemy, "./src/menu/.enemy");
    change_rect_enemy(my_realstrcat(enemy, "RECT"), "./src/menu/.stat_enemy",
                    &f->enemy.rect);
    sfSprite_setTextureRect(f->enemy.enemy, f->enemy.rect);
    change_scl_enemy(my_realstrcat(enemy, "SCL"),
                    "./src/menu/.stat_enemy", &scl);
    change_scale(f->enemy.enemy, scl.x, scl.y);
    change_scl_enemy(my_realstrcat(enemy, "STUN"),
                    "./src/menu/.stat_enemy", &scl);
    sfSprite_setPosition(f->spell.stun, scl);
        change_scl_enemy(my_realstrcat(enemy, "TRAP"),
                    "./src/menu/.stat_enemy", &scl);
    sfSprite_setPosition(f->spell.abilities[1], scl);
}

void change_life_enemy(fight_t *f, char *enemy)
{
    sfVector2f pos = {500, 500};

    f->enemy.max_life = change_basic_stat_enemy(my_realstrcat(enemy, "HP"),
                                                "./src/menu/.stat_enemy");
    f->enemy.defense = change_basic_stat_enemy(my_realstrcat(enemy, "DEF"),
                                                "./src/menu/.stat_enemy");
    f->enemy.actual_life = f->enemy.max_life;
    change_scl_enemy(my_realstrcat(enemy, "HPPOS"),
                    "./src/menu/.stat_enemy", &pos);
    sfSprite_setPosition(f->enemy.life_enemy_back, pos);
    sfSprite_setPosition(f->enemy.life_enemy, pos);
    change_scl_enemy(my_realstrcat(enemy, "HPSCL"),
                    "./src/menu/.stat_enemy", &pos);
    change_scale(f->enemy.life_enemy, pos.x, pos.y);
    change_scale(f->enemy.life_enemy_back, pos.x, pos.y);
}

void change_enemy(fight_t *f, char *enemy)
{
    sfVector2f scl = {1.2, 1.2};

    change_texture_enemy_and_rect(f, enemy);
    f->enemy.attack = change_basic_stat_enemy(my_realstrcat(enemy, "ATK"),
                                            "./src/menu/.stat_enemy");
    change_scl_enemy(my_realstrcat(enemy, "POS"),
                    "./src/menu/.stat_enemy", &scl);
    sfSprite_setPosition(f->enemy.enemy, scl);
    f->enemy.left = change_basic_stat_enemy(my_realstrcat(enemy, "LEFT"),
                                            "./src/menu/.stat_enemy");
    f->enemy.max_left = change_basic_stat_enemy(my_realstrcat(enemy, "MAXLEFT"),
                                            "./src/menu/.stat_enemy");
    f->enemy.sec = change_sec_enemy(my_realstrcat(enemy, "SEC"),
                                    "./src/menu/.stat_enemy");
    change_life_enemy(f, enemy);
    change_attack_texture_and_rect(f, enemy);
    change_attack_enemy(f, enemy);
}
