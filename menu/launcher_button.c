/*
** EPITECH PROJECT, 2019
** csfml
** File description:
** csflm rtfm
*/

#include "my.h"
#include "launcher.h"
#include "duck_hunth.h"

int init_l_button_play1(l_button_p1_t *l_button_p1)
{
    l_button_p1->rect.left = 0;
    l_button_p1->rect.top = 0;
    l_button_p1->rect.width = 150;
    l_button_p1->rect.height = 67;
    l_button_p1->pos.x = 100;
    l_button_p1->pos.y = 600;
    l_button_p1->frame = 0;
    l_button_p1->texture = sfTexture_createFromFile
        ("./sprite/button1.png", NULL);
    l_button_p1->sprite = sfSprite_create();
    l_button_p1->sound_buffer = sfSoundBuffer_createFromFile
        ("./sound/click.ogg");
    l_button_p1->sound = sfSound_create();
    if (l_button_p1->sprite == NULL || l_button_p1->texture == NULL ||
        l_button_p1->sound_buffer == NULL || l_button_p1->sound == NULL)
            return (84);
    sfSound_setBuffer(l_button_p1->sound, l_button_p1->sound_buffer);
    sfSprite_setPosition(l_button_p1->sprite, l_button_p1->pos);
    return (0);
}

int init_l_button_play2(l_button_p2_t *l_button_p2)
{
    l_button_p2->rect.left = 0;
    l_button_p2->rect.top = 0;
    l_button_p2->rect.width = 150;
    l_button_p2->rect.height = 67;
    l_button_p2->pos.x = 250;
    l_button_p2->pos.y = 600;
    l_button_p2->frame = 0;
    l_button_p2->texture = sfTexture_createFromFile
        ("./sprite/button2.png", NULL);
    l_button_p2->sprite = sfSprite_create();
    l_button_p2->sound_buffer = sfSoundBuffer_createFromFile
        ("./sound/click.ogg");
    l_button_p2->sound = sfSound_create();
    if (l_button_p2->sprite == NULL || l_button_p2->texture == NULL ||
        l_button_p2->sound_buffer == NULL || l_button_p2->sound == NULL)
            return (84);
    sfSound_setBuffer(l_button_p2->sound, l_button_p2->sound_buffer);
    sfSprite_setPosition(l_button_p2->sprite, l_button_p2->pos);
    return (0);
}

int init_l_button_exit(l_button_exit_t *l_button_exit)
{
    l_button_exit->rect.left = 0;
    l_button_exit->rect.top = 0;
    l_button_exit->rect.width = 150;
    l_button_exit->rect.height = 67;
    l_button_exit->pos.x = 175;
    l_button_exit->pos.y = 670;
    l_button_exit->frame = 0;
    l_button_exit->texture = sfTexture_createFromFile
        ("./sprite/button3.png", NULL);
    l_button_exit->sprite = sfSprite_create();
    l_button_exit->sound_buffer = sfSoundBuffer_createFromFile
        ("./sound/click.ogg");
    l_button_exit->sound = sfSound_create();
    if (l_button_exit->sprite == NULL || l_button_exit->texture == NULL ||
        l_button_exit->sound_buffer == NULL || l_button_exit->sound == NULL)
            return (84);
    sfSound_setBuffer(l_button_exit->sound, l_button_exit->sound_buffer);
    sfSprite_setPosition(l_button_exit->sprite, l_button_exit->pos);
    return (0);
}

int init_launcher_button(l_button_t *l_button)
{
    l_button->l_button_p1 = malloc(sizeof(l_button_p1_t));
    l_button->l_button_p2 = malloc(sizeof(l_button_p2_t));
    l_button->l_button_exit = malloc(sizeof(l_button_exit_t));
    if (init_l_button_play1(l_button->l_button_p1) == 84 ||
        init_l_button_play2(l_button->l_button_p2) == 84 ||
        init_l_button_exit(l_button->l_button_exit) == 84 ||
        l_button->l_button_p1 == NULL ||
        l_button->l_button_p2 == NULL ||
        l_button->l_button_exit == NULL)
        return (84);
    return (0);
}

void disp_button(l_win_t *l_win, l_button_t *l_button)
{
    sfSprite_setTexture(l_button->l_button_p1->sprite,
        l_button->l_button_p1->texture, sfTrue);
    sfSprite_setTexture(l_button->l_button_p2->sprite,
        l_button->l_button_p2->texture, sfTrue);
    sfSprite_setTexture(l_button->l_button_exit->sprite,
        l_button->l_button_exit->texture, sfTrue);
    sfSprite_setTextureRect(l_button->l_button_p1->sprite,
        l_button->l_button_p1->rect);
    sfSprite_setTextureRect(l_button->l_button_p2->sprite,
        l_button->l_button_p2->rect);
    sfSprite_setTextureRect(l_button->l_button_exit->sprite,
        l_button->l_button_exit->rect);
    sfRenderWindow_drawSprite(l_win->window,
        l_button->l_button_p1->sprite, NULL);
    sfRenderWindow_drawSprite(l_win->window,
        l_button->l_button_p2->sprite, NULL);
    sfRenderWindow_drawSprite(l_win->window,
        l_button->l_button_exit->sprite, NULL);

}