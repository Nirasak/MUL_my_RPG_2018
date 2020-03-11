/*
** EPITECH PROJECT, 2019
** fight.h
** File description:
** create my .h for my fight function struct
*/

#ifndef FIGHT_H_
#define FIGHT_H_

typedef struct explo
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
    sfClock *clock_part;
    sfTime time_part;
    float scd_part;
    int way;
    int x;
    int y;
    int direct;
} explo_t;

typedef struct shop
{
    sfSprite *shop;
    sfSprite *karma;
    sfSprite *hover_item;
    sfClock *clock_karma;
    sfSprite *zoom;
    sfSprite *close_hover;
    sfVector2f *posmin;
    sfVector2f *posmax;
    char **text_item;
    sfSprite *buy;
    sfFont *font;
    sfText **text;
    sfSprite *gnar;
    sfClock *clock_gnar;
    sfSprite **item;
    sfVector2f *pos_item;
    sfSprite *popo;
    sfSprite *heal;
    sfClock *clock_heal;
    int life_popo;
    int nb_item;
    sfColor color;
} shop_t;

typedef struct enemy
{
    sfSprite *enemy;
    sfSprite *life_enemy;
    sfSprite *life_enemy_back;
    int actual_life;
    int max_life;
    int defense;
    int left;
    int max_left;
    sfClock *anime;
    int attack;
    float sec;
    sfIntRect rect;
    int resetscl;
    sfSprite *attackspr;
    sfClock *move_attack;
    sfClock *anime_attack;
    sfIntRect attack_rect;
    int max_left_attack;
    int left_attack;
    sfVector2f pos_attack;
    float sec_attack;
    sfVector2f speed_attack;
    
    sfSprite *attacksprtwo;
    sfClock *move_attacktwo;
    sfClock *anime_attacktwo;
    sfIntRect attack_recttwo;
    int max_left_attacktwo;
    int attacktwo;
    int left_attacktwo;
    sfVector2f pos_attacktwo;
    float sec_attacktwo;
    sfVector2f speed_attacktwo;
} enemy_t;

typedef struct spell
{
    sfSprite *life;
    sfSprite *interface;
    sfSprite *inventory;
    sfSprite *select_abi;
    sfClock *cunlock;
    sfSprite *lvlup;
    sfClock *clvlup;
    sfSprite **icon_abi;
    sfSprite **unlock;
    int *unlock_spell;
    sfText **text;
    sfSprite **abilities;
    sfClock **clock_abi;
    sfSprite *stun;
    sfClock *clock_stun;
    sfText **text_dmg;
    sfSprite *qspell;
    sfClock *clock_qspell;
    sfClock *move_qspell;
    sfText **cooldown_text;
    int *cooldown;
    sfSprite *espell;
    sfClock *clock_espell;
    sfClock *clock_ult;
} spell_t;

typedef struct bg_fight
{
    sfSprite *jungle;
    sfSprite *cave;
} bg_fight_t;

typedef struct spawn
{
    sfSprite *bg;
    sfSprite *rock;
    sfSprite *bush;
    sfSprite *poro;
    sfSprite *rporo;
    sfSprite *tamo;
    sfClock **clock;
    sfSprite *bag;
    sfText *text;
    int shoot;
    sfClock *clocke;
} spawn_t;

typedef struct cait
{
    sfSprite *sprite;
    sfClock *clock;
    sfSprite *shot;
    sfClock *cshot;
    sfSprite *impact;
    sfClock *cimpact;
    sfMusic *shot_sound;
    int *spe;
    int life_steal;
    sfSprite *xp;
    sfMusic *lvlup;
} cait_t;

typedef struct report
{
    sfSprite *background;
    sfSprite *board;
    sfText **info_t;
    sfClock *passed;
    int init;
    int xp;
    int gold;
    int success;
    sfSprite *victory;
    sfClock *clock_victory;
} report_t;

typedef struct fight
{
    spawn_t spawn;
    cait_t cait;
    spell_t spell;
    shop_t shop;
    enemy_t enemy;
    bg_fight_t bgf;
    int stun;
    float quest;
    report_t report;
    explo_t *explo;
} fight_t;

//enemy
int init_enemy(fight_t *f);
int init_bg_fight(fight_t *f);
void draw_enemy_life(fight_t *f);
void draw_enemy(dwd_t *dwd, fight_t *f);
void draw_jungle(dwd_t *dwd, fight_t *f);
void change_enemy(fight_t *f, char *enemy);
void anime_attack_enemy(fight_t *f);
int move_attack_enemy(fight_t *f, sfVector2f *reset, int *a);
int enemy_basic_attack(fight_t *f);
float calcul_dist(float x, float xx);
sfVector2f pos_cait_corp(fight_t *f);
sfVector2f pos_enemy_corp(fight_t *f);
void init_cooldown(fight_t *f);
void addapt_to_difficult(dwd_t *dwd, fight_t *f);
void put_text_on_enemy(fight_t *f);
char *check_enemy(fight_t *f);
void change_attack_texture_and_rect(fight_t *f, char *enemy);
void change_attack_enemy(fight_t *f, char *enemy);
void change_attacktwo_texture_and_rect(fight_t *f, char *enemy);
void change_attacktwo_enemy(fight_t *f, char *enemy);
void anime_attacktwo_enemy(fight_t *f);
int move_attacktwo_enemy(fight_t *f, sfVector2f *pos, int *reset);
int enemy_second_attack(fight_t *f);
void enemy_turn(fight_t *f, int *i);
void anime_enemy(fight_t *f);
//shop
void init_hitbox_shop(fight_t *f);
int display_shop(dwd_t *dwd, fight_t *f);
int check_return(dwd_t *dwd, fight_t *f);
void shop_loop(dwd_t *dwd, fight_t *f);
int general_hitboxfunc
(dwd_t *dwd, sfVector2f posmin, sfVector2f posmax, sfSprite *sp);
void check_hitbox(dwd_t *dwd, fight_t *f);
void anime_gnar(fight_t *f);
void anime_karma(fight_t *f);

//item
int init_shop_item(fight_t *d);
void draw_item_on_bar(fight_t *f, int i);
void handle_item(dwd_t *dwd, fight_t *f, int i);
void check_price(fight_t *f, int i, int *buy);

//buff item
void buff_dmg(fight_t *f, char *s);
void buff_speed(fight_t *f, char *s);
void buff_crit(fight_t *f, char *s);
void buff_popo(fight_t *f, char *s);
void buff_lifesteal(fight_t *f, char *s);
void add_buff_item(fight_t *f, int item);
void buff_extra_turn(fight_t *f, char *s);

//abilities
void anime_stun(dwd_t *dwd, fight_t *f);
void second_spell(dwd_t *dwd, fight_t *f);
int anime_trap(dwd_t *dwd, fight_t *f);
int handle_trap(dwd_t *dwd, fight_t *f);
void delete_buff_shield(fight_t *f, int *i);
void decrease_cooldown(fight_t *f);
int handle_qspell(dwd_t *dwd, fight_t *f);
int handle_espell(dwd_t *dwd, fight_t *f);
int handle_rspell(dwd_t *dwd, fight_t *f);
void decrease_when_qspell(fight_t *f);
void decrease_when_zspell(fight_t *f);
void decrease_when_espell(fight_t *f);
void decrease_when_rspell(fight_t *f);
int handle_ult(dwd_t *dwd, fight_t *f);
int first_spell(dwd_t *dwd, fight_t *f, sfVector2f *pos, int *active);
int third_spell(dwd_t *dwd, fight_t *f);
int last_spell(fight_t *f);

//spawn
int init_spr_spawn(fight_t *f);
void init_else_spawn(fight_t *f);
void anime_poro(fight_t *f);
void anime_tamo(fight_t *f);
void anime_rporo(fight_t *f);
void move_rporo(dwd_t *dwd, fight_t *f);
void move_tamo(fight_t *f);

//interface
int init_interface(fight_t *f);
void init_stat(fight_t *f);
int init_abilities(fight_t *f);
int check_gainabi(fight_t *f);
void unlock_abi(dwd_t *dwd, fight_t *f);
int move_unlock_bar(fight_t *f);
void level_up(fight_t *f, int *i);
void print_money(dwd_t *d, fight_t *f, int i);
void anime_xpbar(dwd_t *dwd, fight_t *f);
void victory_condi(dwd_t *dwd, fight_t *f);
//life
void draw_life(dwd_t *dwd, fight_t *f);

//anime shoot
void deal_dmg(dwd_t *dwd, fight_t *f, sfVector2f *pos, int dmg);
int normal_attack(dwd_t *dwd, fight_t *f);
void handle_shoot(fight_t *f, int nb, int *life);
void put_impact(fight_t *f);
void reduce_impact(fight_t *f);
void no_crit_shot(fight_t *f, int a, int *i);
void headshoot(fight_t *f, int dmg, int *life);

//text
void put_text_position(fight_t *f, sfIntRect rect);
int anime_text(sfText *text, int *i);
void move_text(fight_t *f, sfVector2f *pos, int *i);
void move_text_hit(fight_t *f);

//loop fight
void loop_fight(dwd_t *dwd, fight_t *f);
void wait_loop(fight_t *f);
void main_fight_report(dwd_t *dwd, fight_t *f);
void put_fight_loop(dwd_t *dwd, sfSprite *back, fight_t *f);
//init

void init_report(dwd_t *dwd, fight_t *f);

#endif
