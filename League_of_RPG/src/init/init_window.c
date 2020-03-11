/*
** EPITECH PROJECT, 2019
** init_window.c
** File description:
** init my window
*/

#include "my.h"

void ini_window(dwd_t *dwd, int fscreen)
{
    dwd->window = create_mywindow(1920, 1080, fscreen);
    sfRenderWindow_setVerticalSyncEnabled(dwd->window, sfTrue);
    sfRenderWindow_setFramerateLimit(dwd->window, 60);
}
