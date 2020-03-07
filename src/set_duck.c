/*
** EPITECH PROJECT, 2019
** init
** File description:
** init struct and sprites
*/

#include <stdio.h>
#include "my.h"
#include "duck_hunth.h"

int init_duck_arr(duck_arr_t *duck_arr)
{
    int i = -1;

    duck_arr->duck_nb = 50;
    duck_arr->duck_status = malloc(sizeof(int) * duck_arr->duck_nb);
    duck_arr->duck = malloc(sizeof(duck_t *) * (duck_arr->duck_nb + 1));
    if (duck_arr->duck == NULL || duck_arr->duck_status == NULL)
        return (84);
    while (++i < duck_arr->duck_nb) {
        duck_arr->duck[i] = malloc(sizeof(duck_t));
        if (duck_arr->duck[i] == NULL)
            return (84);
        duck_arr->duck_status[i] = 0;
        if (init_duck(duck_arr->duck[i]) == 84)
            return (84);
    }
    return (0);
}

int init_duck(duck_t *duck)
{
    duck->rect.left = 0;
    duck->rect.top = 0;
    duck->rect.width = 110;
    duck->rect.height = 110;
    duck->scale.x = 1;
    duck->scale.y = 1;
    duck->frame = 0;
    duck->speed = 0;
    duck->pos.x = -110;
    duck->pos.y = -110;
    duck->gestation_time = 0;
    duck->texture = sfTexture_createFromFile("sprite/duck.png", NULL);
    duck->sprite = sfSprite_create();
    duck->eat_sound = sfSound_create();
    duck->eat_sound_buffer = sfSoundBuffer_createFromFile("sound/eat1.ogg");
    if (duck->texture == NULL || duck->sprite == NULL ||
        duck->eat_sound == NULL || duck->eat_sound_buffer == NULL)
        return (84);
    sfSound_setBuffer(duck->eat_sound, duck->eat_sound_buffer);
    return (0);
}

void set_duck(win_t *win, cursor_t *cursor, duck_t *duck)
{
    duck->pos.x = cursor->pos.x;
    duck->pos.y = cursor->pos.y - (duck->rect.height / 2);
    duck->speed = 15;
    duck->frame = 0;
    if (sfSprite_getRotation(cursor->sprite) == 180) {
        duck->scale.x = -1;
        duck->pos.x = cursor->origin.x + win->video_mode.width;
        duck->speed = -15;
        sfSprite_setScale(duck->sprite, duck->scale);
    }
}

void reset_duck(duck_t *duck)
{
    duck->rect.left = 0;
    duck->rect.top = 0;
    duck->rect.width = 110;
    duck->rect.height = 110;
    duck->scale.x = 1;
    duck->scale.y = 1;
    duck->frame = 0;
    duck->speed = 0;
    duck->pos.x = -110;
    duck->pos.y = -110;
    duck->gestation_time = 0;
    sfSprite_setRotation(duck->sprite, 0);
    sfSprite_setScale(duck->sprite, duck->scale);
}