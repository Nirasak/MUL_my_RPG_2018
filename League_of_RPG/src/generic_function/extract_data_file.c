/*
** EPITECH PROJECT, 2019
** RPG
** File description:
** extract_data_file
*/

#include "my.h"

int malloc_my_tab(char ***tab, int total_len, char *file)
{
    FILE *fd = fopen(file, "r");
    char *buffer = NULL;
    size_t sz = 0;
    int i = 0;

    if ((*tab = malloc(sizeof(char *) * (total_len + 1))) == NULL)
        return (84);
    for (; getline(&buffer, &sz, fd) > 0; i++) {
        (*tab)[i] = my_strdup(buffer);
        (*tab)[i][my_strlen((*tab)[i]) - 1] = '\0';
        if (i == 0 && my_strcmp((*tab)[i], "333666999") != 0)
            return (84);
    }
    (*tab)[i] = NULL;
    fclose(fd);
    return (0);
}

int extract_data_file(char *file, char ***tab)
{
    FILE *fd = fopen(file, "r");
    char *buffer = NULL;
    ssize_t len = 0;
    size_t sz = 0;
    int total_len = 0;

    if (fd == NULL)
        return (84);
    while ((len  = getline(&buffer, &sz, fd)) > 0)
        total_len += len;
    fclose(fd);
    return (malloc_my_tab(tab, total_len, file));
}

int extract_saved_value(char *obj, char **tab)
{
    char *output = NULL;

    for (int i = 0; tab[i] != NULL; i++) {
        if (my_str_egal_cmp(tab[i], obj) == 0 &&
            (output = alloc_my_path(tab[i])) == NULL)
            return (84);
        if (output != NULL) {
            return (my_atoi(output));
        }
    }
    return (84);
}

char *extract_string_value(char *obj, char **tab)
{
    char *output = NULL;

    for (int i = 0; tab[i] != NULL; i++) {
        if (my_str_egal_cmp(tab[i], obj) == 0 &&
            (output = alloc_my_path(tab[i])) == NULL)
            return (NULL);
        if (output != NULL) {
            return (output);
        }
    }
    return (NULL);
}
