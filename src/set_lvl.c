/*
** EPITECH PROJECT, 2019
** init
** File description:
** init struct and sprites
*/

#include <time.h>
#include "my.h"
#include "duck_hunth.h"

void check_lvl(win_t *win, obj_t *obj)
{
    obj->bg->bg_index = win->lvl - 1;
    if ((win->lvl == 1 && win->score >= 150) ||
        (win->lvl == 2 && win->score >= 500) ||
        (win->lvl == 3 && win->score >= 1000)) {
        reset_carrot_arr(win, obj->ammo->carrot_arr);
        reset_seed_arr(win, obj->ammo->seed_arr);
        win->lvl++;
    }
}