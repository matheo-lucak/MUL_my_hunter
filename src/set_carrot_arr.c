/*
** EPITECH PROJECT, 2019
** init
** File description:
** init struct and sprites
*/

#include <stdio.h>
#include "my.h"
#include "duck_hunth.h"

int init_carrot_arr(carrot_arr_t *carrot_arr)
{
    carrot_arr->carrot_status = malloc(sizeof(int) * 5);
    carrot_arr->carrot = malloc(sizeof(carrot_t *) * 6);
    carrot_arr->carrot[5] = NULL;
    if (carrot_arr->carrot_status == NULL || carrot_arr->carrot == NULL)
        return (84);
    carrot_arr->carrot_status[0] = 1;
    carrot_arr->carrot_status[1] = 1;
    carrot_arr->carrot_status[2] = 1;
    carrot_arr->carrot_status[3] = 1;
    carrot_arr->carrot_status[4] = 1;
    if (init_carrot(carrot_arr) == 84)
        return (84);
    return (0);
}

void reset_carrot_arr(win_t *win, carrot_arr_t *carrot_arr)
{
    int i = -1;

    while (++i < 5) {
        if (carrot_arr->carrot_status[i] == 2 &&
            (carrot_arr->carrot[i]->pos.y < 0 ||
            carrot_arr->carrot[i]->pos.x < 0 ||
            carrot_arr->carrot[i]->pos.y > win->video_mode.height ||
            carrot_arr->carrot[i]->pos.x > win->video_mode.width)) {
            carrot_arr->carrot_status[i] = 1;
            reset_carrot(carrot_arr->carrot[i]);
            }
    }
}