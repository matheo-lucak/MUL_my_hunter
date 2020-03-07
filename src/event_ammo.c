/*
** EPITECH PROJECT, 2019
** init
** File description:
** init struct and sprites
*/

#include "my.h"
#include "duck_hunth.h"

void fire_ammo(cannon_t *cannon, ammo_t *ammo)
{
    if (cannon->is_fire_able == 6) {
        if (sfKeyboard_isKeyPressed(sfKeyNumpad1) ||
            sfKeyboard_isKeyPressed(sfKeyNum1))
            carrot_throw(cannon, ammo->carrot_arr);
        if (sfKeyboard_isKeyPressed(sfKeyNumpad2) ||
            sfKeyboard_isKeyPressed(sfKeyNum2))
            seed_throw(cannon, ammo->seed_arr);
    cannon->is_fire_able = 0;
    }
}

void is_ammo_disp(win_t *win, ammo_t *ammo)
{
    int i = -1;

    while (++i < 5) {
        if (ammo->carrot_arr->carrot_status[i] == 2)
            disp_carrot(win, ammo->carrot_arr->carrot[i]);
        if (ammo->seed_arr->seed_status[i] == 2)
            disp_seed(win, ammo->seed_arr->seed[i]);
    }
}