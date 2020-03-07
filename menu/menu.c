/*
** EPITECH PROJECT, 2019
** csfml
** File description:
** csflm rtfm
*/

#include "my.h"
#include "duck_hunth.h"
#include "launcher.h"

int init_launcher(l_win_t *l_win, l_obj_t *l_obj)
{
    if (init_launcher_window(l_win, 500, 750) == 84 ||
        init_launcher_bg(l_obj->l_bg) == 84 ||
        init_launcher_bg_menu(l_obj->l_bg) == 84 ||
        init_launcher_music(l_obj->l_music) == 84 ||
        init_launcher_button(l_obj->l_button) == 84 ||
        init_launcher_score(l_obj->l_score) == 84)
        return (84);
    return (0);
}

int set_launcher_obj(l_win_t *l_win, l_obj_t *l_obj)
{
    l_obj->l_music = malloc(sizeof(l_music_t));
    l_obj->l_bg = malloc(sizeof(l_bg_t));
    l_obj->l_button = malloc(sizeof(l_button_t));
    l_obj->l_score = malloc(sizeof(l_score_t));
    if (init_launcher(l_win, l_obj) == 84 || l_obj->l_bg == NULL ||
        l_obj->l_music == NULL || l_obj->l_button == NULL ||
        l_obj->l_score == NULL)
        return (84);
    return (0);
}

int launcher(int *play, int *bot)
{
    l_win_t *l_win = malloc(sizeof(l_win_t));
    l_obj_t *l_obj = malloc(sizeof(l_obj_t));

    if (set_launcher_obj(l_win, l_obj) == 84)
        return (84);
    while (sfRenderWindow_isOpen(l_win->window)) {
        while (sfRenderWindow_pollEvent(l_win->window, &(l_win->event))) {
            if (l_win->event.type == sfEvtClosed ||
                sfKeyboard_isKeyPressed(sfKeyEscape))
                sfRenderWindow_close(l_win->window);
        }
        is_launcher_event(l_win, l_obj->l_bg, l_obj->l_button);
        disp_launcher_all(l_win, l_obj);
    }
    *play = l_win->play;
    *bot = l_win->bot;
    free_launcher(l_win, l_obj);
    return (0);
}