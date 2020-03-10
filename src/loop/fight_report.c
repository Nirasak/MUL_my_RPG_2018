/*
** EPITECH PROJECT, 2019
** RPG
** File description:
** fight_report
*/

#include "my.h"

static void display(dwd_t *dwd, fight_t *f)
{
    sfRenderWindow_drawSprite(dwd->window, f->report.background, NULL);
    sfRenderWindow_drawSprite(dwd->window, f->report.board, NULL);
    for (int i = 0; i != 7; i++) {
        if (i == 3 || i == 4) {
        f->report.success == 0 ? sfRenderWindow_drawText
            (dwd->window, f->report.info_t[3], NULL) : 0;
        f->report.success == 1 ? sfRenderWindow_drawText
            (dwd->window, f->report.info_t[4], NULL) : 0;
        continue;
        }
    sfRenderWindow_drawText(dwd->window, f->report.info_t[i], NULL);
    }
    disp_mouse(dwd);
}

static float cond_passing_loop(fight_t *f)
{
    static sfTime time;
    static float sec;

    time = sfClock_getElapsedTime(f->report.passed);
    sec = time.microseconds / 1000000.0;
    return (sec);
}

static void event_passing(dwd_t *dwd, float sec, fight_t *f)
{
    if (sec > 1.5 && (dwd->event.type == sfEvtKeyPressed ||
        dwd->event.type == sfEvtMouseButtonPressed)) {
        dwd->is_open = GAME_MAP;
        if (f->report.success == 0) {
            f->cait.spe[8] = f->cait.spe[8] + f->report.gold;
            f->cait.spe[7] = f->cait.spe[7] + f->report.xp;
        }
        else {
            f->cait.spe[8] = f->cait.spe[8] + (f->report.gold / 4);
            f->cait.spe[7] = f->cait.spe[7] + (f->report.xp / 4);
        }
    }
}

static void print_xp_and_gold(fight_t *f)
{
    if (f->report.init == 0 && f->report.success == 0) {
        f->report.init = 1;
        sfText_setString(f->report.info_t[6], my_itoa(f->report.xp));
        sfText_setString(f->report.info_t[5], my_itoa(f->report.gold));
        sfClock_restart(f->report.passed);
    }
    if (f->report.init == 0 && f->report.success == 1) {
        f->report.init = 1;
        sfText_setString(f->report.info_t[6], my_itoa(f->report.xp / 4));
        sfText_setString(f->report.info_t[5], my_itoa(f->report.gold / 4));
        sfClock_restart(f->report.passed);
    }
}

void main_fight_report(dwd_t *dwd, fight_t *f)
{
    float sec = 0;

    f->report.init = 0;
    while (dwd->is_open == REPORT_FIGHT) {
        print_xp_and_gold(f);
        sec = cond_passing_loop(f);
        while (sfRenderWindow_pollEvent(dwd->window, &dwd->event)) {
            mouse(dwd);
            event_passing(dwd, sec, f);
        }
        display(dwd, f);
        sfRenderWindow_display(dwd->window);
    }
}
