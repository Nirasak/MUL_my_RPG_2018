/*
** EPITECH PROJECT, 2019
** rpg.c
** File description:
** create my rpg loop
*/

#include "my.h"

int my_rpg(void)
{
    dwd_t dwd;
    fight_t fight;
    map_t map;

    if (init_all(&dwd, &fight, &map) == 84)
        return (84);
    pseudo_menu(&dwd);
    while (sfRenderWindow_isOpen(dwd.window)) {
        main_menu(&dwd, &fight, &map);
        gameplay_map(&map, &dwd, &fight);
        if (dwd.is_open != MENU && dwd.is_open != LEAVE)
            after_instance(&map, &dwd);
        sfRenderWindow_display(dwd.window);
    }
    destroy_all(&dwd, &fight);
    return (0);
}
