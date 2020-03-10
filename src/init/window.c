/*
** EPITECH PROJECT, 2018
** my_runner
** File description:
** window
*/

#include "my.h"

sfRenderWindow *create_mywindow(unsigned int width, unsigned int height,
int fscreen)
{
    sfRenderWindow *window;
    sfVideoMode vd_md = {width, height, 32};

    if (fscreen == 1)
        window = sfRenderWindow_create(vd_md, "Quest League",
                                    sfFullscreen | sfClose, NULL);
    else
        window = sfRenderWindow_create(vd_md, "Quest League",
                                    sfResize | sfClose, NULL);
    return (window);
}
