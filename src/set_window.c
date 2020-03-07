/*
** EPITECH PROJECT, 2019
** init
** File description:
** init struct and sprites
*/

#include <stdio.h>
#include "my.h"
#include "duck_hunth.h"

int init_window(win_t *win , int width, int height)
{
    win->video_mode.width = width;
    win->video_mode.height = height;
    win->video_mode.bitsPerPixel = 32;
    win->window = sfRenderWindow_create(win->video_mode,
        "DuckyDucky Feeder", sfClose | sfDefaultStyle, NULL);
    sfRenderWindow_setFramerateLimit(win->window, 30);
    win->life = 3;
    win->lvl = 1;
    win->score = 0;
    win->pause_texture = sfTexture_createFromFile("./sprite/pause.png", NULL);
    win->g_ovr_texture = sfTexture_createFromFile("./sprite/g_ovr.png", NULL);
    win->pause_sprite = sfSprite_create();
    win->restart = 1;
    if (win->window == NULL || win->pause_sprite == NULL ||
        win->pause_texture == NULL)
        return (84);
    return (0);
}