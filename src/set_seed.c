/*
** EPITECH PROJECT, 2019
** init
** File description:
** init struct and sprites
*/

#include <stdio.h>
#include "my.h"
#include "duck_hunth.h"

void set_init_seed_value(seed_t *seed)
{
    seed->pos.x = -100;
    seed->pos.y = -100;
    seed->vector.x = 0;
    seed->vector.y = 0;
    seed->size.x = 50;
    seed->size.y = 30;
}

int init_seed(seed_arr_t *seed_arr)
{
    int i = -1;
    sfVector2f origin;

    origin.x = 18.5;
    origin.y = 15;
    while (++i < 5) {
        seed_arr->seed[i] = malloc(sizeof(seed_t));
        seed_arr->seed[i]->texture = sfTexture_createFromFile
            ("./sprite/seed.png", NULL);
        seed_arr->seed[i]->sprite = sfSprite_create();
        if (seed_arr->seed[i] == NULL ||
            seed_arr->seed[i]->texture == NULL ||
            seed_arr->seed[i]->sprite == NULL)
            return (84);
        set_init_seed_value(seed_arr->seed[i]);
        sfSprite_setOrigin(seed_arr->seed[i]->sprite, origin);
    }
    return (0);
}

void set_seed(cannon_t *cannon, seed_t *seed)
{
    seed->p0.x = cannon->fire_pt.x;
    seed->p0.y = cannon->fire_pt.y;
    seed->pos.x = cannon->fire_pt.x;
    seed->pos.y = cannon->fire_pt.y;
    seed->vector.x = cannon->ammo_vector.x;
    seed->vector.y = cannon->ammo_vector.y;
    seed->speed = cannon->ammo_speed;
    seed->g = cannon->ammo_grav;
    sfSprite_rotate(seed->sprite, sfSprite_getRotation(cannon->sprite));
}

void reset_seed(seed_t *seed)
{
    seed->pos.x = -100;
    seed->pos.y = -100;
    seed->speed = 0;
    seed->vector.x = 0;
    seed->vector.y = 0;
    sfSprite_setRotation(seed->sprite, 0);
}