/*
** EPITECH PROJECT, 2019
** init
** File description:
** init struct and sprites
*/

#include <stdio.h>
#include "my.h"
#include "duck_hunth.h"

void move_rand_cursor(win_t *win, cursor_t *cursor)
{
    if (win->bot == 1 && cursor->is_switch_able >= 50 - win->lvl * 10) {
        if (sfSprite_getRotation(cursor->sprite) == 0) {
            sfSprite_setRotation(cursor->sprite, 180);
            cursor->pos.x = win->video_mode.width;
        } else if (sfSprite_getRotation(cursor->sprite) == 180) {
            sfSprite_setRotation(cursor->sprite, 0);
            cursor->pos.x = 0;
        }
    cursor->is_switch_able = 0;
    }
}

void entity_rand_throw(win_t *win, cursor_t *cursor, entity_t *entity)
{
    if (win->bot == 1 && cursor->is_fire_able >= 50 - win->lvl * 10) {
        cursor->pos.y = rand() % 400;
        if (cursor->mode == 1)
            duck_throw(win, cursor, entity->duck_arr);
        if (cursor->mode == 2)
            bird_throw(win, cursor, entity->bird_arr);
        cursor->is_fire_able = 0;
    }
}