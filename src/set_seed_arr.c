/*
** EPITECH PROJECT, 2019
** init
** File description:
** init struct and sprites
*/

#include <stdio.h>
#include "my.h"
#include "duck_hunth.h"

int init_seed_arr(seed_arr_t *seed_arr)
{
    seed_arr->seed_status = malloc(sizeof(int) * 5);
    seed_arr->seed = malloc(sizeof(seed_t *) * 6);
    seed_arr->seed[5] = NULL;
    if (seed_arr->seed_status == NULL || seed_arr->seed == NULL)
        return (84);
    seed_arr->seed_status[0] = 1;
    seed_arr->seed_status[1] = 1;
    seed_arr->seed_status[2] = 1;
    seed_arr->seed_status[3] = 1;
    seed_arr->seed_status[4] = 1;
    if (init_seed(seed_arr) == 84)
        return (84);
    return (0);
}

void reset_seed_arr(win_t *win, seed_arr_t *seed_arr)
{
    int i = -1;

    while (++i < 5) {
        if (seed_arr->seed_status[i] == 2 &&
            (seed_arr->seed[i]->pos.y < 0 ||
            seed_arr->seed[i]->pos.x < 0 ||
            seed_arr->seed[i]->pos.y > win->video_mode.height ||
            seed_arr->seed[i]->pos.x > win->video_mode.width)) {
            seed_arr->seed_status[i] = 1;
            reset_seed(seed_arr->seed[i]);
            }
    }
}