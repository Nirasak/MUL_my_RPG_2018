/*
** EPITECH PROJECT, 2019
** check_enemy
** File description:
** check which enemy draw
*/

#include "my.h"

char *check_little_enemy(fight_t *f)
{
    if (f->quest == 3) {
        f->report.gold = 200;
        f->report.xp = 100;
        return ("MINION");
    }
    if (f->quest == 4) {
        f->report.gold = 500;
        f->report.xp = 250;
        return ("CORBAC");
    }
    if (f->quest == 5) {
        f->report.gold = 1000;
        f->report.xp = 500;
        return ("BCORBAC");
    }
    f->report.gold = 10000;
    f->report.xp = 10000;
    return ("VEIGAR");
}

char *check_enemy(fight_t *f)
{
    if (f->quest == 3 || f->quest == 4 || f->quest == 5)
        return (check_little_enemy(f));
    if (f->quest == 6) {
        f->report.gold = 2000;
        f->report.xp = 800;
        return ("JINX");
    }
    if (f->quest == 7) {
        f->report.gold = 5000;
        f->report.xp = 1500;
        return ("NASH");
    }
    f->report.gold = 10000;
    f->report.xp = 10000;
    return ("VEIGAR");
}
