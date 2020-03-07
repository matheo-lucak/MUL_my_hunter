/*
** EPITECH PROJECT, 2019
** csfml
** File description:
** csflm rtfm
*/

#include "my.h"
#include "duck_hunth.h"
#include "launcher.h"

static void free_launcher_bg(l_bg_t *l_bg)
{
    int i = -1;

    while (++i < 46)
        sfTexture_destroy(l_bg->t_menu[i]);
    sfTexture_destroy(l_bg->texture_loading);
    sfSprite_destroy(l_bg->sprite);
    free(l_bg);
}

static void free_launcher_button(l_button_t *l_button)
{
    sfTexture_destroy(l_button->l_button_p1->texture);
    sfTexture_destroy(l_button->l_button_p2->texture);
    sfTexture_destroy(l_button->l_button_exit->texture);
    sfSprite_destroy(l_button->l_button_p1->sprite);
    sfSprite_destroy(l_button->l_button_p2->sprite);
    sfSprite_destroy(l_button->l_button_exit->sprite);
    sfSound_destroy(l_button->l_button_p1->sound);
    sfSound_destroy(l_button->l_button_p2->sound);
    sfSound_destroy(l_button->l_button_exit->sound);
    sfSoundBuffer_destroy(l_button->l_button_p1->sound_buffer);
    sfSoundBuffer_destroy(l_button->l_button_p2->sound_buffer);
    sfSoundBuffer_destroy(l_button->l_button_exit->sound_buffer);
    free(l_button->l_button_p1);
    free(l_button->l_button_p2);
    free(l_button->l_button_exit);
    free(l_button);
}

static void free_launcher_music(l_music_t *l_music)
{
    sfMusic_destroy(l_music->music);
    sfMusic_destroy(l_music->music_launch);
    free(l_music);
}

static void free_launcher_score(l_score_t *l_score)
{
    sfText_destroy(l_score->text_hs);
    sfText_destroy(l_score->text_s);
    sfFont_destroy(l_score->font);
    free(l_score);
}

void free_launcher(l_win_t *l_win, l_obj_t *l_obj)
{
    sfRenderWindow_destroy(l_win->window);
    free_launcher_music(l_obj->l_music);
    free_launcher_button(l_obj->l_button);
    free_launcher_bg(l_obj->l_bg);
    free_launcher_score(l_obj->l_score);
    free(l_win);
    free(l_obj);
}