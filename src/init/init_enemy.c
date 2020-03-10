/*
** EPITECH PROJECT, 2019
** init_enemy.c
** File description:
** init all my enemys
*/

#include "my.h"

static void init_var(fight_t *f)
{
    f->enemy.actual_life = 10000;
    f->enemy.max_life = 10000;
    f->enemy.anime = sfClock_create();
    f->enemy.left = 0;
    f->enemy.max_left = 0;
    f->enemy.attackspr = sfSprite_create();
    f->enemy.move_attack = sfClock_create();
    f->enemy.anime_attack = sfClock_create();
    f->enemy.attacksprtwo = sfSprite_create();
    f->enemy.move_attacktwo = sfClock_create();
    f->enemy.anime_attacktwo = sfClock_create();
    f->enemy.resetscl = 0;
}

int init_enemy(fight_t *f)
{
    char **path;
    sfIntRect rect = {0, 37, 407, 37};

    if (extract_data_file("./src/menu/.enemy", &path) == 84)
        return (84);
    f->enemy.life_enemy = f_sprite_create("LIFE", path, 1360, 554);
    f->enemy.life_enemy_back = f_sprite_create("LIFE", path, 1360, 554);
    change_scale(f->enemy.life_enemy, 0.5, 0.5);
    f->enemy.enemy = f_sprite_create("TRAIN", path, 1300, 600);
    change_scale(f->enemy.enemy, 1.25, 1.25);
    sfSprite_setTextureRect(f->enemy.life_enemy_back, rect);
    change_scale(f->enemy.life_enemy_back, 0.5, 0.5);
    init_var(f);
    return (0);
}
