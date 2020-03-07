/*
** EPITECH PROJECT, 2019
** init
** File description:
** init struct and sprites
*/

#include <stdio.h>
#include "my.h"
#include "duck_hunth.h"

void free_carrot(carrot_arr_t *carrot_arr)
{
    int i = -1;

    while (++i < 5) {
        sfTexture_destroy(carrot_arr->carrot[i]->texture);
        sfSprite_destroy(carrot_arr->carrot[i]->sprite);
        free(carrot_arr->carrot[i]);
    }
    free(carrot_arr->carrot_status);
    free(carrot_arr->carrot);
}

void free_seed(seed_arr_t *seed_arr)
{
    int i = -1;

    while (++i < 5) {
        sfTexture_destroy(seed_arr->seed[i]->texture);
        sfSprite_destroy(seed_arr->seed[i]->sprite);
        free(seed_arr->seed[i]);
    }
    free(seed_arr->seed_status);
    free(seed_arr->seed);
}

void free_ammo(ammo_t *ammo)
{
    free_carrot(ammo->carrot_arr);
    free_seed(ammo->seed_arr);
    free(ammo);
}