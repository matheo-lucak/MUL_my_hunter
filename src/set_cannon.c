/*
** EPITECH PROJECT, 2019
** init
** File description:
** init struct and sprites
*/

#include <stdio.h>
#include "my.h"
#include "duck_hunth.h"

void set_init_cannon_value(win_t *win , cannon_t *cannon)
{
    cannon->origin.x = 21;
    cannon->origin.y = 62;
    cannon->pos.x = win->video_mode.width / 2;
    cannon->pos.y = win->video_mode.height;
    cannon->ammo_vector.x = sin(0.001 * M_PI / 180) * cannon->origin.y;
    cannon->ammo_vector.y = -cos(0.001 * M_PI / 180) * cannon->origin.y;
    cannon->fire_pt.x = cannon->pos.x;
    cannon->fire_pt.y = cannon->pos.y - cannon->origin.y;
    cannon->is_fire_able = 0;
    cannon->ammo_speed = 0.5;
    cannon->ammo_grav = 6.5;
    cannon->angle = 0;
    cannon->image = sfTexture_copyToImage(cannon->texture);
    cannon->image_0 = sfTexture_copyToImage(cannon->texture);
    cannon->im_size = sfImage_getSize(cannon->image);
}

int init_cannon(win_t *win , cannon_t *cannon)
{
    cannon->texture = sfTexture_createFromFile("./sprite/cannon.png", NULL);
    cannon->sprite = sfSprite_create();
    cannon->fire_sound_buffer = sfSoundBuffer_createFromFile
        ("./sound/plop.ogg");
    cannon->fire_sound = sfSound_create();
    if (cannon->texture == NULL || cannon->sprite == NULL ||
        cannon->fire_sound == NULL || cannon->fire_sound_buffer == NULL)
        return (84);
    set_init_cannon_value(win, cannon);
    sfSound_setBuffer(cannon->fire_sound, cannon->fire_sound_buffer);
    sfSprite_setOrigin(cannon->sprite, cannon->origin);
    sfSprite_setPosition(cannon->sprite, cannon->pos);
    sfSprite_setRotation(cannon->sprite, 0.001);
    return (0);
}

void set_cannon_angle(cannon_t *cannon)
{
    cannon->angle = sfSprite_getRotation(cannon->sprite) * M_PI / 180;
    cannon->ammo_vector.x = sin(cannon->angle) * cannon->origin.y;
    cannon->ammo_vector.y = -cos(cannon->angle) * cannon->origin.y;
    cannon->fire_pt.x = cannon->pos.x + cannon->ammo_vector.x;
    cannon->fire_pt.y = cannon->pos.y + cannon->ammo_vector.y;
}