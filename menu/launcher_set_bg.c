/*
** EPITECH PROJECT, 2019
** csfml
** File description:
** csflm rtfm
*/

#include "my.h"
#include "duck_hunth.h"
#include "launcher.h"

int init_launcher_bg_menu(l_bg_t *l_bg)
{
    int i = -1;
    char *part1 = malloc(14);
    char *part2 = malloc(4);
    char *path = malloc(sizeof(char) * 21);

    my_strcpy(part1, "./sprite/bg/bg");
    my_strcpy(part2, ".png");
    my_memset(path, 0, 21);
    while (++i < 46) {
        my_strcat(path, part1);
        if (i < 9)
            my_strcat(path, "0");
        my_strcat(path, my_int_to_str(i + 1));
        my_strcat(path, part2);
        l_bg->t_menu[i] = sfTexture_createFromFile(path, NULL);
        my_memset(path, 0, 21);
        if (l_bg->t_menu[i] == NULL)
            return (84);
    }
    return (0);
}