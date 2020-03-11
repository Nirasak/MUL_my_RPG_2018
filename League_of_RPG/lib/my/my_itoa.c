/*
** EPITECH PROJECT, 2018
** my_itoa
** File description:
** convert a int into a char *
*/

#include <stdlib.h>

int my_intlen(int nb)
{
    int i = 0;

    while (nb > 0) {
        nb = nb / 10;
        i = i + 1;
    }
    return (i);
}

int my_compute_power_rec(int nb, int p)
{
    int result = 1;

    while (p >= 1) {
        result = result * nb;
        p = p - 1;
    }
    return (result);
}

char *my_itoa(int nb)
{
    int len = my_intlen(nb);
    int stock_len = len;
    char *str = malloc(sizeof(char) * (len + 1));
    int result = 0;
    int i = 0;

    if (nb == 0)
        return ("0");
    while (i < stock_len) {
        len = len - 1;
        result = nb / my_compute_power_rec(10, len);
        str[i] = result + '0';
        nb = nb - result * my_compute_power_rec(10, len);
        i = i + 1;
    }
    str[i] = '\0';
    return (str);
}

char *cond_crit_itoa(char *str, int i)
{
    str[i] = '0';
    str[i + 1] = '%';
    str[i + 2] = '\0';
    return (str);
}

char *my_itoa_crit(int nb)
{
    int len = my_intlen(nb);
    int stock_len = len;
    char *str = malloc(sizeof(char) * (len + 3));
    int result = 0;
    int i = 0;

    if (nb == 0)
        return (cond_crit_itoa(str, i));
    while (i < stock_len) {
        len = len - 1;
        result = nb / my_compute_power_rec(10, len);
        str[i] = result + '0';
        nb = nb - result * my_compute_power_rec(10, len);
        i = i + 1;
    }
    str[i] = '%';
    str[i + 1] = '\0';
    return (str);
}
