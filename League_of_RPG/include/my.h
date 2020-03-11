/*
** EPITECH PROJECT, 2019
** my.h
** File description:
** protos
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/Window/Keyboard.h>
#include <SFML/System.h>
#include <SFML/Audio.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#include "window.h"
#include "fight.h"
#include "map.h"

#ifndef MY_
#define MY_


/* lib */

int my_str_egal_cmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int n);
int my_strcmp(char const *s1, char const *s2);
int my_strlen(char *const str);
char **str_to_wordtab(char *s);
char *cut_str(char *s);
char *get_cut_str(char *s);
char *return_price(char *s);
char *get_and_str(char *s);
char *return_stat_item(char *s);
char *cut_str(char *s);
int my_strlen(char *s);
char *my_strdup(char const *src);
char *my_itoa(int i);
char *my_itoa_crit(int i);
int my_atoi(char *st);
char *my_strcat(char const *dest, char const *src, char *save);
/* particular lib */
void dell_last_cara(char **name);
void fill_my_string(char **name, char caracter);
int change_text_enemy(char *obj, sfSprite *sprite, char *place);
int change_scl_enemy(char *obj, char *place, sfVector2f *scl);
int change_basic_stat_enemy(char *obj, char *place);
float change_sec_enemy(char *obj, char *place);
int change_rect_enemy(char *obj, char *place, sfIntRect *rect);
int randomm(int a, int b);

/* parsing file */

void modify_data(dwd_t *dwd, char *obj, char *cating);
int extract_data_file(char *file, char ***tab);
char *extract_string_value(char *obj, char **tab);
int extract_saved_value(char *obj, char **tab);
char *alloc_my_path(char *str);
char *find_obj(char **tab, char *s);
void update_saves(dwd_t *dwd);
void transfer_profile_data(dwd_t *dwd, char **src);

/* initialisation */

void ini_option(dwd_t *dwd);
void init_option(dwd_t *dwd);
void init_profile_icon(dwd_t *dwd);
void init_before_menu(dwd_t *dwd);
void init_button(dwd_t *dwd);
sfRenderWindow *create_mywindow(unsigned int width, unsigned int height,
int fscreen);
int init_all(dwd_t *dwd, fight_t *f, map_t *map);
void ini_window(dwd_t *dwd, int fscreen);
int init_menu(dwd_t *dwd);
int init_sound(dwd_t *dwd, fight_t *f);
int init_cara(fight_t *f);
void init_utils(dwd_t *dwd, int nb1, int nb2);
int init_lore(dwd_t *dwd);
int init_animation(dwd_t *dwd);
int init_profiles(dwd_t *dwd);
void init_choose_diff(dwd_t *dwd);
void init_pause(dwd_t *dwd);
void init_keybinding(dwd_t *dwd);
void init_keys(dwd_t *dwd);
void fill_my_keys(dwd_t *dwd);
void reini_instance_before(map_t *map);
void init_htp(dwd_t *dwd);
int init_quest(dwd_t *dwd);
/* generic */
sfSprite *create_sprite(char *path, float x, float y);
sfSprite *f_sprite_create(char *obj, char **tab, float x, float y);
void check_rect_menu(dwd_t *dwd);
void change_scale(sfSprite *sprite, float x, float y);
sfText *create_button_text
(char *my_font, char *my_text, int size, sfColor color);
int active_option_button(sfSprite *button, int *change_value, dwd_t *dwd);
int re_active_option_button(sfSprite *button, dwd_t *dwd);
int active_button(sfSprite *button, sfText *text, sfColor color, dwd_t *dwd);
void modify_file(char **tab, char *obj, char *cating, char *path);
void fill_save(dwd_t *dwd, char *obj, char *cating);

/* mouse */

int init_mouse(dwd_t *dwd);
void mouse(dwd_t *dwd);
void disp_mouse(dwd_t *dwd);

/* button */

void display_button(dwd_t *dwd);
int push_small_button(sfSprite *sprite, dwd_t *dwd, int x, int y);
int push_fcursor(sfSprite *sprite, dwd_t *dwd);
int push_scursor(sfSprite *sprite, dwd_t *dwd);
void active_music_bar(sfSprite *sprite, dwd_t *dwd);
void active_sound_bar(sfSprite *sprite, dwd_t *dwd, fight_t *f);
void insert_keys(dwd_t *dwd, sfSprite *sprite);
void init_key_text(dwd_t *dwd, int i, char *my_font, int first);
void reduce_to_csfml_key(dwd_t *dwd, int i);

/* text */

void pos_text(sfText *text, int x, int y);
void pos_button_text(sfText **text, sfSprite *button, char *obj);

/* pseudo */

void set_pos_pseudo(sfText *user_pseudo, char *name);
void pseudo_menu(dwd_t *dwd);

/* animation */

void anime_menu(dwd_t *dwd);
void anime_cait(fight_t *f);
int anime_shot(fight_t *f, int *i);
int anime_animation(dwd_t *dwd);

/* main loops */

int my_rpg(void);
void gameplay_loop(dwd_t *dwd, fight_t *f, map_t *map);
void main_option(dwd_t *dwd, fight_t *f);
void main_menu(dwd_t *dwd, fight_t *f, map_t *map);
void draw_spawn(dwd_t *dwd, fight_t *f);
int display_shop(dwd_t *dwd, fight_t *f);
void icon_menu(dwd_t *dwd);
void main_lore(dwd_t *dwd);
void main_changement_profile(dwd_t *dwd);
void choose_diff_menu(dwd_t *dwd);
void main_keybinding(dwd_t *dwd);
void main_pause(dwd_t *dwd, fight_t *f);
void main_htp(dwd_t *dwd);
void discution(dwd_t *dwd, fight_t *f);
void display_text(dwd_t *dwd, fight_t *f);

/* interface */

void draw_interface(dwd_t *dwd, fight_t *f);
void draw_abi(dwd_t *dwd, fight_t *f);

/* display menus */

void draw_all(dwd_t *dwd);
void display_all_keybinding(dwd_t *dwd);

/* destroy */

void destroy_all(dwd_t *dwd, fight_t *f);

//miaou
char *my_realstrcat(char *s, char const *s2);
float my_atof(char const *str);

#endif
