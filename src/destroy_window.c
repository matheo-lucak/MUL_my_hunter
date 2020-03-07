/*
** EPITECH PROJECT, 2019
** init
** File description:
** init struct and sprites
*/

#include <stdio.h>
#include "my.h"
#include "duck_hunth.h"

void free_win(win_t *win)
{
    sfRenderWindow_destroy(win->window);
    free(win);
}

void free_music(music_arr_t *music_arr)
{
    sfMusic_destroy(music_arr->music[0]);
    free(music_arr->music);
    free(music_arr);
}

void free_bg(bg_t *bg, text_t *text)
{
    int i = -1;

    while (++i < 4)
        sfTexture_destroy(bg->texture[i]);
    sfSprite_destroy(bg->sprite);
    sfText_destroy(text->text);
    sfFont_destroy(text->font);
    free(bg->texture);
    free(bg);
}

void free_heart_bar(heart_bar_t *heart_bar)
{
    sfTexture_destroy(heart_bar->texture);
    sfSprite_destroy(heart_bar->sprite);
    free(heart_bar);
}

void free_win_obj(win_t *win, obj_t *obj)
{
    free_music(obj->music_arr);
    free_bg(obj->bg, obj->text);
    free_heart_bar(obj->heart_bar);
    free_cannon_ammo(obj->cannon, obj->ammo_bar);
    free_entity(obj->entity, obj->cursor);
    free_ammo(obj->ammo);
    free(obj);
    free(win);
}