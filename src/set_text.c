/*
** EPITECH PROJECT, 2019
** init
** File description:
** init struct and sprites
*/

#include <stdio.h>
#include "my.h"
#include "duck_hunth.h"

int init_text(win_t *win, text_t *text)
{
    text->font = sfFont_createFromFile("./font/metalia.ttf");
    text->text = sfText_create();
    if (text->font == NULL || text->text == NULL)
        return (84);
    text->pos.x = win->video_mode.width - 100;
    text->pos.y = 0;
    sfText_setPosition(text->text, text->pos);
    sfText_setCharacterSize(text->text, 25);
    sfText_setFont(text->text, text->font);
    return (0);
}

void disp_text(win_t *win, text_t *text)
{
    char *str = malloc(sizeof(char) * 50);
    if (str == NULL)
        return ;
    my_strcpy(str, "score: ");
    str[7] = '\0';
    my_strcat(str, my_int_to_str(win->score));
    sfText_setString(text->text, str);
    sfRenderWindow_drawText(win->window, text->text, NULL);
    free(str);
}