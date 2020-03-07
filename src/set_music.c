/*
** EPITECH PROJECT, 2019
** init
** File description:
** init struct and sprites
*/

#include <time.h>
#include "my.h"
#include "duck_hunth.h"

int init_music_arr(music_arr_t *music_arr)
{
    srand(time(0));
    music_arr->music_nb = rand() % 3;
    music_arr->music = malloc(sizeof(sfMusic *) * 2);
    if (music_arr->music == NULL)
        return (84);
    music_arr->music[0] = sfMusic_createFromFile("music/toxicity.ogg");
    if (music_arr->music[0] == NULL)
        return (84);
    sfMusic_play(music_arr->music[0]);
    sfMusic_setLoop(music_arr->music[0], sfTrue);
    sfMusic_setVolume(music_arr->music[0], 10);
    return (0);
}