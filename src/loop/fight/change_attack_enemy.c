/*
** EPITECH PROJECT, 2019
** change_attack_enemy.c
** File description:
** change my attack of my enemis
*/

#include "my.h"

void change_attack_texture_and_rect(fight_t *f, char *enemy)
{
    sfVector2f scl;

    change_text_enemy(my_realstrcat(enemy, "ATK"), f->enemy.attackspr,
                    "./src/menu/.enemy");
    change_rect_enemy(my_realstrcat(enemy, "ATKRECT"), "./src/menu/.enemy",
                      &f->enemy.attack_rect);
    sfSprite_setTextureRect(f->enemy.attackspr, f->enemy.attack_rect);
    f->enemy.max_left_attack =
        change_basic_stat_enemy(my_realstrcat(enemy, "ATKMAXLEFT"),
                                                    "./src/menu/.enemy");
    f->enemy.left_attack =
        change_basic_stat_enemy(my_realstrcat(enemy, "ATKLEFT"),
                                                    "./src/menu/.enemy");
    change_scl_enemy(my_realstrcat(enemy, "ATKSCL"),
                    "./src/menu/.enemy", &scl);
    change_scale(f->enemy.attackspr, scl.x, scl.y);
}

void change_attack_enemy(fight_t *f, char *enemy)
{
    sfVector2f scl;

    f->enemy.sec_attack = change_sec_enemy(my_realstrcat(enemy, "ATKSEC"),
                                    "./src/menu/.enemy");
    change_scl_enemy(my_realstrcat(enemy, "ATKPOS"),
                    "./src/menu/.enemy", &f->enemy.pos_attack);
    change_scl_enemy(my_realstrcat(enemy, "ATKSPD"),
                    "./src/menu/.enemy", &f->enemy.speed_attack);
    scl.x = 0;
    scl.y = -1500;
    sfSprite_setPosition(f->enemy.attackspr, scl);
    scl.x = 0;
    scl.y = f->enemy.attack_rect.height / 5;
    sfSprite_setOrigin(f->enemy.attackspr, scl);
    change_attacktwo_texture_and_rect(f, enemy);
    change_attacktwo_enemy(f, enemy);
}

void change_attacktwo_texture_and_rect(fight_t *f, char *enemy)
{
    sfVector2f scl;

    change_text_enemy(my_realstrcat(enemy, "ATK2"), f->enemy.attacksprtwo,
                    "./src/menu/.enemy");
    change_rect_enemy(my_realstrcat(enemy, "ATK2RECT"), "./src/menu/.enemy",
                    &f->enemy.attack_recttwo);
    sfSprite_setTextureRect(f->enemy.attackspr, f->enemy.attack_recttwo);
    f->enemy.max_left_attacktwo =
        change_basic_stat_enemy(my_realstrcat(enemy, "ATK2MAXLEFT"),
                                                    "./src/menu/.enemy");
    f->enemy.left_attacktwo =
        change_basic_stat_enemy(my_realstrcat(enemy, "ATK2LEFT"),
                                                    "./src/menu/.enemy");
    change_scl_enemy(my_realstrcat(enemy, "ATK2SCL"),
                    "./src/menu/.enemy", &scl);
    change_scale(f->enemy.attacksprtwo, scl.x, scl.y);
}

void change_attacktwo_enemy(fight_t *f, char *enemy)
{
    sfVector2f scl;

    f->enemy.sec_attacktwo = change_sec_enemy(my_realstrcat(enemy, "ATK2SEC"),
                                    "./src/menu/.enemy");
    change_scl_enemy(my_realstrcat(enemy, "ATK2POS"),
                    "./src/menu/.enemy", &f->enemy.pos_attacktwo);
    change_scl_enemy(my_realstrcat(enemy, "ATK2SPD"),
                    "./src/menu/.enemy", &f->enemy.speed_attacktwo);
    scl.x = 0;
    scl.y = -1500;
    sfSprite_setPosition(f->enemy.attacksprtwo, scl);
    scl.x = 0;
    scl.y = f->enemy.attack_recttwo.height / 5;
    sfSprite_setOrigin(f->enemy.attacksprtwo, scl);
}
