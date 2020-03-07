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
#include <unistd.h>

#ifndef DUCK_HUNTH_H
#define DUCK_HUNTH_H

typedef struct win
{
    sfRenderWindow *window;
    sfVideoMode video_mode;
    sfSprite *pause_sprite;
    sfTexture *pause_texture;
    sfTexture *g_ovr_texture;
    sfEvent event;
    int lvl;
    int life;
    int score;
    long time;
    int bot;
    int restart;
} win_t;

typedef struct text
{
    sfText *text;
    sfFont *font;
    sfVector2f pos;
} text_t;

typedef struct music_arr
{
    sfMusic **music;
    int music_nb;
} music_arr_t;

typedef struct bg
{
    sfTexture **texture;
    sfSprite *sprite;
    int bg_index;
} bg_t;

typedef struct cannon
{
    sfTexture *texture;
    sfSprite *sprite;
    sfSound *fire_sound;
    sfSoundBuffer *fire_sound_buffer;
    sfImage *image;
    sfImage *image_0;
    sfVector2u im_size;
    sfVector2f pos;
    sfIntRect rect;
    sfVector2f fire_pt;
    sfVector2f ammo_vector;
    sfVector2f origin;
    float ammo_grav;
    float ammo_speed;
    int is_fire_able;
    float angle;
} cannon_t;

typedef struct ammo_bar
{
    sfTexture *carrot_texture;
    sfSprite *carrot_sprite;
    sfVector2f carrot_pos;
    sfIntRect carrot_rect;
    sfTexture *seed_texture;
    sfSprite *seed_sprite;
    sfVector2f seed_pos;
    sfIntRect seed_rect;
}   ammo_bar_t;

typedef struct heart_bar
{
    sfTexture *texture;
    sfSprite *sprite;
    sfIntRect rect;
} heart_bar_t;

typedef struct cursor
{
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f pos;
    sfVector2f origin;
    sfIntRect rect;
    int mode;
    int color_mode;
    int is_fire_able;
    int is_switch_able;
} cursor_t;

typedef struct duck
{
    sfTexture *texture;
    sfSprite *sprite;
    sfSoundBuffer *eat_sound_buffer;
    sfSound *eat_sound;
    sfVector2f scale;
    sfVector2f pos;
    sfIntRect rect;
    int gestation_time;
    int frame;
    int speed;
} duck_t;

typedef struct duck_arr
{
    duck_t **duck;
    int *duck_status;
    int duck_nb;
} duck_arr_t;

typedef struct bird
{
    sfTexture *texture;
    sfSprite *sprite;
    sfSoundBuffer *eat_sound_buffer;
    sfSound *eat_sound;
    sfVector2f scale;
    sfVector2f pos;
    sfIntRect rect;
    int gestation_time;
    int frame;
    int speed;
} bird_t;

typedef struct bird_arr
{
    bird_t **bird;
    int *bird_status;
    int bird_nb;
} bird_arr_t;

typedef struct carrot
{
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f pos;
    sfVector2f p0;
    sfVector2f vector;
    sfVector2f size;
    float g;
    float speed;
} carrot_t;

typedef struct carrot_arr
{
    carrot_t **carrot;
    int *carrot_status;
} carrot_arr_t;

typedef struct seed
{
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f pos;
    sfVector2f p0;
    sfVector2f vector;
    sfVector2f size;
    float g;
    float speed;
} seed_t;

typedef struct seed_arr
{
    seed_t **seed;
    int *seed_status;
} seed_arr_t;

typedef struct ammo
{
    carrot_arr_t *carrot_arr;
    seed_arr_t *seed_arr;
} ammo_t;

typedef struct entity
{
    duck_arr_t *duck_arr;
    bird_arr_t *bird_arr;
} entity_t;

typedef struct obj
{
    music_arr_t *music_arr;
    bg_t *bg;
    cannon_t *cannon;
    heart_bar_t *heart_bar;
    ammo_bar_t *ammo_bar;
    cursor_t *cursor;
    entity_t *entity;
    ammo_t *ammo;
    text_t *text;
} obj_t;

int init_window(win_t *win , int width, int height);

int init_bg(bg_t *bg);
void disp_bg(win_t *win, bg_t *bg);

int init_music_arr(music_arr_t *music_arr);

int init_text(win_t *win, text_t *text);
void disp_text(win_t *win, text_t *text);

int init_cannon(win_t *win , cannon_t *cannon);
void set_cannon_angle(cannon_t *cannon);
void cannon_rotate(cannon_t *cannon);
void cannon_power(cannon_t *cannon);
void get_cannon_color(cannon_t *cannon);
void disp_cannon(win_t *win, cannon_t *cannon);
void fire_ammo(cannon_t *cannon, ammo_t *ammo);

int init_heart_bar(win_t *win, heart_bar_t *heart_bar);
void disp_heart_bar(win_t *win, heart_bar_t *heart_bar);

void is_ammo_disp(win_t *win, ammo_t *ammo);
int init_ammo_bar(win_t *win, ammo_bar_t *ammo_bar);
void disp_ammo_bar(win_t *win, ammo_bar_t *ammo_bar, ammo_t *ammo);

int init_cursor(cursor_t *cursor);
void set_cursor(cursor_t *cursor);
void disp_cursor(win_t *win, cursor_t *cursor);
void move_cursor(win_t *win, cursor_t *cursor);
void cursor_change_mod(cursor_t *cursor);
void cursor_event(win_t *win, cursor_t *cursor, entity_t *entity);

void move_rand_cursor(win_t *win, cursor_t *cursor);
void entity_rand_throw(win_t *win, cursor_t *cursor, entity_t *entity);

int init_duck_arr(duck_arr_t *duck_arr);
int init_duck(duck_t *duck);
void anime_duck(duck_t *duck);
void disp_ducks(win_t *win, duck_arr_t *duck_arr);
void reset_duck(duck_t *duck);
void set_duck(win_t *win, cursor_t *cursor, duck_t *duck);
int duck_throw(win_t *win, cursor_t *cursor, duck_arr_t *duck_arr);

int init_bird_arr(bird_arr_t *bird_arr);
int init_bird(bird_t *bird);
void anime_bird(bird_t *bird);
void disp_birds(win_t *win, bird_arr_t *bird_arr);
void reset_bird(bird_t *bird);
void set_bird(win_t *win, cursor_t *cursor, bird_t *bird);
int bird_throw(win_t *win, cursor_t *cursor, bird_arr_t *bird_arr);

int init_carrot_arr(carrot_arr_t *carrot_arr);
int init_carrot(carrot_arr_t *carrot_arr);
void reset_carrot_arr(win_t *win, carrot_arr_t *carrot_arr);
void set_carrot(cannon_t *cannon, carrot_t *carrot);
void reset_carrot(carrot_t *carrot);
void disp_carrot(win_t *win, carrot_t *carrot);
int carrot_throw(cannon_t *cannon, carrot_arr_t *carrot_arr);

int init_seed_arr(seed_arr_t *seed_arr);
int init_seed(seed_arr_t *seed_arr);
void reset_seed_arr(win_t *win, seed_arr_t *seed_arr);
void set_seed(cannon_t *cannon, seed_t *seed);
void reset_seed(seed_t *seed);
void disp_seed(win_t *win, seed_t *seed);
int seed_throw(cannon_t *cannon, seed_arr_t *seed_arr);

int set_obj(win_t *win , obj_t *obj);
void is_collid_able(entity_t *entity, ammo_t *ammo);
void is_fed(win_t *win, entity_t *entity);
void is_fed_entity_outside(win_t *win, entity_t *entity);
void is_entity_outside(win_t *win, entity_t *entity);
void is_event(win_t *win, obj_t *obj);

void check_lvl(win_t *win, obj_t *obj);

void free_cannon_ammo(cannon_t *cannon, ammo_bar_t *ammo_bar);
void free_entity(entity_t *entity, cursor_t *cursor);
void free_ammo(ammo_t *ammo);
void free_win_obj(win_t *win, obj_t *obj);

void set_score(int score_value, char *filepath);
char *read_score(char const *filepath);

int start_game(int bot);

#endif /* !DUCK_HUNTH_H */
