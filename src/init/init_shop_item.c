/*
** EPITECH PROJECT, 2019
** init_shop_item.c
** File description:
** init my item stat
*/

#include "my.h"

void annex_create_item_text(fight_t *f, sfVector2f pos)
{
    f->shop.text[0] = sfText_create();
    sfText_setFont(f->shop.text[0], f->shop.font);
    sfText_setColor(f->shop.text[0], sfRed);
    sfText_setPosition(f->shop.text[0], pos);
    sfText_setCharacterSize(f->shop.text[0], 35);
    pos.x = 1040;
    pos.y = 710;
    for (int i = 1; i != 4; i++) {
        f->shop.text[i] = sfText_create();
        sfText_setFont(f->shop.text[i], f->shop.font);
        sfText_setColor(f->shop.text[i], sfWhite);
        sfText_setPosition(f->shop.text[i], pos);
        sfText_setCharacterSize(f->shop.text[i], 30);
        pos.x = pos.x;
        pos.y = pos.y + 40;
    }
}

int create_item_text(fight_t *f)
{
    sfVector2f pos;

    f->shop.text = malloc(sizeof(sfText *) * 5);
    pos.x = 1160;
    pos.y = 630;
    f->shop.font = sfFont_createFromFile("./assets/cara/font.otf");
    if (!f->shop.font)
        return (84);
    annex_create_item_text(f, pos);
    pos.x = 1220;
    pos.y = 920;
    sfText_setColor(f->shop.text[3], sfYellow);
    sfText_setPosition(f->shop.text[3], pos);
    return (0);
}

void create_popo(fight_t *f)
{
    sfIntRect rect2 = {0, 0, 480, 480};

    f->shop.popo = create_sprite("./assets/spawn/item.png", 1055, 932);
    sfSprite_setTextureRect(f->shop.popo, rect2);
    change_scale(f->shop.popo, 0.10, 0.10);
}

int init_shop_item(fight_t *f)
{
    sfVector2f pos = {363, 930};
    sfIntRect rect = {0, 0, 0, 0};

    if (extract_data_file("./src/menu/.item", &f->shop.text_item) == 84)
        return (84);
    if (create_item_text(f) == 84)
        return (84);
    f->shop.item = malloc(sizeof(sfSprite *) * 7);
    for (int i = 0; i != 6; i++) {
        f->shop.item[i] = create_sprite
            ("./assets/spawn/item.png", pos.x, pos.y);
        change_scale(f->shop.item[i], 0.12, 0.12);
        pos.x = pos.x + 65;
    }
    sfSprite_setTextureRect(f->spell.abilities[1], rect);
    create_popo(f);
    return (0);
}
