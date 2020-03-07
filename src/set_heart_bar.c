/*
** EPITECH PROJECT, 2019
** init
** File description:
** init struct and sprites
*/

#include <stdio.h>
#include "my.h"
#include "duck_hunth.h"

int init_heart_bar(win_t *win, heart_bar_t *heart_bar)
{
    sfVector2f pos_heart;

    pos_heart.x = win->video_mode.width;
    pos_heart.y = win->video_mode.height;
    heart_bar->texture = sfTexture_createFromFile(
        "./sprite/heart_bar.png", &(heart_bar->rect));
    heart_bar->sprite = sfSprite_create();
    if (heart_bar->texture == NULL || heart_bar->sprite == NULL)
        return (84);
    heart_bar->rect.left = 0;
    heart_bar->rect.top = 0;
    heart_bar->rect.width = 171;
    heart_bar->rect.height = 50;
    sfSprite_setPosition(heart_bar->sprite, pos_heart);
    sfSprite_setTexture(heart_bar->sprite, heart_bar->texture,
        sfTrue);
    sfSprite_setRotation(heart_bar->sprite, 180);
    return (0);
}

void disp_heart_bar(win_t *win, heart_bar_t *heart_bar)
{
    heart_bar->rect.width = 57 * win->life;
    sfSprite_setTextureRect(heart_bar->sprite, heart_bar->rect);
    sfRenderWindow_drawSprite(win->window, heart_bar->sprite, NULL);
}