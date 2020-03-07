/*
** EPITECH PROJECT, 2019
** duck_hunth
** File description:
** header for duck hunt
*/

#include <math.h>
#include <SFML/Graphics.h>
#include <SFML/Window/Mouse.h>
#include <SFML/Window/Keyboard.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include <stdio.h>

#ifndef LAUNCHER_H_
#define LAUNCHER_H_

typedef struct l_win
{
    sfRenderWindow *window;
    sfVideoMode video_mode;
    sfEvent event;
    int play;
    int bot;
} l_win_t;

typedef struct l_music
{
    sfMusic *music_launch;
    sfMusic *music;
} l_music_t;

typedef struct l_bg
{
    sfSprite *sprite;
    sfTexture **t_menu;
    sfTexture *texture_loading;
    sfIntRect rect;
    sfVector2i scale;
    int frame;
    int menu_frame;
} l_bg_t;

typedef struct l_score
{
    sfFont *font;
    sfText *text_hs;
    sfText *text_s;
    sfVector2f pos_hs;
    sfVector2f pos_s;
    char *str_hs;
    char *str_s;
} l_score_t;

typedef struct l_button_p1
{
    sfSprite *sprite;
    sfTexture *texture;
    sfSoundBuffer *sound_buffer;
    sfSound *sound;
    sfVector2f pos;
    sfIntRect rect;
    int frame;
} l_button_p1_t;

typedef struct l_button_p2
{
    sfSprite *sprite;
    sfTexture *texture;
    sfSoundBuffer *sound_buffer;
    sfSound *sound;
    sfVector2f pos;
    sfIntRect rect;
    int frame;
} l_button_p2_t;

typedef struct l_button_exit
{
    sfSprite *sprite;
    sfTexture *texture;
    sfSoundBuffer *sound_buffer;
    sfSound *sound;
    sfVector2f pos;
    sfIntRect rect;
    int frame;
} l_button_exit_t;

typedef struct l_button
{
    l_button_p1_t *l_button_p1;
    l_button_p2_t *l_button_p2;
    l_button_exit_t *l_button_exit;
} l_button_t;

typedef struct l_obj
{
    l_button_t *l_button;
    l_score_t *l_score;
    l_bg_t *l_bg;
    l_music_t *l_music;

} l_obj_t;


int init_launcher_window(l_win_t *l_win , int width, int height);
int init_launcher_bg(l_bg_t *l_bg);
int init_launcher_bg_menu(l_bg_t *l_bg);
int init_launcher_music(l_music_t *l_music);
int init_launcher_button(l_button_t *l_button);
int init_launcher_score(l_score_t *l_score);
void disp_button(l_win_t *l_win, l_button_t *l_button);
void disp_launcher_all(l_win_t *l_win, l_obj_t *l_obj);
void free_launcher(l_win_t *l_win, l_obj_t *l_obj_t);
void is_launcher_event(l_win_t *l_win, l_bg_t *l_bg, l_button_t *l_button);
int launch_game(void);

#endif /* !LAUNCHER_H_ */
