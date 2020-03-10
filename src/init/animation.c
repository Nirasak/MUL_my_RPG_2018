/*
** EPITECH PROJECT, 2019
** animation.c
** File description:
** create my animation
*/

#include "my.h"

int init_animation(dwd_t *dwd)
{
    char **map;

    if (extract_data_file("src/menu/.loading_menu", &map) == 84)
        return (84);
    dwd->animation = f_sprite_create("ANIMATION1", map, 0, 0);
    dwd->animation2 = f_sprite_create("ANIMATION2", map, 0, 0);
    dwd->clock_anime = sfClock_create();
    dwd->clock_key = sfClock_create();
    change_scale(dwd->animation, 3.2, 3.2);
    change_scale(dwd->animation2, 3.2, 3.2);
    return (0);
}

static int which_draw(dwd_t *dwd, int use)
{
    if (use == 0) {
        sfRenderWindow_drawSprite(dwd->window, dwd->animation, NULL);
    }
    else if (use == 1) {
        sfRenderWindow_drawSprite(dwd->window, dwd->animation2, NULL);
    }
    else {
        dwd->menu.profile.played = 1;
        modify_data(dwd, "played=", my_itoa(dwd->menu.profile.played));
        update_saves(dwd);
        return (1);
    }
    return (0);
}

static void anime_condi(dwd_t *dwd, int *use, sfIntRect *rect, int *count)
{
    rect->left = rect->left + 600;
    if (*use == 1)
        sfSprite_setTextureRect(dwd->animation2, *rect);
    else
        sfSprite_setTextureRect(dwd->animation, *rect);
    sfClock_restart(dwd->clock_anime);
    if (rect->left == 8400) {
        rect->left = 0;
        rect->top = rect->top + 338;
        (*count)++;
    }
    if (*use == 0 && *count == 7 && rect->left == 3000) {
        rect->top = 0;
        (*count) = 0;
        (*use)++;
    }
}

int key_passed(dwd_t *dwd)
{
    static sfTime time;
    static float sec;

    time = sfClock_getElapsedTime(dwd->clock_key);
    sec += time.microseconds / 1000000.0;
    sfClock_restart(dwd->clock_key);
    while (sfRenderWindow_pollEvent(dwd->window, &dwd->event)) {
        if (sec > 1 && dwd->event.type == sfEvtKeyPressed) {
            dwd->menu.profile.played = 1;
            modify_data(dwd, "played=", my_itoa(dwd->menu.profile.played));
            modify_data(dwd, "diff=", my_itoa(dwd->menu.profile.played));
            update_saves(dwd);
            return (1);
        }
    }
    return (0);
}

int anime_animation(dwd_t *dwd)
{
    static sfTime time;
    static float sec;
    static sfIntRect rect = {0, 0, 600, 350};
    static int count = 0;
    static int use = 0;

    time = sfClock_getElapsedTime(dwd->clock_anime);
    sec = time.microseconds / 1000000.0;
    if (sec > 0.08) {
        anime_condi(dwd, &use, &rect, &count);
        if (use >= 1 && count == 7 && rect.left > 0) {
            use++;
        }
    }
    if (which_draw(dwd, use) == 1 || key_passed(dwd) == 1)
        return (1);
    sfRenderWindow_display(dwd->window);
    return (0);
}
