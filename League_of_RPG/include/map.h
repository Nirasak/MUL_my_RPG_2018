/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** rpg.h
*/

#ifndef MY_H_
#define MY_H_

typedef struct part
{
    sfVector2f pos_a;
    sfVector2f pos_b;
    sfVector2f pos_c;
    sfVector2f pos_d;
    sfVector2f pos_e;
    sfColor color;
    sfVertexArray *array;
    sfClock *clock;
    sfTime time;
    float scd;
    int way;
} part_t;

typedef struct inst
{
    sfVector2f size;
    sfClock *clock;
    sfClock *clock_b;
    sfTime time_b;
    float scd_b;
    sfTime time;
    float scd;
    sfTexture *t_black;
    sfSprite *s_black;
    sfVector2f p_black;
    sfIntRect r_black;
    int x;
    int y;
    sfVector2f zoom;
    int x_cait;
    int y_cait;
    sfVector2f zoom_cait;
} inst_t;

typedef struct perso
{
    sfTexture *t_perso;
    sfSprite *s_perso;
    sfIntRect r_perso;
    sfVector2f p_perso;
    sfVector2f mid_screen;
    int run;
    int mvmt;
    sfClock *clock;
    sfTime time;
    float scd;
} perso_t;

typedef struct map
{
    sfTexture *t_map;
    sfSprite *s_map;
    sfVector2f origin;
    sfClock *clock;
    sfTime time;
    float scd;
    char **tab;
    sfVector2i pos_map;
    sfTexture *t_mini;
    sfSprite *s_mini;
    sfIntRect r_mini;
    sfVector2f p_mini;
    sfSprite *s_circle;
    sfIntRect r_circle;
    sfVector2f p_circle;
    inst_t inst;
    perso_t perso;
    part_t *part;
    sfTexture *t_markmin;
    sfSprite *s_markmin;
    sfVector2f p_markmin;
    sfIntRect r_markmin;
    sfTexture *t_mark;
    sfSprite *s_mark;
    sfVector2f p_mark;
    sfIntRect r_mark;
} map_t;

/* loop */

void gameplay_map(map_t *map, dwd_t *dwd, fight_t *fight);

/* create */

void create_my_minimap(map_t *map);
void create_my_instance(map_t *map);
void create_my_perso(map_t *map);
void create_my_markquest(map_t *map);
char **create_my_map(map_t *map);
void init_particules(map_t *map);
void init_rdm_explo(fight_t *map);
void reinit_instance(map_t *map);
void init_punct(dwd_t *dwd);

/* movements */

void move_map_left(map_t *map, fight_t *fight);
void move_map_right(map_t *map, fight_t *fight);
void move_map_up(map_t *map, fight_t *fight);
void move_map_down(map_t *map, fight_t *fight);
void move_perso(map_t *map);
void set_mark(map_t *map, dwd_t *dwd, fight_t *f);
int check_instance_spawn(map_t *map);

/* instance */

void my_instance_fight(map_t *map, dwd_t *dwd);
void after_instance(map_t *map, dwd_t *dwd);
void clock_instance(map_t *map);
void init_instance(map_t *map);

/* display */

void display_map(map_t *map, dwd_t *dwd);
void particules(map_t *map, dwd_t *dwd);

void markquest_setplace(dwd_t *dwd, int, int);
void decrease_when_popo(fight_t *f);
int gain_life(dwd_t *dwd, fight_t *f);
int check_mouse_in_rect(dwd_t *dwd, fight_t *f);
void spawn_loop(dwd_t *dwd, fight_t *fight);
void init_quest_one(map_t *map, fight_t *fight);
void reset_cooldown(fight_t *f);
void reset_shield(fight_t *f);
int fight(dwd_t *dwd, fight_t *f, sfSprite *);
int check_rect_quest(sfSprite *);
void set_pos_explo(sfVector2f pos, fight_t *f, sfColor color);
void print_quest(dwd_t *dwd, fight_t *f);
void explo_right(fight_t *f, sfRenderWindow *);
void explo_left(fight_t *f, sfRenderWindow *);
void draw_cara_quest(dwd_t *dwd, fight_t *f);
void lose_fight(dwd_t *dwd, fight_t *f, map_t *map);
void win_fight(dwd_t *dwd, fight_t *f, map_t *map);

#endif
