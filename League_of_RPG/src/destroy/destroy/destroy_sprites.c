/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** destroy sprites
*/

#include "my.h"

void destroy_sprites_menu_thrd(dwd_t *dwd)
{
    sfSprite_destroy(dwd->menu.profile.icon_board);
    for (int i = 0; i < 6; i = i + 1)
        sfSprite_destroy(dwd->menu.profile.acon[i]);
    for (int i = 0; i < 6; i = i + 1)
        sfSprite_destroy(dwd->menu.profile.icon[i]);
    sfSprite_destroy(dwd->menu.button.confirm);
    sfSprite_destroy(dwd->menu.button.play);
    sfSprite_destroy(dwd->menu.button.lore);
    sfSprite_destroy(dwd->menu.button.option);
    sfSprite_destroy(dwd->menu.button.leave);
    sfSprite_destroy(dwd->menu.button.back);
    sfSprite_destroy(dwd->menu.button.map);
    sfSprite_destroy(dwd->mouse.f_mouse);
    sfSprite_destroy(dwd->mouse.s_mouse);
    sfSprite_destroy(dwd->sound.music_bar);
    sfSprite_destroy(dwd->sound.sound_bar);
    sfSprite_destroy(dwd->sound.under_music);
    sfSprite_destroy(dwd->sound.under_sound);
    sfSprite_destroy(dwd->quest.s_inter);
    sfSprite_destroy(dwd->quest.s_excla);
}

void destroy_sprites_menu_scd(dwd_t *dwd)
{
    sfSprite_destroy(dwd->menu.menu);
    sfSprite_destroy(dwd->menu.menu2);
    sfSprite_destroy(dwd->menu.board);
    sfSprite_destroy(dwd->menu.lore_champ);
    sfSprite_destroy(dwd->menu.htp.next_bt);
    sfSprite_destroy(dwd->menu.htp.prev_bt);
    sfSprite_destroy(dwd->menu.htp.back_bt);
    sfSprite_destroy(dwd->menu.htp.champ_htp);
    sfSprite_destroy(dwd->menu.pause.pause_champ);
    sfSprite_destroy(dwd->menu.pause.resume);
    sfSprite_destroy(dwd->menu.pause.option);
    sfSprite_destroy(dwd->menu.pause.save);
    sfSprite_destroy(dwd->menu.pause.menu);
    sfSprite_destroy(dwd->menu.pause.leave);
    sfSprite_destroy(dwd->menu.diff.easy);
    sfSprite_destroy(dwd->menu.diff.medium);
    sfSprite_destroy(dwd->menu.diff.hard);
    sfSprite_destroy(dwd->menu.profile.profile_board);
    sfSprite_destroy(dwd->menu.profile.name_board);
    destroy_sprites_menu_thrd(dwd);
}

void destroy_sprites_menu(dwd_t *dwd)
{
    sfSprite_destroy(dwd->animation);
    sfSprite_destroy(dwd->animation2);
    sfSprite_destroy(dwd->save.save1_bt);
    sfSprite_destroy(dwd->save.save2_bt);
    sfSprite_destroy(dwd->save.save3_bt);
    for (int i = 0; i < 3; i = i + 1)
        sfSprite_destroy(dwd->option.bt_option[i]);
    sfSprite_destroy(dwd->option.f_cursor);
    sfSprite_destroy(dwd->option.s_cursor);
    sfSprite_destroy(dwd->option.htp);
    for	(int i = 0; i < 12; i = i + 1)
        sfSprite_destroy(dwd->option.key.key[i]);
    sfSprite_destroy(dwd->option.key.champ_key);
    for (int i = 0; i < 2; i = i + 1)
        sfSprite_destroy(dwd->option.utils.bt_bg[i]);
    for (int i = 0; i < 3; i = i + 1)
        sfSprite_destroy(dwd->option.utils.bt_fps[i]);
    destroy_sprites_menu_scd(dwd);
}
