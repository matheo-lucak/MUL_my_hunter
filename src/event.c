/*
** EPITECH PROJECT, 2019
** csfml
** File description:
** csflm rtfm
*/

#include <SFML/System/Export.h>
#include <SFML/System/Time.h>
#include <SFML/System/Types.h>
#include "my.h"
#include "duck_hunth.h"

void is_close(win_t *win, text_t *text)
{
    sfVector2f pos;
    sfClock *clock = sfClock_create();
    float s = sfClock_getElapsedTime(clock).microseconds / 1000000.0;

    pos.x = 300;
    pos.y = 300;
    sfText_setCharacterSize(text->text, 50);
    sfText_setPosition(text->text, pos);
    sfSprite_setTexture(win->pause_sprite, win->g_ovr_texture, sfTrue);
    sfRenderWindow_drawSprite(win->window, win->pause_sprite, NULL);
    sfRenderWindow_drawText(win->window, text->text, NULL);
    sfRenderWindow_display(win->window);
    while (s < 5)
        s = sfClock_getElapsedTime(clock).microseconds / 1000000.0;
    sfClock_destroy(clock);
}

void is_pause(win_t *win)
{
    int i = 0;

    if (sfKeyboard_isKeyPressed(sfKeyP)) {
        sfSprite_setTexture(win->pause_sprite, win->pause_texture, sfTrue);
        sfRenderWindow_drawSprite(win->window, win->pause_sprite, NULL);
        sfRenderWindow_display(win->window);
        i = 1;
    }
    while (i == 1) {
        sfRenderWindow_pollEvent(win->window, &(win->event));
        if (win->event.type == sfEvtClosed ||
            sfKeyboard_isKeyPressed(sfKeyEscape)) {
            win->restart = 0;
            sfRenderWindow_close(win->window);
            }
        if (sfKeyboard_isKeyPressed(sfKeySpace))
            i = 0;
    }
}

void fire_event(obj_t *obj)
{
    if (sfKeyboard_isKeyPressed(sfKeyNumpad1) ||
        sfKeyboard_isKeyPressed(sfKeyNumpad2) ||
        sfKeyboard_isKeyPressed(sfKeyNum1) ||
        sfKeyboard_isKeyPressed(sfKeyNum2))
        fire_ammo(obj->cannon, obj->ammo);
    is_collid_able(obj->entity, obj->ammo);
}

void close_event(win_t *win)
{
    while (sfRenderWindow_pollEvent(win->window, &(win->event)));
    if (sfKeyboard_isKeyPressed(sfKeyEscape) ||
        win->event.type == sfEvtClosed) {
        win->restart = 0;
        sfRenderWindow_close(win->window);
    }
}

void is_event(win_t *win, obj_t *obj)
{
    cannon_rotate(obj->cannon);
    cannon_power(obj->cannon);
    fire_event(obj);
    cursor_event(win, obj->cursor, obj->entity);
    is_fed(win, obj->entity);
    is_fed_entity_outside(win, obj->entity);
    is_entity_outside(win, obj->entity);
    check_lvl(win, obj);
    if (win->life == 0) {
        is_close(win, obj->text);
        set_score(win->score, "score");
        sfRenderWindow_close(win->window);
    }
    win->time++;
    is_pause(win);
    close_event(win);
}