/*
** EPITECH PROJECT, 2019
** RPG
** File description:
** init_cara_annex
*/

#include "my.h"

void annex_init_abilities_icon(fight_t *f, char **path)
{
    for (int i = 0; i != 4; i++) {
        f->spell.unlock[i] = f_sprite_create("UNLOCK", path, 730, 842);
        change_scale(f->spell.unlock[i], 1.3, 1.3);
        change_scale(f->spell.icon_abi[i], 0.43, 0.43);
        f->spell.unlock_spell[i] = 0;
    }
    f->stun = 0;
}

int init_abilities_icon(fight_t *f)
{
    sfVector2f pos = {95, 1012};
    char **path;

    if (extract_data_file("./src/menu/.cara", &path) == 84)
        return (84);
    sfText_setColor(f->spell.text[6], sfBlue);
    sfText_setPosition(f->spell.text[6], pos);
    f->spell.icon_abi = malloc(sizeof(sfSprite *) * 5);
    f->spell.unlock = malloc(sizeof(sfSprite *) * 5);
    f->spell.unlock_spell = malloc(sizeof(int) * 5);
    f->spell.icon_abi[0] = f_sprite_create("SPELL1", path, 736, 927);
    f->spell.icon_abi[1] = f_sprite_create("SPELL2", path, 815, 927);
    f->spell.icon_abi[2] = f_sprite_create("SPELL3", path, 892, 927);
    f->spell.icon_abi[3] = f_sprite_create("SPELL4", path, 968, 927);
    annex_init_abilities_icon(f, path);
    return (0);
}

void annex_init_abilities(fight_t *f)
{
    for (int i = 0; i != 4; i++) {
        f->spell.clock_abi[i] = sfClock_create();
        f->spell.text_dmg[i] = sfText_create();
    }
}

static void first_init(fight_t *f, char **path)
{
    f->spell.abilities[1] = f_sprite_create("TRAP", path, 1345, 760);
    f->spell.stun = f_sprite_create("STUN", path, 1265, 430);
    f->spell.qspell = f_sprite_create("QSPELL", path, 300, 600);
    f->spell.espell = f_sprite_create("ESPELL", path, -20, 300);
    f->spell.clock_espell = sfClock_create();
    change_scale(f->spell.espell, 3.0, 3.0);
    change_scale(f->spell.qspell, 0.5, 0.5);
    f->spell.clock_ult = sfClock_create();
    f->spell.clock_stun = sfClock_create();
    f->spell.clock_qspell = sfClock_create();
    f->spell.move_qspell = sfClock_create();
    change_scale(f->spell.stun, 0.4, 0.4);
}

int init_abilities(fight_t *f)
{
    sfVector2f origin = {516 / 2, 389 / 2};
    char **path;
    sfVector2f pos = pos_cait_corp(f);

    pos.y = pos.y + 70;
    if (extract_data_file("./src/menu/.cara", &path) == 84)
        return (84);
    init_abilities_icon(f);
    f->spell.clock_abi = malloc(sizeof(sfClock *) * 5);
    f->spell.abilities = malloc(sizeof(sfSprite *) * 5);
    f->spell.text_dmg = malloc(sizeof(sfText *) * 5);
    first_init(f, path);
    f->spell.abilities[3] = f_sprite_create("ULT", path, pos.x, pos.y);
    change_scale(f->spell.abilities[3], 0.01, 0.01);
    sfSprite_setOrigin(f->spell.abilities[3], origin);
    annex_init_abilities(f);
    return (0);
}
