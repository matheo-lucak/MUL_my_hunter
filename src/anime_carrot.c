/*
** EPITECH PROJECT, 2019
** init
** File description:
** init struct and sprites
*/

#include <stdio.h>
#include "my.h"
#include "duck_hunth.h"

void disp_carrot(win_t *win, carrot_t *carrot)
{
    sfVector2f ant_pos;

    ant_pos.x = carrot->pos.x;
    ant_pos.y = 0.5 * carrot->g * my_powf((carrot->pos.x - carrot->p0.x) /
        carrot->vector.x, 2) + (carrot->vector.y *
        (carrot->pos.x - carrot->p0.x)/ carrot->vector.x) + carrot->p0.y;
    carrot->pos.x += carrot->vector.x * carrot->speed;
    carrot->pos.y = 0.5 * carrot->g * my_powf((carrot->pos.x - carrot->p0.x) /
        carrot->vector.x, 2) + (carrot->vector.y *
        (carrot->pos.x - carrot->p0.x)/ carrot->vector.x) + carrot->p0.y;
    sfSprite_setTexture(carrot->sprite, carrot->texture, sfTrue);
    sfSprite_setPosition(carrot->sprite, carrot->pos);
    if (carrot->pos.x - ant_pos.x > 0)
    sfSprite_setRotation(carrot->sprite, atan((carrot->pos.y - ant_pos.y) /
        (carrot->pos.x - ant_pos.x)) * 180 / M_PI - 135);
    else
    sfSprite_setRotation(carrot->sprite, atan((carrot->pos.y - ant_pos.y) /
        (carrot->pos.x - ant_pos.x)) * 180 / M_PI + 45);
    sfRenderWindow_drawSprite(win->window, carrot->sprite, NULL);
}

int carrot_throw(cannon_t *cannon, carrot_arr_t *carrot_arr)
{
    int i = -1;

    while (++i < 5) {
        if (carrot_arr->carrot_status[i] == 1) {
            carrot_arr->carrot_status[i] = 2;
            sfSound_play(cannon->fire_sound);
            set_carrot(cannon, carrot_arr->carrot[i]);
            return (0);
        }
    }
    return (0);
}