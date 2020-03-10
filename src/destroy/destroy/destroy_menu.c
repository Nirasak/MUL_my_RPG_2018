/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** destroy
*/

#include "my.h"

void destroy_menu_scd(dwd_t *dwd)
{
    sfText_destroy(dwd->option.particle);
    sfText_destroy(dwd->option.confirm_particle);
}

void destroy_menu(dwd_t *dwd)
{
    sfClock_destroy(dwd->clock_anime);
    sfClock_destroy(dwd->clock_key);
    free(dwd->pseudo);
    sfText_destroy(dwd->pseudo_t);
    sfText_destroy(dwd->save.save1_t);
    sfText_destroy(dwd->save.save2_t);
    sfText_destroy(dwd->save.save3_t);
    for (int i = 0; dwd->save.data_save1[i]; i = i + 1)
        free(dwd->save.data_save1[i]);
    for	(int i = 0; dwd->save.data_save2[i]; i = i + 1)
        free(dwd->save.data_save2[i]);
    for	(int i = 0; dwd->save.data_save3[i]; i = i + 1)
        free(dwd->save.data_save3[i]);
    free(dwd->save.data_save1);
    free(dwd->save.data_save2);
    free(dwd->save.data_save3);
    sfText_destroy(dwd->option.f_screen);
    sfText_destroy(dwd->option.confirm_screen);
    destroy_menu_scd(dwd);
}
