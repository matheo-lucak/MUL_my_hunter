/*
** EPITECH PROJECT, 2019
** init
** File description:
** init struct and sprites
*/

#include <stdio.h>
#include "my.h"
#include "duck_hunth.h"

int init_bird_arr(bird_arr_t *bird_arr)
{
    int i = -1;

    bird_arr->bird_nb = 50;
    bird_arr->bird_status = malloc(sizeof(int) * bird_arr->bird_nb);
    bird_arr->bird = malloc(sizeof(bird_t *) * (bird_arr->bird_nb + 1));
    if (bird_arr->bird == NULL || bird_arr->bird_status == NULL)
        return (84);
    while (++i < bird_arr->bird_nb) {
        bird_arr->bird[i] = malloc(sizeof(bird_t));
        if (bird_arr->bird[i] == NULL)
            return (84);
        bird_arr->bird_status[i] = 0;
        if (init_bird(bird_arr->bird[i]) == 84)
            return (84);
    }
    return (0);
}

int init_bird(bird_t *bird)
{
    bird->rect.top = 0;
    bird->rect.left = 0;
    bird->rect.width = 70;
    bird->rect.height = 55;
    bird->scale.x = 1;
    bird->scale.y = 1;
    bird->frame = 0;
    bird->speed = 0;
    bird->pos.x = -110;
    bird->pos.y = -110;
    bird->gestation_time = 0;
    bird->texture = sfTexture_createFromFile("sprite/bird.png", NULL);
    bird->sprite = sfSprite_create();
    bird->eat_sound = sfSound_create();
    bird->eat_sound_buffer = sfSoundBuffer_createFromFile("sound/eat2.ogg");
    if (bird->texture == NULL || bird->sprite == NULL ||
        bird->eat_sound == NULL || bird->eat_sound_buffer == NULL)
        return (84);
    sfSound_setBuffer(bird->eat_sound, bird->eat_sound_buffer);
    return (0);
}

void set_bird(win_t *win, cursor_t *cursor, bird_t *bird)
{
    bird->pos.x = cursor->pos.x;
    bird->pos.y = cursor->pos.y - (bird->rect.height / 2);
    bird->speed = 15;
    bird->frame = 0;
    if (sfSprite_getRotation(cursor->sprite) == 180) {
        bird->scale.x = -1;
        bird->pos.x = cursor->origin.x + win->video_mode.width;
        bird->speed = -15;
        sfSprite_setScale(bird->sprite, bird->scale);
    }
}

void reset_bird(bird_t *bird)
{
    bird->rect.left = 0;
    bird->rect.top = 0;
    bird->rect.width = 70;
    bird->rect.height = 55;
    bird->scale.x = 1;
    bird->scale.y = 1;
    bird->frame = 0;
    bird->speed = 0;
    bird->pos.x = -110;
    bird->pos.y = -110;
    bird->gestation_time = 0;
    sfSprite_setRotation(bird->sprite, 0);
    sfSprite_setScale(bird->sprite, bird->scale);
}