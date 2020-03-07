/*
** EPITECH PROJECT, 2019
** init
** File description:
** init struct and sprites
*/

#include <stdio.h>
#include "my.h"
#include "duck_hunth.h"

void set_cannon_color(cannon_t *cannon, int x, int y)
{
    sfColor color = sfImage_getPixel(cannon->image, x, y);

    if (color.r != 255 || color.b != 255 || color.b != 255)
        return ;
    color.b = 0;
    if (y <= 21) {
        color.r = 255;
        color.g = y * 12;
    } else if ( y <= 42) {
        color.g = 255;
        color.r = 255 - (y * 12);
    } else
        color = sfGreen;
    sfImage_setPixel(cannon->image, x, y, color);
}

void get_cannon_color(cannon_t *cannon)
{
    int x = -1;
    float y = (42 / 6.5) * cannon->ammo_grav - (147 / 6.5);

    while (y < cannon->im_size.y) {
        while ((unsigned int)++x < cannon->im_size.x) {
            set_cannon_color(cannon, x, (int)y);
        }
        x = -1;
        y += 1;
    }
}