/*
1;4803;0c** EPITECH PROJECT, 2019
** rpgg
** File description:
** animation perso
*/

#include "my.h"

int check_instance_spawn(map_t *map)
{
    if (sfKeyboard_isKeyPressed(sfKeyReturn) && map->origin.x + 485
        + map->perso.p_perso.x / 2 >= 220 && map->origin.x + 485 +
        map->perso.p_perso.x / 2 <= 460 && map->origin.y + 315 +
        map->perso.p_perso.y / 2 >= 1513 && map->origin.y + 315 +
        map->perso.p_perso.y / 2 <= 1678) {
        return (0);
    }
    return (1);
}

void set_mark(map_t *map, dwd_t *dwd, fight_t *f)
{
    sfVector2f pos_mark = {map->p_mark.x - map->origin.x * 2 + 485,
                            map->p_mark.y - map->origin.y * 2 + 315};

    sfSprite_setPosition(map->s_markmin, map->p_markmin);
    sfSprite_setPosition(map->s_mark, pos_mark);
    if (sfKeyboard_isKeyPressed(sfKeyReturn) && map->origin.x + 485
        + map->perso.p_perso.x / 2 >= map->p_mark.x / 2 + 280 &&
        map->origin.x + 485 + map->perso.p_perso.x / 2 <=
        map->p_mark.x / 2 + 440 && map->origin.y + 315 +
        map->perso.p_perso.y / 2 >= map->p_mark.y / 2 + 230
        && map->origin.y + 315 + map->perso.p_perso.y / 2
        <= map->p_mark.y / 2 + 395) {
        change_enemy(f, check_enemy(f));
        dwd->is_open = GAMEPLAY;
        my_instance_fight(map, dwd);
    }
}

void move_perso_nesw(map_t *map)
{
    if (map->perso.mvmt == 1) {
        if (map->perso.r_perso.left < 802)
            map->perso.r_perso.left = map->perso.r_perso.left + 132;
        else
            map->perso.r_perso.left = 10;
    }
    if (map->perso.mvmt == 0)
        map->perso.r_perso.left = 934;
    sfClock_restart(map->perso.clock);
    sfSprite_setTextureRect(map->perso.s_perso, map->perso.r_perso);
}

void move_perso(map_t *map)
{
    map->perso.time = sfClock_getElapsedTime(map->perso.clock);
    map->perso.scd = map->perso.time.microseconds / 100000.0f;
    map->p_circle.x = 1504.4 +
        (map->perso.p_perso.x / 2 + map->origin.x + 485) / 6;
    map->p_circle.y = -12.8 +
        (map->perso.p_perso.y / 2 + map->origin.y + 315) / 6;
    sfSprite_setPosition(map->s_circle, map->p_circle);
    if ((map->perso.run >= 1 && map->perso.run <= 4) && map->perso.scd >= 1.15)
        move_perso_nesw(map);
}
