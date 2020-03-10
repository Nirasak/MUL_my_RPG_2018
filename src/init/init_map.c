/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** create
*/

#include "my.h"

void create_my_markquest(map_t *map)
{
    map->t_markmin = sfTexture_createFromFile("assets/markquest.png", NULL);
    map->s_markmin = sfSprite_create();
    map->r_markmin.left = 10;
    map->r_markmin.top = 10;
    map->r_markmin.width = 12;
    map->r_markmin.height = 31;
    map->p_markmin.x = 1710;
    map->p_markmin.y = 172;
    sfSprite_setTexture(map->s_markmin, map->t_markmin, sfTrue);
    sfSprite_setTextureRect(map->s_markmin, map->r_markmin);
    map->t_mark = sfTexture_createFromFile("assets/mark.png", NULL);
    map->s_mark = sfSprite_create();
    map->r_mark.left = 0;
    map->r_mark.top = 0;
    map->r_mark.width = 1000;
    map->r_mark.height = 900;
    map->p_mark.x = 1610;
    map->p_mark.y = 1600;
    sfSprite_setTexture(map->s_mark, map->t_mark, sfTrue);
    sfSprite_setTextureRect(map->s_mark, map->r_mark);
}

void create_my_minimap(map_t *map)
{
    map->s_mini = sfSprite_create();
    map->s_circle = sfSprite_create();
    map->p_mini.x = 1500;
    map->p_mini.y = 1;
    map->r_mini.top = 0;
    map->r_mini.left = 1500;
    map->r_mini.height = 350;
    map->r_mini.width = 420;
    map->r_circle.top = 20;
    map->r_circle.left = 20;
    map->r_circle.height = 30;
    map->r_circle.width = 30;
    map->p_circle.x = 1504.4;
    map->p_circle.y = -12.8;
    sfSprite_setTexture(map->s_mini, map->t_mini, sfTrue);
    sfSprite_setTextureRect(map->s_mini, map->r_mini);
    sfSprite_setTexture(map->s_circle, map->t_mini, sfTrue);
    sfSprite_setTextureRect(map->s_circle, map->r_circle);
    sfSprite_setPosition(map->s_mini, map->p_mini);
    sfSprite_setPosition(map->s_circle, map->p_circle);
}

void create_my_instance(map_t *map)
{
    map->inst.size.x = 2;
    map->inst.size.y = 2;
    map->inst.clock = sfClock_create();
    map->inst.scd = 0;
    map->inst.t_black = sfTexture_createFromFile(
        "assets/map/instance.png", NULL);
    map->inst.s_black = sfSprite_create();
    map->inst.p_black.x = 0;
    map->inst.p_black.y = 0;
    map->inst.r_black.top = 0;
    map->inst.r_black.left = 0;
    map->inst.r_black.width = 1920;
    map->inst.r_black.height = 1080;
    sfSprite_setTexture(map->inst.s_black, map->inst.t_black, sfTrue);
    sfSprite_setTextureRect(map->inst.s_black, map->inst.r_black);
    sfSprite_setPosition(map->inst.s_black, map->inst.p_black);
    map->inst.clock_b = sfClock_create();
    map->inst.scd_b = 0;
}

void create_my_perso(map_t *map)
{
    map->perso.run = 0;
    map->perso.mvmt = 0;
    map->perso.t_perso = sfTexture_createFromFile("assets/map/mvmt.png", NULL);
    map->perso.s_perso = sfSprite_create();
    map->perso.r_perso.left = 934;
    map->perso.r_perso.top = 388;
    map->perso.r_perso.width = 120;
    map->perso.r_perso.height = 150;
    map->perso.mid_screen.x = (1920 - map->perso.r_perso.width) / 2;
    map->perso.mid_screen.y = (1080 - map->perso.r_perso.height) / 2;
    map->perso.p_perso.x = 0;
    map->perso.p_perso.y = 0;
    sfSprite_setTexture(map->perso.s_perso, map->perso.t_perso, sfTrue);
    sfSprite_setTextureRect(map->perso.s_perso, map->perso.r_perso);
    map->perso.clock = sfClock_create();
    map->perso.scd = 0;
}

char **create_my_map(map_t *map)
{
    sfVector2f p_map = {0, 0};
    sfVector2f size = {2, 2};
    char **tab = NULL;

    map->t_mini = sfTexture_createFromFile("assets/map/minimap.png", NULL);
    extract_data_file(".map.txt", &tab);
    map->pos_map.x = 1210;
    map->pos_map.y = 890;
    map->origin.x = map->pos_map.x - 485;
    map->origin.y = map->pos_map.y - 315;
    map->t_map = sfTexture_createFromFile("assets/map/map.png", NULL);
    map->s_map = sfSprite_create();
    sfSprite_setTexture(map->s_map, map->t_map, sfTrue);
    sfSprite_setOrigin(map->s_map, map->origin);
    sfSprite_setScale(map->s_map, size);
    sfSprite_setPosition(map->s_map, p_map);
    map->clock = sfClock_create();
    map->scd = 0;
    return (tab);
}
