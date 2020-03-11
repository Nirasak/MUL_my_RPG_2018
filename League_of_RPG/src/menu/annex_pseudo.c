/*
** EPITECH PROJECT, 2019
** RPG
** File description:
** annex_pseudo
*/

#include "my.h"

void dell_last_cara(char **name)
{
    char *save_name;
    int i;

    if (*name == NULL)
        return;
    else {
        save_name = my_strdup(*name);
        *name = malloc(my_strlen(*name));
    }
    for (i = 0; my_strlen(save_name) - 1 > i; i++)
        (*name)[i] = save_name[i];
    (*name)[i] = '\0';
}

void fill_my_string(char **name, char caracter)
{
    char *save_name = "\0";
    int k = 0;

    if (*name == NULL)
        *name = malloc(2);
    else {
        save_name = my_strdup(*name);
        *name = malloc(my_strlen(*name) + 2);
    }
    for (int i = 0; save_name[i] != '\0'; i++, k++)
        (*name)[k] = save_name[i];
    (*name)[k] = caracter;
    (*name)[k + 1] = '\0';
}

void set_pos_pseudo(sfText *user_pseudo, char *name)
{
    sfVector2f pos_pseudo = {915, 400};

    if (my_strlen(name) > 1)
        pos_pseudo.x = 915 - (21.5 * (my_strlen(name) - 1));
    sfText_setPosition(user_pseudo, pos_pseudo);
}
