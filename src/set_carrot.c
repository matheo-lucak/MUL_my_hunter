/*
** EPITECH PROJECT, 2019
** init
** File description:
** init struct and sprites
*/

#include <stdio.h>
#include "my.h"
#include "duck_hunth.h"

void set_init_carrot_value(carrot_t *carrot)
{
    carrot->pos.x = -100;
    carrot->pos.y = -100;
    carrot->vector.x = 0;
    carrot->vector.y = 0;
    carrot->size.x = 50;
    carrot->size.y = 30;
}

int init_carrot(carrot_arr_t *carrot_arr)
{
    int i = -1;
    sfVector2f origin;

    origin.x = 25;
    origin.y = 15;
    while (++i < 5) {
        carrot_arr->carrot[i] = malloc(sizeof(carrot_t));
        carrot_arr->carrot[i]->texture = sfTexture_createFromFile
            ("./sprite/carrot.png", NULL);
        carrot_arr->carrot[i]->sprite = sfSprite_create();
        if (carrot_arr->carrot[i] == NULL ||
            carrot_arr->carrot[i]->texture == NULL ||
            carrot_arr->carrot[i]->sprite == NULL)
            return (84);
        set_init_carrot_value(carrot_arr->carrot[i]);
        sfSprite_setOrigin(carrot_arr->carrot[i]->sprite, origin);
    }
    return (0);
}

void set_carrot(cannon_t *cannon, carrot_t *carrot)
{
    carrot->p0.x = cannon->fire_pt.x;
    carrot->p0.y = cannon->fire_pt.y;
    carrot->pos.x = cannon->fire_pt.x;
    carrot->pos.y = cannon->fire_pt.y;
    carrot->vector.x = cannon->ammo_vector.x;
    carrot->vector.y = cannon->ammo_vector.y;
    carrot->speed = cannon->ammo_speed;
    carrot->g = cannon->ammo_grav;
    sfSprite_rotate(carrot->sprite, sfSprite_getRotation(cannon->sprite)
        + 135);
}

void reset_carrot(carrot_t *carrot)
{
    carrot->pos.x = -100;
    carrot->pos.y = -100;
    carrot->speed = 0;
    carrot->vector.x = 0;
    carrot->vector.y = 0;
    sfSprite_setRotation(carrot->sprite, 0);
}