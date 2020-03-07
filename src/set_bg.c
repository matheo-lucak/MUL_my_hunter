/*
** EPITECH PROJECT, 2019
** init
** File description:
** init struct and sprites
*/

#include <stdio.h>
#include "my.h"
#include "duck_hunth.h"

int init_bg(bg_t *bg)
{
    bg->texture = malloc(sizeof(sfTexture *) * 4);
    if (bg->texture == NULL)
        return (84);
    bg->texture[0] = sfTexture_createFromFile("sprite/bg00.png", NULL);
    bg->texture[1] = sfTexture_createFromFile("sprite/bg01.png", NULL);
    bg->texture[2] = sfTexture_createFromFile("sprite/bg02.png", NULL);
    bg->texture[3] = sfTexture_createFromFile("sprite/bg03.png", NULL);
    bg->sprite = sfSprite_create();
    if (bg->texture[0] == NULL || bg->texture[1] == NULL ||
        bg->texture[2] == NULL || bg->texture[3] == NULL ||
        bg->sprite == NULL)
        return (84);
    return (0);
}

void disp_bg(win_t *win, bg_t *bg)
{
    sfSprite_setTexture(bg->sprite, bg->texture[bg->bg_index], sfTrue);
    sfRenderWindow_drawSprite(win->window, bg->sprite, NULL);
}