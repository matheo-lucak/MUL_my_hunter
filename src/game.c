/*
** EPITECH PROJECT, 2019
** csfml
** File description:
** csflm rtfm
*/

#include "my.h"
#include "duck_hunth.h"

void launch_game(void);

void disp_all(win_t *win, obj_t *obj)
{
        sfRenderWindow_clear(win->window, sfBlack);
        disp_bg(win, obj->bg);
        disp_heart_bar(win, obj->heart_bar);
        disp_ammo_bar(win, obj->ammo_bar, obj->ammo);
        disp_ducks(win, obj->entity->duck_arr);
        disp_birds(win, obj->entity->bird_arr);
        is_ammo_disp(win, obj->ammo);
        disp_cursor(win, obj->cursor);
        disp_cannon(win, obj->cannon);
        disp_text(win, obj->text);
        sfRenderWindow_display(win->window);
}

int start_game(int bot)
{
    win_t *win = malloc(sizeof(win_t));
    obj_t *obj = malloc(sizeof(obj_t));
    int restart = 1;

    win->bot = bot;
    if (set_obj(win, obj) == 84 || win == NULL || obj == NULL)
        return (84);
    while (sfRenderWindow_isOpen(win->window)) {
        is_event(win, obj);
        disp_all(win, obj);
    }
    restart = win->restart;
    free_win_obj(win, obj);
    return (restart);
}