/*
** EPITECH PROJECT, 2019
** init
** File description:
** init struct and sprites
*/

#include <stdio.h>
#include "my.h"
#include "duck_hunth.h"

int init_cursor(cursor_t *cursor)
{
    cursor->rect.left = 0;
    cursor->rect.top = 0;
    cursor->rect.width = 49;
    cursor->rect.height = 47;
    cursor->origin.x = 0;
    cursor->origin.y = 23;
    cursor->pos.x = 0;
    cursor->pos.y = 23;
    cursor->mode = 1;
    cursor->color_mode = 1;
    cursor->is_switch_able = 0;
    cursor->is_fire_able = 19;
    cursor->texture = sfTexture_createFromFile("sprite/cursor.png", NULL);
    cursor->sprite = sfSprite_create();
    if (cursor->texture == NULL || cursor->sprite == NULL)
        return (84);
    sfSprite_setOrigin(cursor->sprite, cursor->origin);
    return (0);
}

void set_cursor(cursor_t *cursor)
{
    cursor->rect.left = 0;
    cursor->rect.top = 0;
    cursor->rect.width = 49;
    cursor->rect.height = 47;
    cursor->origin.x = 0;
    cursor->origin.y = 23;
    cursor->pos.x = 0;
    cursor->pos.y = 23;
    cursor->mode = 1;
    cursor->color_mode = 1;
    cursor->is_switch_able = 0;
}