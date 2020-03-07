/*
** EPITECH PROJECT, 2019
** csfml
** File description:
** csflm rtfm
*/

#include "my.h"
#include "duck_hunth.h"
#include "launcher.h"

void is_button_pressed1(l_win_t *l_win, l_bg_t *l_bg,
    l_button_p1_t *l_button_p1)
{
    sfMouseButtonEvent mouse;

    sfRenderWindow_pollEvent(l_win->window, &(l_win->event));
    if (l_win->event.mouseButton.button == sfMouseLeft)
        mouse = l_win->event.mouseButton;
    if (mouse.x >= l_button_p1->pos.x && mouse.x <= l_button_p1->pos.x + 150 &&
        mouse.y >= l_button_p1->pos.y && mouse.y <= l_button_p1->pos.y + 67 &&
        sfMouse_isButtonPressed(sfMouseLeft) && l_button_p1->rect.left != 150
        && l_bg->frame == 23) {
        sfSound_play(l_button_p1->sound);
        l_button_p1->rect.left = 150;
        l_win->play = 1;
        l_win->bot = 1;
        }
    if (l_button_p1->rect.left == 150)
        l_button_p1->frame++;
    if (l_button_p1->frame == 6)
        sfRenderWindow_close(l_win->window);
}

void is_button_pressed2(l_win_t *l_win, l_bg_t *l_bg,
    l_button_p2_t *l_button_p2)
{
    sfMouseButtonEvent mouse;

    sfRenderWindow_pollEvent(l_win->window, &(l_win->event));
    if (l_win->event.mouseButton.button == sfMouseLeft)
        mouse = l_win->event.mouseButton;
    if (mouse.x >= l_button_p2->pos.x && mouse.x <= l_button_p2->pos.x + 150 &&
        mouse.y >= l_button_p2->pos.y && mouse.y <= l_button_p2->pos.y + 67 &&
        sfMouse_isButtonPressed(sfMouseLeft) && l_button_p2->rect.left != 150
        && l_bg->frame == 23) {
        sfSound_play(l_button_p2->sound);
        l_button_p2->rect.left = 150;
        l_win->play = 1;
        l_win->bot = 0;
        }
    if (l_button_p2->rect.left == 150)
        l_button_p2->frame++;
    if (l_button_p2->frame == 6)
        sfRenderWindow_close(l_win->window);
}

void is_button_pressed3(l_win_t *l_win, l_bg_t *l_bg,
    l_button_exit_t *l_button_exit)
{
    sfMouseButtonEvent mouse;

    sfRenderWindow_pollEvent(l_win->window, &(l_win->event));
    if (l_win->event.mouseButton.button == sfMouseLeft)
        mouse = l_win->event.mouseButton;
    if (mouse.x >= l_button_exit->pos.x &&
        mouse.x <= l_button_exit->pos.x + 150 &&
        mouse.y >= l_button_exit->pos.y &&
        mouse.y <= l_button_exit->pos.y + 67 &&
        sfMouse_isButtonPressed(sfMouseLeft) && l_button_exit->rect.left != 150
        && l_bg->frame == 23) {
        sfSound_play(l_button_exit->sound);
        l_button_exit->rect.left = 150;
        l_win->play = 0;
        l_win->bot = 1;
        }
    if (l_button_exit->rect.left == 150)
        l_button_exit->frame++;
    if (l_button_exit->frame == 6)
        sfRenderWindow_close(l_win->window);
}

void is_launcher_event(l_win_t *l_win, l_bg_t *l_bg, l_button_t *l_button)
{
    is_button_pressed1(l_win, l_bg, l_button->l_button_p1);
    is_button_pressed2(l_win, l_bg, l_button->l_button_p2);
    is_button_pressed3(l_win, l_bg, l_button->l_button_exit);

    if (sfKeyboard_isKeyPressed(sfKeyEscape))
        sfRenderWindow_close(l_win->window);
}
