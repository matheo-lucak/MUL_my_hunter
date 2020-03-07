/*
** EPITECH PROJECT, 2019
** csfml
** File description:
** csflm rtfm
*/

#include "my.h"
#include "duck_hunth.h"

int init_obj(win_t *win, obj_t *obj)
{
    if (init_window(win, 800, 600) == 84 ||
        init_bg(obj->bg) == 84 ||
        init_music_arr(obj->music_arr) == 84 ||
        init_heart_bar(win, obj->heart_bar) == 84 ||
        init_cannon(win, obj->cannon) == 84 ||
        init_ammo_bar(win, obj->ammo_bar) == 84 ||
        init_cursor(obj->cursor) == 84 ||
        init_duck_arr(obj->entity->duck_arr) == 84 ||
        init_bird_arr(obj->entity->bird_arr) == 84 ||
        init_carrot_arr(obj->ammo->carrot_arr) == 84 ||
        init_seed_arr(obj->ammo->seed_arr) == 84 ||
        init_text(win, obj->text) == 84)
        return (84);
    return (0);
}

int check_malloc(obj_t *obj)
{
    if (obj->music_arr == NULL || obj->bg == NULL || obj->heart_bar == NULL ||
        obj->cannon == NULL || obj->ammo_bar == NULL ||
        obj->cursor == NULL || obj->entity == NULL || obj->ammo == NULL ||
        obj->text == NULL || obj->entity == NULL || obj->entity == NULL ||
        obj->ammo == NULL)
        return (84);
    return (0);
}

int set_obj(win_t *win , obj_t *obj)
{
    obj->music_arr = malloc(sizeof(music_arr_t));
    obj->bg = malloc(sizeof(bg_t));
    obj->heart_bar = malloc(sizeof(heart_bar_t));
    obj->cannon = malloc(sizeof(cannon_t));
    obj->ammo_bar = malloc(sizeof(ammo_bar_t));
    obj->cursor = malloc(sizeof(cursor_t));
    obj->entity = malloc(sizeof(entity_t));
    obj->ammo = malloc(sizeof(ammo_t));
    obj->text = malloc(sizeof(text_t));
    obj->entity->duck_arr = malloc(sizeof(duck_arr_t));
    obj->entity->bird_arr = malloc(sizeof(bird_arr_t));
    obj->ammo->carrot_arr = malloc(sizeof(carrot_arr_t));
    obj->ammo->seed_arr = malloc(sizeof(seed_arr_t));
    if (check_malloc(obj) == 84)
        return (84);
    init_obj(win, obj);
    return (0);
}