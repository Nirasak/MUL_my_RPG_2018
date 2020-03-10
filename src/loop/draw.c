/*
** EPITECH PROJECT, 2019
** draw.c
** File description:
** draw my sprite on loop
*/

#include "my.h"

void draw_spawn(dwd_t *dwd, fight_t *f)
{
    sfRenderWindow_drawSprite(dwd->window, f->spawn.bg, NULL);
    sfRenderWindow_drawSprite(dwd->window, f->spawn.tamo, NULL);
    sfRenderWindow_drawSprite(dwd->window, f->spawn.rock, NULL);
    draw_enemy(dwd, f);
    sfRenderWindow_drawSprite(dwd->window, f->spawn.bush, NULL);
    anime_poro(f);
    move_tamo(f);
    anime_rporo(f);
    anime_tamo(f);
    shop_loop(dwd, f);
    draw_interface(dwd, f);
    draw_cara_quest(dwd, f);
    f->cait.spe[9] = f->cait.spe[10];
    loop_fight(dwd, f);
    sfRenderWindow_drawSprite(dwd->window, f->spell.abilities[1], NULL);
    sfRenderWindow_drawSprite(dwd->window, f->spell.abilities[3], NULL);
    sfRenderWindow_drawText(dwd->window, f->spawn.text, NULL);
    sfRenderWindow_drawSprite(dwd->window, dwd->menu.button.map, NULL);
    sfRenderWindow_drawText(dwd->window, dwd->menu.button.map_t, NULL);
}

void draw_enemy(dwd_t *dwd, fight_t *f)
{
    draw_enemy_life(f);
    sfRenderWindow_drawSprite(dwd->window, f->enemy.enemy, NULL);
    sfRenderWindow_drawSprite(dwd->window, f->enemy.attackspr, NULL);
    sfRenderWindow_drawSprite(dwd->window, f->enemy.attacksprtwo, NULL);
    sfRenderWindow_drawSprite(dwd->window, f->enemy.life_enemy_back, NULL);
    sfRenderWindow_drawSprite(dwd->window, f->enemy.life_enemy, NULL);
    sfRenderWindow_drawSprite(dwd->window, f->cait.impact, NULL);
}

void draw_stat(dwd_t *dwd, fight_t *f)
{
    for (int i = 0; i != 4; i++)
        if (f->spell.unlock_spell[i] != 0 && f->spell.cooldown[i] == 0)
            sfRenderWindow_drawSprite(dwd->window, f->spell.icon_abi[i], NULL);
    sfText_setString(f->spell.text[1], my_itoa_crit(f->cait.spe[1]));
    sfText_setString(f->spell.text[2], my_itoa_crit(f->cait.life_steal));
    for (int i = 0; i != 11; i++) {
        if (i != 1 && i != 2)
            sfText_setString(f->spell.text[i], my_itoa(f->cait.spe[i]));
        sfRenderWindow_drawText(dwd->window, f->spell.text[i], NULL);
    }
}

static void disp_it(dwd_t *dwd, fight_t *f)
{
    for (int i = 0; i != 5; i++) {
        sfText_setString
            (f->spell.cooldown_text[i], my_itoa(f->spell.cooldown[i]));
        if (f->spell.cooldown[i] != 0)
            sfRenderWindow_drawText
                (dwd->window, f->spell.cooldown_text[i], NULL);
    }
}

void draw_interface(dwd_t *dwd, fight_t *f)
{
    sfRenderWindow_drawSprite(dwd->window, f->cait.sprite, NULL);
    sfRenderWindow_drawSprite(dwd->window, f->cait.shot, NULL);
    sfRenderWindow_drawSprite(dwd->window, f->spell.select_abi, NULL);
    sfRenderWindow_drawSprite(dwd->window, f->spell.interface, NULL);
    sfRenderWindow_drawSprite(dwd->window, f->spell.inventory, NULL);
    anime_xpbar(dwd, f);
    unlock_abi(dwd, f);
    draw_life(dwd, f);
    draw_stat(dwd, f);
    print_money(dwd, f, 2);
    handle_item(dwd, f, 2);
    sfRenderWindow_drawSprite(dwd->window, f->shop.heal, NULL);
    disp_it(dwd, f);
}
