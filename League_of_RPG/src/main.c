/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** create my main function for my rpg
*/

#include "my.h"

int main(int ac, char **av, char **env)
{
    if (ac != 1 || av[0] == NULL)
        return (84);
    for (int i = 0; env[i] != NULL; i++) {
        if (my_strncmp("DISPLAY=", env[i], 8) == 0)
            return (my_rpg());
    }
    write(2, "Error: invalid env\n", 19);
    return (84);
}
