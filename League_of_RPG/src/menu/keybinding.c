/*
** EPITECH PROJECT, 2019
** RPG
** File description:
** keybinding
*/

#include "my.h"

static void fill_now(dwd_t *dwd, char **tab)
{
    modify_data(dwd, "up=", tab[0]);
    modify_data(dwd, "down=", tab[1]);
    modify_data(dwd, "left=", tab[2]);
    modify_data(dwd, "right=", tab[3]);
    modify_data(dwd, "spell1=", tab[4]);
    modify_data(dwd, "spell2=", tab[5]);
    modify_data(dwd, "spell3=", tab[6]);
    modify_data(dwd, "spell4=", tab[7]);
    modify_data(dwd, "heal=", tab[8]);
    modify_data(dwd, "quest=", tab[9]);
    modify_data(dwd, "shop=", tab[10]);
    modify_data(dwd, "instance=", tab[11]);
}

void fill_my_keys(dwd_t *dwd)
{
    char **tab = malloc(sizeof(char *) * 12);

    for (int i = 0; i != 12; i++) {
        tab[i] = malloc(2);
        tab[i][0] = dwd->option.key.keybind[i][0];
        if (tab[i][0] > 25)
            tab[i][0] += 22;
        else
            tab[i][0] += 'a';
        tab[i][1] = '\0';
    }
    fill_now(dwd, tab);
    for (int i = 0; i != 12; i++)
        free(tab[i]);
    free(tab);
}

static void anime_key_champ(dwd_t *dwd)
{
    static sfTime time;
    static float sec;
    static sfIntRect rect = {0, 0, 288, 288};

    time = sfClock_getElapsedTime(dwd->option.key.clock_key);
    sec = time.microseconds / 1000000.0;
    if (sec > 0.06) {
        rect.left += 288;
        if (rect.left > 3240)
            rect.left = 0;
        sfSprite_setTextureRect(dwd->option.key.champ_key, rect);
        sfClock_restart(dwd->option.key.clock_key);
    }
    sfRenderWindow_drawSprite(dwd->window, dwd->option.key.champ_key, NULL);
}

void act_button(dwd_t *dwd)
{
    if (active_button(dwd->menu.button.confirm, dwd->menu.button.confirm_t,
        sfRed, dwd) == 1 && dwd->option.key.is_clicked == -1) {
        dwd->is_open = OPTION;
        fill_my_keys(dwd);
    }
    for (int i = 0; i != 12; i++)
        insert_keys(dwd, dwd->option.key.key[i]);
}

void main_keybinding(dwd_t *dwd)
{
    while (dwd->is_open == KEYBINDING) {
        anime_menu(dwd);
        while (sfRenderWindow_pollEvent(dwd->window, &dwd->event)) {
            mouse(dwd);
            act_button(dwd);
        }
        display_all_keybinding(dwd);
        anime_key_champ(dwd);
        disp_mouse(dwd);
        sfRenderWindow_display(dwd->window);
    }
}
