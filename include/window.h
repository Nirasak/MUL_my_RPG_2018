/*
** EPITECH PROJECT, 2019
** window
** File description:
** struct for windows
*/

#ifndef WINDOW__
#define WINDOW_

typedef enum enum_menu
{
    PSEUDO,
    NEW_PROF,
    ICON,
    MENU,
    HTP,
    DIFFICULTY,
    LORE,
    OPTION,
    KEYBINDING,
    LEAVE,
    PAUSE,
    PAUSE_OPTION,
    GAMEPLAY,
    GAME_MAP,
    QUEST_DISCUT,
    SHOP,
    REPORT_FIGHT,
} e_menu_t;

typedef struct quest
{
    sfSprite *s_inter;
    sfVector2f p_inter;
    sfSprite *s_excla;
    sfVector2f p_excla;
    char **discution;
    sfText *quest;
    sfText *text_champ;
    sfSprite *background;
    sfSprite *garen;
    sfClock *c_garen;
    sfSprite *rammus;
    sfClock *c_rammus;
} quest_t;

typedef struct sound
{
    sfSprite *music_bar;
    sfSprite *sound_bar;
    sfSprite *under_sound;
    sfSprite *under_music;
    sfMusic *menu;
    sfMusic *click;
    sfMusic *boss;
    sfMusic *map;
    sfMusic *fight;
    int music_vol;
    int effect_vol;
} sound_t;

typedef struct mouse
{
    int is_clicked;
    int which_mouse;
    sfVector2i mouse_pos;
    sfVector2f pos;
    sfSprite *f_mouse;
    sfIntRect rect_fmouse;
    sfSprite *s_mouse;
} mouse_t;

typedef struct button
{
    int bt_clicked;
    sfSprite *name;
    sfSprite *confirm;
    sfText *confirm_t;
    sfSprite *play;
    sfText *play_t;
    sfSprite *lore;
    sfText *lore_t;
    sfSprite *option;
    sfText *option_t;
    sfSprite *leave;
    sfText *leave_t;
    sfSprite *back;
    sfText *back_t;
    sfSprite *music;
    sfSprite *sound;
    sfSprite *bt_fcursor;
    sfSprite *bt_scursor;
    sfSprite *map;
    sfText *map_t;
} button_t;

typedef struct profile
{
    sfText *option;
    sfText *which_icon;
    sfSprite *profile_board;
    sfSprite *name_board;
    sfSprite *icon_board;
    sfSprite **acon;
    sfSprite **icon;
    int current_icon;
    int difficulty;
    int played;
} profile_t;

typedef struct diff
{
    sfSprite *easy;
    sfText *easy_t;
    sfSprite *medium;
    sfText *medium_t;
    sfSprite *hard;
    sfText *hard_t;
} diff_t;

typedef struct pause
{
    sfText *pause;
    sfClock *clock_pause;
    sfSprite *pause_champ;
    sfSprite *resume;
    sfSprite *option;
    sfSprite *save;
    sfSprite *menu;
    sfSprite *leave;
    sfText *resume_t;
    sfText *option_t;
    sfText *save_t;
    sfText *menu_t;
    sfText *leave_t;
} pause_t;

typedef struct how_to_play
{
    sfSprite *next_bt;
    sfSprite *prev_bt;
    sfSprite *back_bt;
    sfText *next_t;
    sfText *prev_t;
    sfText *back_t;
    sfText *text_htp;
    sfSprite *board_htp;
    sfClock *clock_htp;
    sfSprite *champ_htp;
} htop_t;

typedef struct menu
{
    char **data;
    sfClock *clock;
    sfClock *clock2;
    sfSprite *menu;
    sfSprite *menu2;
    sfSprite *board;
    profile_t profile;
    sfIntRect rect_menu;
    sfIntRect rect_menu2;
    button_t button;
    diff_t diff;
    sfText **lore;
    char **data_lore;
    sfSprite *lore_champ;
    sfClock *clock_lore;
    pause_t pause;
    htop_t htp;
} menu_t;

typedef struct utils
{
    sfText **background;
    sfSprite **bt_bg;
    sfText **fps;
    sfSprite **bt_fps;
    int fps_value;
} utils_t;

typedef struct keybinding
{
    char **keybind;
    sfText **text_key;
    sfText **key_t;
    sfSprite **key;
    sfText *keybinding;
    sfSprite *champ_key;
    sfClock *clock_key;
    int is_clicked;
} keybind_t;

typedef struct option
{
    sfSprite **bt_option;
    sfText *option;
    sfText *f_screen;
    sfText *confirm_screen;
    int screen;
    sfText *particle;
    sfText *confirm_particle;
    int parti;
    sfText *qwerty;
    sfText *music;
    sfText *effect;
    sfSprite *f_cursor;
    sfSprite *s_cursor;
    utils_t utils;
    keybind_t key;
    sfSprite *htp;
    sfText *htp_t;
} option_t;

typedef struct save
{
    sfText *save1_t;
    sfText *save2_t;
    sfText *save3_t;
    sfSprite *save1_bt;
    sfSprite *save2_bt;
    sfSprite *save3_bt;
    char **data_save1;
    char **data_save2;
    char **data_save3;
} save_t;

typedef struct window
{
    int user;
    sfSprite *animation;
    sfSprite *animation2;
    sfClock *clock_anime;
    sfClock *clock_key;
    int is_open;
    int last_open;
    int shop_back;
    int background;
    char *pseudo;
    sfText *pseudo_t;
    e_menu_t e_menu;
    mouse_t mouse;
    menu_t menu;
    option_t option;
    sound_t sound;
    sfRenderWindow *window;
    sfEvent event;
    save_t save;
    quest_t quest;
} dwd_t;

#endif
