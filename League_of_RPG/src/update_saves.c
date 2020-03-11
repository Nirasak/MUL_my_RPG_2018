/*
** EPITECH PROJECT, 2019
** RPG
** File description:
** update_saves
*/

#include "my.h"

void transfer_profile_data(dwd_t *dwd, char **src)
{
    char *pseudo = extract_string_value("pseudo", src);
    char *icon = extract_string_value("icon", src);
    char *diff = extract_string_value("diff", src);
    char *played = extract_string_value("played", src);

    dwd->pseudo = pseudo;
    dwd->menu.profile.current_icon = my_atoi(icon);
    dwd->menu.profile.difficulty = my_atoi(diff);
    dwd->menu.profile.played = my_atoi(played);
    modify_data(dwd, "pseudo=", pseudo);
    modify_data(dwd, "icon=", icon);
    modify_data(dwd, "diff=", diff);
    modify_data(dwd, "played=", played);
    modify_data(dwd, "user=", my_itoa(dwd->user));
    sfText_setString(dwd->pseudo_t, pseudo);
    dwd->is_open = MENU;
}

void fill_save(dwd_t *dwd, char *obj, char *cating)
{
    if (dwd->user == 1)
        modify_file(dwd->save.data_save1, obj, cating, "src/.save1");
    else if (dwd->user == 2)
        modify_file(dwd->save.data_save2, obj, cating, "src/.save2");
    else
        modify_file(dwd->save.data_save3, obj, cating, "src/.save3");
}

void update_saves(dwd_t *dwd)
{
    fill_save(dwd, "pseudo=", dwd->pseudo);
    fill_save(dwd, "icon=", my_itoa(dwd->menu.profile.current_icon));
    fill_save(dwd, "diff=", my_itoa(dwd->menu.profile.difficulty));
    fill_save(dwd, "played=", my_itoa(dwd->menu.profile.played));
}
