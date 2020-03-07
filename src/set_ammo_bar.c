/*
** EPITECH PROJECT, 2019
** init
** File description:
** init struct and sprites
*/

#include <stdio.h>
#include "my.h"
#include "duck_hunth.h"

int init_seed_bar(win_t *win, ammo_bar_t *ammo_bar)
{
    sfVector2f pos_seed;

    pos_seed.x = 0;
    pos_seed.y = win->video_mode.height - 84;
    ammo_bar->seed_texture = sfTexture_createFromFile(
        "./sprite/seed_bar.png", NULL);
    ammo_bar->seed_sprite = sfSprite_create();
    if (ammo_bar->seed_texture == NULL || ammo_bar->seed_sprite == NULL)
        return (84);
    ammo_bar->seed_rect.left = 0;
    ammo_bar->seed_rect.top = 0;
    ammo_bar->seed_rect.width = 250;
    ammo_bar->seed_rect.height = 41;
    sfSprite_setPosition(ammo_bar->seed_sprite, pos_seed);
    sfSprite_setTexture(ammo_bar->seed_sprite, ammo_bar->seed_texture,
        sfTrue);
    return (0);
}

int init_carrot_bar(win_t *win, ammo_bar_t *ammo_bar)
{
    sfVector2f pos_carrot;
    pos_carrot.x = 0;
    pos_carrot.y = win->video_mode.height - 43;
    ammo_bar->carrot_texture = sfTexture_createFromFile(
        "./sprite/carrot_bar.png", NULL);
    ammo_bar->carrot_sprite = sfSprite_create();
    if (ammo_bar->carrot_texture == NULL || ammo_bar->carrot_sprite == NULL)
        return (84);
    ammo_bar->carrot_rect.left = 0;
    ammo_bar->carrot_rect.top = 0;
    ammo_bar->carrot_rect.width = 250;
    ammo_bar->carrot_rect.height = 43;
    sfSprite_setPosition(ammo_bar->carrot_sprite, pos_carrot);
    sfSprite_setTexture(ammo_bar->carrot_sprite, ammo_bar->carrot_texture,
        sfTrue);
    return (0);
}

int init_ammo_bar(win_t *win, ammo_bar_t *ammo_bar)
{
    if (init_carrot_bar(win, ammo_bar) == 84 ||
        init_seed_bar(win, ammo_bar))
        return (84);
    return (0);
}

void disp_ammo_bar(win_t *win, ammo_bar_t *ammo_bar, ammo_t *ammo)
{
    int carrot_nb = 0;
    int seed_nb = 0;
    int i = -1;

    while (++i < 5) {
        if (ammo->carrot_arr->carrot_status[i] == 1)
            carrot_nb += ammo->carrot_arr->carrot_status[i];
        if (ammo->seed_arr->seed_status[i] == 1)
            seed_nb += ammo->seed_arr->seed_status[i];
    }
    ammo_bar->carrot_rect.width = 50 * carrot_nb;
    ammo_bar->seed_rect.width = 50 * seed_nb;
    sfSprite_setTextureRect(ammo_bar->carrot_sprite, ammo_bar->carrot_rect);
    sfSprite_setTextureRect(ammo_bar->seed_sprite, ammo_bar->seed_rect);
    sfRenderWindow_drawSprite(win->window, ammo_bar->carrot_sprite, NULL);
    sfRenderWindow_drawSprite(win->window, ammo_bar->seed_sprite, NULL);
}