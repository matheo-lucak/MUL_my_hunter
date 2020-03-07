/*
** EPITECH PROJECT, 2019
** init
** File description:
** init struct and sprites
*/

#include <stdio.h>
#include "my.h"
#include "duck_hunth.h"

void disp_seed(win_t *win, seed_t *seed)
{
    sfVector2f ant_pos;

    ant_pos.x = seed->pos.x;
    ant_pos.y = 0.5 * seed->g * my_powf((seed->pos.x - seed->p0.x) /
        seed->vector.x, 2) + (seed->vector.y *
        (seed->pos.x - seed->p0.x)/ seed->vector.x) + seed->p0.y;
    seed->pos.x += seed->vector.x * seed->speed;
    seed->pos.y = 0.5 * seed->g * my_powf((seed->pos.x - seed->p0.x) /
        seed->vector.x, 2) + (seed->vector.y *
        (seed->pos.x - seed->p0.x)/ seed->vector.x) + seed->p0.y;
    sfSprite_setTexture(seed->sprite, seed->texture, sfTrue);
    sfSprite_setPosition(seed->sprite, seed->pos);
    if (seed->pos.x - ant_pos.x > 0) {
    sfSprite_setRotation(seed->sprite, atan((seed->pos.y - ant_pos.y) /
        (seed->pos.x - ant_pos.x)) * 180 / M_PI + 90);
    } else {
    sfSprite_setRotation(seed->sprite, atan((seed->pos.y - ant_pos.y) /
        (seed->pos.x - ant_pos.x)) * 180 / M_PI - 90);
    }
    sfRenderWindow_drawSprite(win->window, seed->sprite, NULL);
}

int seed_throw(cannon_t *cannon, seed_arr_t *seed_arr)
{
    int i = -1;

    while (++i < 5) {
        if (seed_arr->seed_status[i] == 1) {
            seed_arr->seed_status[i] = 2;
            sfSound_play(cannon->fire_sound);
            set_seed(cannon, seed_arr->seed[i]);
            return (0);
        }
    }
    return (0);
}