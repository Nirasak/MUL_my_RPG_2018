/*
** EPITECH PROJECT, 2019
** RPG
** File description:
** init_report
*/

#include "my.h"

static void more_init(fight_t *f, char *my_font)
{
    f->report.info_t[3] = create_button_text
        (my_font, "Success", 150, sfGreen);
    f->report.info_t[4] = create_button_text
        (my_font, "Fail", 150, sfRed);
    f->report.info_t[5] = create_button_text
        (my_font, "0", 100, sfYellow);
    f->report.info_t[6] = create_button_text
        (my_font, "0", 100, sfGreen);
    pos_text(f->report.info_t[0], 700, 185);
    pos_text(f->report.info_t[1], 650, 500);
    pos_text(f->report.info_t[2], 1200, 500);
    pos_text(f->report.info_t[3], 775, 700);
    pos_text(f->report.info_t[4], 950, 700);
    pos_text(f->report.info_t[5], 830, 500);
    pos_text(f->report.info_t[6], 1330, 500);
    f->report.passed = sfClock_create();
}

void init_report(dwd_t *dwd, fight_t *f)
{
    char *my_font = extract_string_value("font", dwd->menu.data);

    f->report.background = f_sprite_create("BG_QUEST", dwd->menu.data, 0, 0);
    f->report.victory = f_sprite_create("VICTORY", dwd->menu.data, 350, 100);
    f->report.board = f_sprite_create("BOARD", dwd->menu.data, 0, 0);
    f->report.info_t = malloc(sizeof(sfText *) * 7);
    f->report.init = 0;
    f->report.info_t[0] = create_button_text
        (my_font, "Fight report", 100, sfWhite);
    f->report.info_t[1] = create_button_text
        (my_font, "Gold", 100, sfYellow);
    f->report.info_t[2] = create_button_text
        (my_font, "Xp", 100, sfGreen);
    more_init(f, my_font);
    f->report.xp = 0;
    f->report.gold = 0;
    f->report.clock_victory = sfClock_create();
    f->report.success = 0;
}
