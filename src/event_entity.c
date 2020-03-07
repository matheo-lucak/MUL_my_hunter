/*
** EPITECH PROJECT, 2019
** init
** File description:
** init struct and sprites
*/

#include "my.h"
#include "duck_hunth.h"

void is_fed(win_t *win, entity_t *entity)
{
    int i = -1;

    while (++i < entity->duck_arr->duck_nb) {
        if (entity->duck_arr->duck_status[i] == 1 &&
            entity->duck_arr->duck[i]->gestation_time >= win->lvl / 4 + 1) {
            entity->duck_arr->duck_status[i] = 2;
            win->score += 10 + (win->video_mode.height -
                entity->duck_arr->duck[i]->pos.y) / 150;
            }
    }
    i = -1;
    while (++i < entity->duck_arr->duck_nb) {
        if (entity->bird_arr->bird_status[i] == 1 &&
            entity->bird_arr->bird[i]->gestation_time >= 1) {
            entity->bird_arr->bird_status[i] = 2;
            win->score += 15 + (win->video_mode.height -
                entity->bird_arr->bird[i]->pos.y) / 150;
            }
    }
}

void is_fed_duck_outside(win_t *win, duck_arr_t *duck_arr)
{
    int i = -1;

    while (++i < duck_arr->duck_nb) {
        if ((duck_arr->duck[i]->pos.y > win->video_mode.height ||
            duck_arr->duck[i]->pos.x > win->video_mode.width ||
            duck_arr->duck[i]->pos.x < 0) &&
            duck_arr->duck_status[i] == 2) {
            duck_arr->duck_status[i] = 0;
            reset_duck(duck_arr->duck[i]);
        }
    }
}

void is_fed_bird_outside(win_t *win, bird_arr_t *bird_arr)
{
    int i = -1;

    while (++i < bird_arr->bird_nb) {
        if ((bird_arr->bird[i]->pos.y > win->video_mode.height ||
            bird_arr->bird[i]->pos.x > win->video_mode.width ||
            bird_arr->bird[i]->pos.x < 0) &&
            bird_arr->bird_status[i] == 2) {
            bird_arr->bird_status[i] = 0;
            reset_bird(bird_arr->bird[i]);
        }
    }
}

void is_fed_entity_outside(win_t *win, entity_t *entity)
{
    is_fed_duck_outside(win, entity->duck_arr);
    is_fed_bird_outside(win, entity->bird_arr);
}

void is_entity_outside(win_t *win, entity_t *entity)
{
    int i = -1;

    while (++i < entity->duck_arr->duck_nb) {
        if (entity->duck_arr->duck[i]->pos.y > win->video_mode.height &&
            entity->duck_arr->duck_status[i] == 1) {
            entity->duck_arr->duck_status[i] = 0;
            reset_duck(entity->duck_arr->duck[i]);
            win->life += -1;
        }
    }
    i = -1;
    while (++i < entity->bird_arr->bird_nb) {
        if (entity->bird_arr->bird[i]->pos.y > win->video_mode.height &&
            entity->bird_arr->bird_status[i] != 0) {
            entity->bird_arr->bird_status[i] = 0;
            reset_bird(entity->bird_arr->bird[i]);
            win->life += -1;
        }
    }
}
