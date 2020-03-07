/*
** EPITECH PROJECT, 2019
** csfml
** File description:
** csflm rtfm
*/

#include "my.h"
#include "duck_hunth.h"
#include "launcher.h"

void anime_launcher_bg(l_bg_t *l_bg)
{
    if (l_bg->frame >= 1 && l_bg->frame <= 8) {
        l_bg->rect.left = l_bg->frame * 500;
        l_bg->rect.top = 0;
    }
    if (l_bg->frame >= 8 && l_bg->frame <= 16) {
        l_bg->rect.left = (l_bg->frame - 8) * 500;
        l_bg->rect.top = 430;
    }
    if (l_bg->frame >= 16 && l_bg->frame <= 21) {
        l_bg->rect.left = (l_bg->frame - 16) * 500;
        l_bg->rect.top = 860;
    }
    l_bg->frame++;
}

void disp_score(l_win_t *l_win, l_score_t *l_score)
{
    sfRenderWindow_drawText(l_win->window   , l_score->text_hs, NULL);
    sfRenderWindow_drawText(l_win->window, l_score->text_s, NULL);
}

void disp_launcher_dino(l_win_t *l_win, l_obj_t *l_obj)
{
    anime_launcher_bg(l_obj->l_bg);
    sfSprite_setTexture(l_obj->l_bg->sprite,
        l_obj->l_bg->texture_loading, sfTrue);
    sfSprite_setTextureRect(l_obj->l_bg->sprite, l_obj->l_bg->rect);
    sfRenderWindow_drawSprite(l_win->window, l_obj->l_bg->sprite, NULL);
}

void disp_launcher_menu(l_win_t *l_win, l_obj_t *l_obj)
{
    if (l_obj->l_bg->frame == 22) {
        l_obj->l_bg->frame++;
        sfMusic_play (l_obj->l_music->music);
    }
    sfRenderWindow_setFramerateLimit(l_win->window, 10);
    sfSprite_setTexture(l_obj->l_bg->sprite,
        l_obj->l_bg->t_menu[l_obj->l_bg->menu_frame], 1);
    l_obj->l_bg->menu_frame++;
    sfRenderWindow_drawSprite(l_win->window, l_obj->l_bg->sprite, NULL);
    disp_score(l_win, l_obj->l_score);
    disp_button(l_win, l_obj->l_button);
    if (l_obj->l_bg->menu_frame == 47)
        l_obj->l_bg->menu_frame = 0;
}

void disp_launcher_all(l_win_t *l_win, l_obj_t *l_obj)
{
    sfRenderWindow_clear(l_win->window, sfBlack);
    if (l_obj->l_bg->frame <= 21)
        disp_launcher_dino(l_win, l_obj);
    else
        disp_launcher_menu(l_win, l_obj);
    sfRenderWindow_display(l_win->window);
}