/*
** EPITECH PROJECT, 2019
** init
** File description:
** init struct and sprites
*/

#include <stdio.h>
#include "my.h"
#include "duck_hunth.h"

void anime_bird(bird_t *bird)
{
    if (bird->frame == 0)
        bird->rect.left = 0;
    if (bird->frame == 3)
        bird->rect.left = 70;
    if (bird->frame == 6)
        bird->rect.left = 140;
    if (bird->frame == 9){
        bird->rect.left = 210;
        bird->frame = -3;
    }
    bird->frame++;
}

void disp_hungry_bird(win_t *win, bird_t *bird)
{
    sfSprite_setTexture(bird->sprite, bird->texture, sfTrue);
    sfSprite_setTextureRect(bird->sprite, bird->rect);
    sfSprite_setPosition(bird->sprite, bird->pos);
    if (bird->pos.x > win->video_mode.width && bird->scale.x == 1) {
        bird->scale.x = -1;
        bird->speed *= -1;
        sfSprite_setScale(bird->sprite, bird->scale);
    }
    if (bird->pos.x < 0 && bird->scale.x == -1) {
        bird->scale.x = 1;
        bird->speed *= -1;
        sfSprite_setScale(bird->sprite, bird->scale);
    }
    sfRenderWindow_drawSprite(win->window, bird->sprite, NULL);
    bird->pos.y += 2 + win->lvl / 2;
}

void disp_satiated_bird(win_t *win, bird_t *bird)
{
    sfSprite_setTexture(bird->sprite, bird->texture, sfTrue);
    sfSprite_setTextureRect(bird->sprite, bird->rect);
    sfSprite_rotate(bird->sprite, 10);
    sfSprite_setPosition(bird->sprite, bird->pos);
    sfRenderWindow_drawSprite(win->window, bird->sprite, NULL);
}

void disp_birds(win_t *win, bird_arr_t *bird_arr)
{
    int i = -1;

    while (++i < bird_arr->bird_nb) {
        anime_bird(bird_arr->bird[i]);
        if (bird_arr->bird[i]->gestation_time < 1 &&
            bird_arr->bird_status[i] == 1)
            disp_hungry_bird(win, bird_arr->bird[i]);
        if (bird_arr->bird[i]->gestation_time >= 1 &&
            bird_arr->bird_status[i] == 2)
            disp_satiated_bird(win, bird_arr->bird[i]);
        bird_arr->bird[i]->pos.x += bird_arr->bird[i]->speed;
    }
}

int bird_throw(win_t *win, cursor_t *cursor, bird_arr_t *bird_arr)
{
    int i = -1;

    while (++i < bird_arr->bird_nb) {
        if (bird_arr->bird_status[i] == 0) {
            bird_arr->bird_status[i] = 1;
            set_bird(win, cursor, bird_arr->bird[i]);
            return (0);
        }
    }
    return (0);
}