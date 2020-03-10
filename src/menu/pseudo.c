/*
** EPITECH PROJECT, 2019
** RPG
** File description:
** pseudo
*/

#include "my.h"

void get_cara(dwd_t *dwd, char *my_font)
{
    char c;

    if (dwd->event.type == sfEvtTextEntered) {
        c = dwd->event.text.unicode;
        if (c == 8)
            dell_last_cara(&dwd->pseudo);
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == 32)
            (dwd->pseudo == NULL || my_strlen(dwd->pseudo) < 10) ?
                fill_my_string(&dwd->pseudo, c) : 0;
        dwd->pseudo_t = create_button_text(my_font, dwd->pseudo, 100, sfWhite);
        set_pos_pseudo(dwd->pseudo_t, dwd->pseudo);
    }
}

void first_pseudo_init(dwd_t *dwd, sfText **text_pseudo, char *my_font)
{
    char *message;
    sfVector2f pos_txt;

    dwd->pseudo = extract_string_value("pseudo", dwd->menu.data);
    if (my_strcmp(dwd->pseudo, "123456789") == 0) {
        dwd->pseudo = NULL;
        dwd->is_open = PSEUDO;
        pos_txt.x = 220;
        pos_txt.y = 135;
        message = extract_string_value("choose_pseudo", dwd->menu.data);
        *text_pseudo = create_button_text(my_font, message, 100, sfWhite);
        sfText_setPosition(*text_pseudo, pos_txt);
    }
}

void cat_path(dwd_t *dwd, int i)
{
    char *full_path = malloc
        (my_strlen(dwd->pseudo) + my_strlen(dwd->menu.data[i]) + 1);
    char *path = malloc(7);
    int j = 0;

    for (; dwd->menu.data[i][j] != '='; j++)
        path[j] = dwd->menu.data[i][j];
    path[j] = '=';
    path[j + 1] = '\0';
    full_path = my_strcat(path, dwd->pseudo, full_path);
    free(dwd->menu.data[i]);
    dwd->menu.data[i] = my_strdup(full_path);
    free(full_path);
    free(path);
}

void modify_pseudo(dwd_t *dwd)
{
    int fd;

    if (active_button(dwd->menu.button.confirm,
        dwd->menu.button.confirm_t, sfRed, dwd) == 1 && dwd->pseudo != NULL &&
        dwd->pseudo[0] != '\0') {
        dwd->is_open = MENU;
        fd = open("./src/menu/.loading_menu", O_WRONLY | O_TRUNC);
        update_saves(dwd);
        init_profiles(dwd);
        for (int i = 0; dwd->menu.data[i] != NULL; i++) {
            my_strncmp(dwd->menu.data[i], "pseudo", 6) == 0 ?
                cat_path(dwd, i) : 0;
            write(fd, dwd->menu.data[i], my_strlen(dwd->menu.data[i]));
            write(fd, "\n", 1);
        }
    }
}

void pseudo_menu(dwd_t *dwd)
{
    char *my_font = extract_string_value("font", dwd->menu.data);
    sfText *text_pseudo;

    first_pseudo_init(dwd, &text_pseudo, my_font);
    while (dwd->is_open == PSEUDO) {
        if (sfRenderWindow_pollEvent(dwd->window, &dwd->event)) {
            mouse(dwd);
            get_cara(dwd, my_font);
            modify_pseudo(dwd);
        }
        anime_menu(dwd);
        sfRenderWindow_drawSprite(dwd->window, dwd->menu.board, NULL);
        sfRenderWindow_drawText(dwd->window, text_pseudo, NULL);
        if (dwd->pseudo != NULL)
            sfRenderWindow_drawText(dwd->window, dwd->pseudo_t, NULL);
        sfRenderWindow_drawSprite(dwd->window, dwd->menu.button.confirm, NULL);
        sfRenderWindow_drawText(dwd->window, dwd->menu.button.confirm_t, NULL);
        disp_mouse(dwd);
        sfRenderWindow_display(dwd->window);
    }
}
