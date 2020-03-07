/*
** EPITECH PROJECT, 2019
** csfml
** File description:
** csflm rtfm
*/

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "my.h"
#include "duck_hunth.h"
#include "launcher.h"

int get_score_size(char const *filepath)
{

    char *buffer = malloc(2);
    int fd = 0;
    int i = 0;
    int is_rd = 1;

    buffer[1] = '\0';
    fd = open(filepath, O_RDONLY);
    if (fd == -1)
        return (0);
    while ((buffer[0] >= '0' && buffer[0] <= '9' && is_rd > 0) || i == 0) {
        is_rd = read(fd, buffer, 1);
        i++;
    }
    close(fd);
    free(buffer);
    return (i - 1);
}

char *read_score(char const *filepath)
{
    int size = get_score_size(filepath);
    char *buffer = malloc(size + 1);
    int fd = 0;

    my_memset(buffer, 0, size + 1);
    fd = open(filepath, O_RDONLY);
    if (fd == -1)
        return (0);
    read(fd, buffer, size);
    my_strcat(buffer, "\n");
    if (buffer[0] < '0' || buffer[1] > '9') {
        buffer[1] = '\0';
        buffer[0] = '0';
    }
    close(fd);
    return (buffer);
}

void set_hscore(char *score)
{
    int fd = 0;

    fd = open("hscore", O_WRONLY | O_TRUNC);
    if (fd == -1)
        return ;
    write(fd, score, my_strlen(score));
    close(fd);
}

void set_score(int score_value, char *filepath)
{
    char *score = my_int_to_str(score_value);
    char *hscore = read_score("hscore");
    int fd = 0;

    if (score_value > my_getnbr(hscore))
        set_hscore(score);
    fd = open(filepath, O_WRONLY | O_TRUNC);
    if (fd == -1)
        return ;
    write(fd, score, my_strlen(score));
    close(fd);
    free(score);
}