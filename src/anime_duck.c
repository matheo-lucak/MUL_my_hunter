/*
** EPITECH PROJECT, 2019
** init
** File description:
** init struct and sprites
*/

#include <stdio.h>
#include "my.h"
#include "duck_hunth.h"

void anime_duck(duck_t *duck)
{
    if (duck->frame == 0)
        duck->rect.left = 0;
    if (duck->frame == 3)
        duck->rect.left = 110;
    if (duck->frame == 6){
        duck->rect.left = 220;
        duck->frame = -3;
    }
    duck->frame++;
}

void disp_hungry_duck(win_t *win, duck_t *duck)
{
    sfSprite_setTexture(duck->sprite, duck->texture, sfTrue);
    sfSprite_setTextureRect(duck->sprite, duck->rect);
    sfSprite_setPosition(duck->sprite, duck->pos);
    if (duck->pos.x > win->video_mode.width && duck->scale.x == 1) {
        duck->scale.x = -1;
        duck->speed *= -1;
        sfSprite_setScale(duck->sprite, duck->scale);
    }
    if (duck->pos.x < 0 && duck->scale.x == -1) {
        duck->scale.x = 1;
        duck->speed *= -1;
        sfSprite_setScale(duck->sprite, duck->scale);
    }
    sfRenderWindow_drawSprite(win->window, duck->sprite, NULL);
    duck->pos.y += 2 + win->lvl / 2;
}

void disp_satiated_duck(win_t *win, duck_t *duck)
{
    sfSprite_setTexture(duck->sprite, duck->texture, sfTrue);
    sfSprite_setTextureRect(duck->sprite, duck->rect);
    sfSprite_rotate(duck->sprite, 10);
    sfSprite_setPosition(duck->sprite, duck->pos);
    sfRenderWindow_drawSprite(win->window, duck->sprite, NULL);
}

void disp_ducks(win_t *win, duck_arr_t *duck_arr)
{
    int i = -1;

    while (++i < duck_arr->duck_nb) {
        anime_duck(duck_arr->duck[i]);
        if (duck_arr->duck[i]->gestation_time < win->lvl / 4 + 1 &&
            duck_arr->duck_status[i] == 1)
            disp_hungry_duck(win, duck_arr->duck[i]);
        if (duck_arr->duck[i]->gestation_time >= win->lvl / 4 + 1 &&
            duck_arr->duck_status[i] == 2)
            disp_satiated_duck(win, duck_arr->duck[i]);
        duck_arr->duck[i]->pos.x += duck_arr->duck[i]->speed;
    }
}

int duck_throw(win_t *win, cursor_t *cursor, duck_arr_t *duck_arr)
{
    int i = -1;

    while (++i < duck_arr->duck_nb) {
        if (duck_arr->duck_status[i] == 0) {
            duck_arr->duck_status[i] = 1;
            set_duck(win, cursor, duck_arr->duck[i]);
            return (0);
        }
    }
    return (0);
}