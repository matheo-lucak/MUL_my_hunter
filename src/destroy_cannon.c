/*
** EPITECH PROJECT, 2019
** init
** File description:
** init struct and sprites
*/

#include <stdio.h>
#include "my.h"
#include "duck_hunth.h"

void free_cannon(cannon_t *cannon)
{
    sfTexture_destroy(cannon->texture);
    sfSprite_destroy(cannon->sprite);
    sfSound_destroy(cannon->fire_sound);
    sfSoundBuffer_destroy(cannon->fire_sound_buffer);
    sfImage_destroy(cannon->image_0);
    sfImage_destroy(cannon->image);
}

void free_ammo_bar(ammo_bar_t *ammo_bar)
{
    sfTexture_destroy(ammo_bar->carrot_texture);
    sfTexture_destroy(ammo_bar->seed_texture);
    sfSprite_destroy(ammo_bar->carrot_sprite);
    sfSprite_destroy(ammo_bar->seed_sprite);
}

void free_cannon_ammo(cannon_t *cannon, ammo_bar_t *ammo_bar)
{
    free_cannon(cannon);
    free_ammo_bar(ammo_bar);
    free(cannon);
    free(ammo_bar);
}