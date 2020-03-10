/*
** EPITECH PROJECT, 2019
** RPG
** File description:
** create sprite from file
*/

#include "my.h"

int my_str_egal_cmp(char const *s1, char const *s2)
{
    int i = 0;

    for (; s1[i] != '=' && s2[i] != '\0' && s1[i] == s2[i]; i++) {
        if (s1[i] != '=' && s2[i] == '\0')
            return (1);
        if (s1[i] == '=' && s2[i] != '\0')
            return (-1);
    }
    if (s1[i] == '=' && s2[i] == '\0')
        return (0);
    if (s1[i] > s2[i])
        return (1);
    else
        return (-1);
}

char *alloc_my_path(char *str)
{
    int i;
    int j;
    int k = 0;
    char *dest = NULL;

    for (i = 0; str[i] != '='; i++);
    for (j = 0; str[j] != '\0'; j++);
    j -= i;
    if ((dest = malloc(j + 1)) == NULL)
        return (NULL);
    for (i += 1; str[i] != '\0'; i++, k++)
        dest[k] = str[i];
    dest[k] = '\0';
    return (dest);
}

char *find_obj(char **tab, char *obj)
{
    char *path = NULL;

    for (int i = 0; tab[i] != NULL; i++) {
        if (my_str_egal_cmp(tab[i], obj) == 0 &&
            (path = alloc_my_path(tab[i])) == NULL)
            return (NULL);
        if (path != NULL) {
            return (path);
        }
    }
    return (NULL);
}

sfSprite *f_sprite_create(char *obj, char **tab, float x, float y)
{
    sfSprite *sprite;
    sfTexture *text;
    sfVector2f pos;
    char *path = find_obj(tab, obj);

    if (path == NULL)
        return (NULL);
    pos.x = x;
    pos.y = y;
    text = sfTexture_createFromFile(path, NULL);
    sprite = sfSprite_create();
    sfSprite_setTexture(sprite, text, sfTrue);
    sfSprite_setPosition(sprite, pos);
    return (sprite);
}
