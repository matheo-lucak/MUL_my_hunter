/*
** EPITECH PROJECT, 2019
** init
** File description:
** init struct and sprites
*/

#include <stdio.h>
#include "my.h"
#include "duck_hunth.h"

void disp_cursor(win_t *win, cursor_t *cursor)
{
    cursor->color_mode = cursor->mode;
    if (cursor->is_switch_able < 50 - win->lvl * 10)
        cursor->is_switch_able++;
    if (cursor->is_fire_able < 50 - win->lvl * 10) {
        cursor->color_mode = 0;
        cursor->is_fire_able++;
    }
    cursor->rect.left = cursor->color_mode * 49;
    sfSprite_setTexture(cursor->sprite, cursor->texture, sfTrue);
    sfSprite_setTextureRect(cursor->sprite, cursor->rect);
    sfSprite_setPosition(cursor->sprite, cursor->pos);
    sfRenderWindow_drawSprite(win->window, cursor->sprite, NULL);
}

void cursor_change_mod(cursor_t *cursor)
{
    if (sfKeyboard_isKeyPressed(sfKeyD) && cursor->is_switch_able >= 5) {
        cursor->color_mode += 1;
        cursor->mode += 1;
        if (cursor->mode >= 3) {
            cursor->color_mode = 1;
            cursor->mode = 1;
        }
    cursor->is_switch_able = 0;
    }
}

void move_cursor(win_t *win, cursor_t *cursor)
{
    if (sfKeyboard_isKeyPressed(sfKeyA) && cursor->pos.y > 23)
        cursor->pos.y -= 10;
    if (sfKeyboard_isKeyPressed(sfKeyW) && cursor->pos.y < 300)
        cursor->pos.y += 10;
    if (sfKeyboard_isKeyPressed(sfKeyS) && cursor->is_switch_able >= 5) {
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

void entity_throw(win_t *win, cursor_t *cursor, entity_t *entity)
{
    if (sfKeyboard_isKeyPressed(sfKeyQ) && cursor->is_fire_able >= 20) {
        if (cursor->mode == 1)
            duck_throw(win, cursor, entity->duck_arr);
        if (cursor->mode == 2)
            bird_throw(win, cursor, entity->bird_arr);
        cursor->is_fire_able = 0;
    }
}

void cursor_event(win_t *win, cursor_t *cursor, entity_t *entity)
{
    if (win->bot == 1) {
        srand(win->time);
        cursor->mode = rand() % 2 + 1;
        move_rand_cursor(win, cursor);
        entity_rand_throw(win, cursor, entity);
    } else {
    entity_throw(win, cursor, entity);
    move_cursor(win, cursor);
    }
    cursor_change_mod(cursor);
}