/*
** EPITECH PROJECT, 2019
** init
** File description:
** init struct and sprites
*/

#include <stdio.h>
#include "my.h"
#include "duck_hunth.h"

void free_duck(duck_arr_t *duck_arr)
{
    int i = -1;

    while (++i < duck_arr->duck_nb) {
        sfTexture_destroy(duck_arr->duck[i]->texture);
        sfSprite_destroy(duck_arr->duck[i]->sprite);
        sfSoundBuffer_destroy(duck_arr->duck[i]->eat_sound_buffer);
        sfSound_destroy(duck_arr->duck[i]->eat_sound);
        free(duck_arr->duck[i]);
    }
    free(duck_arr->duck_status);
    free(duck_arr->duck);
}

void free_bird(bird_arr_t *bird_arr)
{
    int i = -1;

    while (++i < bird_arr->bird_nb) {
        sfTexture_destroy(bird_arr->bird[i]->texture);
        sfSprite_destroy(bird_arr->bird[i]->sprite);
        sfSoundBuffer_destroy(bird_arr->bird[i]->eat_sound_buffer);
        sfSound_destroy(bird_arr->bird[i]->eat_sound);
        free(bird_arr->bird[i]);
    }
    free(bird_arr->bird_status);
    free(bird_arr->bird);
}

void free_cursor(cursor_t *cursor)
{
    sfTexture_destroy(cursor->texture);
    sfSprite_destroy(cursor->sprite);
    free(cursor);
}

void free_entity(entity_t *entity, cursor_t *cursor)
{
    free_duck(entity->duck_arr);
    free_bird(entity->bird_arr);
    free_cursor(cursor);
    free(entity);
}