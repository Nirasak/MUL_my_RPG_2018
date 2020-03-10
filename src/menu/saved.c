/*
** EPITECH PROJECT, 2019
** RPG
** File description:
** saved
*/

#include "my.h"

static void act_existing_button
(dwd_t *dwd, char *save1, char *save2, char *save3)
{
    if (active_button(dwd->save.save1_bt, dwd->save.save1_t,
        sfRed, dwd) == 1 && my_strcmp(save1, "123456789") != 0) {
        dwd->user = 1;
        transfer_profile_data(dwd, dwd->save.data_save1);
    }
    if (active_button(dwd->save.save2_bt, dwd->save.save2_t,
        sfRed, dwd) == 1 && my_strcmp(save2, "123456789") != 0) {
        dwd->user = 2;
        transfer_profile_data(dwd, dwd->save.data_save2);
    }
    if (active_button(dwd->save.save3_bt, dwd->save.save3_t,
        sfRed, dwd) == 1 && my_strcmp(save3, "123456789") != 0) {
        dwd->user = 3;
        transfer_profile_data(dwd, dwd->save.data_save3);
    }
}

static void more_act_button(dwd_t *dwd, char *save2, char *save3)
{
    if (active_button(dwd->save.save2_bt, dwd->save.save2_t,
        sfRed, dwd) == 1 && my_strcmp(save2, "123456789") == 0) {
        dwd->user = 2;
        transfer_profile_data(dwd, dwd->save.data_save2);
        pseudo_menu(dwd);
        init_before_menu(dwd);
    }
    if (active_button(dwd->save.save3_bt, dwd->save.save3_t,
        sfRed, dwd) == 1 && my_strcmp(save3, "123456789") == 0) {
        dwd->user = 3;
        transfer_profile_data(dwd, dwd->save.data_save3);
        pseudo_menu(dwd);
        init_before_menu(dwd);
    }
}

static void act_button(dwd_t *dwd)
{
    char *save1 = extract_string_value("pseudo", dwd->save.data_save1);
    char *save2 = extract_string_value("pseudo", dwd->save.data_save2);
    char *save3 = extract_string_value("pseudo", dwd->save.data_save3);

    if (active_button(dwd->save.save1_bt, dwd->save.save1_t,
        sfRed, dwd) == 1 && my_strcmp(save1, "123456789") == 0) {
        dwd->user = 1;
        transfer_profile_data(dwd, dwd->save.data_save1);
        pseudo_menu(dwd);
        init_before_menu(dwd);
    }
    more_act_button(dwd, save2, save3);
    act_existing_button(dwd, save1, save2, save3);
}

void main_changement_profile(dwd_t *dwd)
{
    while (dwd->is_open == NEW_PROF) {
        while (sfRenderWindow_pollEvent(dwd->window, &dwd->event)) {
            mouse(dwd);
            act_button(dwd);
        }
        anime_menu(dwd);
        sfRenderWindow_drawSprite(dwd->window, dwd->save.save1_bt, NULL);
        sfRenderWindow_drawSprite(dwd->window, dwd->save.save2_bt, NULL);
        sfRenderWindow_drawSprite(dwd->window, dwd->save.save3_bt, NULL);
        sfRenderWindow_drawText(dwd->window, dwd->save.save1_t, NULL);
        sfRenderWindow_drawText(dwd->window, dwd->save.save2_t, NULL);
        sfRenderWindow_drawText(dwd->window, dwd->save.save3_t, NULL);
        disp_mouse(dwd);
        sfRenderWindow_display(dwd->window);
    }
}
