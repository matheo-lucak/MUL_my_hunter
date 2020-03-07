/*
** EPITECH PROJECT, 2019
** csfml
** File description:
** csflm rtfm
*/

#include "my.h"
#include "duck_hunth.h"
#include "launcher.h"

int init_launcher_window(l_win_t *l_win , int width, int height)
{
    l_win->video_mode.width = width;
    l_win->video_mode.height = height;
    l_win->video_mode.bitsPerPixel = 32;
    l_win->play = 0;
    l_win->bot = 1;
    l_win->window = sfRenderWindow_create(l_win->video_mode,
        "DuckyDucky Feeder LAUNCHER", sfClose | sfDefaultStyle, NULL);
    if (l_win->window == NULL)
        return (84);
    sfRenderWindow_setFramerateLimit(l_win->window, 5);
    return (0);
}

int init_launcher_music(l_music_t *l_music)
{
    l_music->music_launch = sfMusic_createFromFile("./music/launcher.ogg");
    l_music->music = sfMusic_createFromFile("./music/tiger.ogg");
    if (l_music->music_launch == NULL || l_music->music == NULL)
        return (84);
    sfMusic_play(l_music->music_launch);
    sfMusic_setLoop(l_music->music, sfTrue);
    sfMusic_setVolume(l_music->music, 8);
    return (0);
}

int init_launcher_bg(l_bg_t *l_bg)
{
    l_bg->rect.left = 0;
    l_bg->rect.top = 0;
    l_bg->rect.width = 500;
    l_bg->rect.height = 430;
    l_bg->scale.x = 1;
    l_bg->scale.y = 1;
    l_bg->frame = 0;
    l_bg->menu_frame = 0;
    l_bg->t_menu = malloc(sizeof(sfTexture *) * 47);
    l_bg->sprite = sfSprite_create();
    l_bg->texture_loading = sfTexture_createFromFile("./sprite/dino.png", NULL);
    if (l_bg->texture_loading == NULL || l_bg->t_menu == NULL ||
        l_bg->sprite == NULL)
        return (84);
    sfSprite_setTexture(l_bg->sprite, l_bg->texture_loading, sfTrue);
    sfSprite_setTextureRect(l_bg->sprite, l_bg->rect);
    return (0);
}

void set_launcher_score(l_score_t *l_score)
{
    l_score->pos_hs.x = 200;
    l_score->pos_hs.y = 250;
    l_score->pos_s.x = 200;
    l_score->pos_s.y = 300;
    sfText_setCharacterSize(l_score->text_hs, 25);
    sfText_setCharacterSize(l_score->text_s, 25);
    sfText_setFont(l_score->text_hs, l_score->font);
    sfText_setFont(l_score->text_s, l_score->font);
    sfText_setPosition(l_score->text_hs, l_score->pos_hs);
    sfText_setPosition(l_score->text_s, l_score->pos_s);
    sfText_setString(l_score->text_hs, l_score->str_hs);
    sfText_setString(l_score->text_s, l_score->str_s);
}

int init_launcher_score(l_score_t *l_score)
{
    l_score->str_hs = malloc(sizeof(char) * 50);
    l_score->str_s = malloc(sizeof(char) * 50);
    l_score->font = sfFont_createFromFile("./font/metalia.ttf");
    l_score->text_hs = sfText_create();
    l_score->text_s = sfText_create();
    if (l_score->str_hs == NULL || l_score->str_s == NULL ||
        l_score->font == NULL || l_score->text_hs == NULL ||
        l_score->text_s == NULL)
        return (84);
    my_strcpy(l_score->str_hs, "HIGH SCORE: ");
    my_strcpy(l_score->str_s, "SCORE: ");
    my_strcat(l_score->str_hs, read_score("hscore"));
    my_strcat(l_score->str_s, read_score("score"));
    set_launcher_score(l_score);
    return (0);
}