/*
** EPITECH PROJECT, 2019
** RPG
** File description:
** init_lore
*/

#include "my.h"

int init_lore(dwd_t *dwd)
{
    int i;
    char *my_font = extract_string_value("font", dwd->menu.data);
    sfIntRect rect = {0, 0, 260, 288};

    if (extract_data_file("src/menu/.story", &dwd->menu.data_lore) == 84)
        return (84);
    dwd->menu.clock_lore = sfClock_create();
    dwd->menu.lore_champ = f_sprite_create("LORE2", dwd->menu.data, 215, 325);
    sfSprite_setTextureRect(dwd->menu.lore_champ, rect);
    for (i = 0; dwd->menu.data_lore[i] != NULL; i++);
    dwd->menu.lore = malloc(sizeof(sfText *) * i);
    dwd->menu.lore[0] = create_button_text(my_font, "Lore", 100, sfWhite);
    pos_text(dwd->menu.lore[0], 1000, 140);
    for (i = 1; dwd->menu.data_lore[i] != NULL; i++) {
        dwd->menu.lore[i] = create_button_text
            (my_font, dwd->menu.data_lore[i], 50, sfWhite);
        pos_text(dwd->menu.lore[i], 550, 235 + (60 * i));
    }
    return (0);
}
