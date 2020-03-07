/*
** EPITECH PROJECT, 2019
** init
** File description:
** init struct and sprites
*/

#include <stdio.h>
#include "my.h"
#include "duck_hunth.h"

void cannon_rotate(cannon_t *cannon)
{
    if (sfKeyboard_isKeyPressed(sfKeyLeft) &&
    (sfSprite_getRotation(cannon->sprite) > 271 ||
    sfSprite_getRotation(cannon->sprite) <= 91)) {
        sfSprite_rotate(cannon->sprite, (float)-10);
        set_cannon_angle(cannon);
    }
    if (sfKeyboard_isKeyPressed(sfKeyRight) &&
    (sfSprite_getRotation(cannon->sprite) < 90 ||
    sfSprite_getRotation(cannon->sprite) >= 269)) {
        sfSprite_rotate(cannon->sprite, (float)10);
        set_cannon_angle(cannon);
    }
}

void cannon_power(cannon_t *cannon)
{
    if (sfKeyboard_isKeyPressed(sfKeyUp) && cannon->ammo_grav > 3.5)
        cannon->ammo_grav -= 0.5;
    if (sfKeyboard_isKeyPressed(sfKeyDown) && cannon->ammo_grav < 10)
        cannon->ammo_grav += 0.5;
}

void disp_cannon(win_t *win, cannon_t *cannon)
{
    if (cannon->is_fire_able < 6)
        cannon->is_fire_able += 1;
    get_cannon_color(cannon);
    sfTexture_updateFromImage(cannon->texture, cannon->image, 0, 0);
    sfSprite_setTexture(cannon->sprite, cannon->texture, sfTrue);
    sfRenderWindow_drawSprite(win->window, cannon->sprite, NULL);
    sfImage_destroy(cannon->image);
    cannon->image = sfImage_copy(cannon->image_0);
}