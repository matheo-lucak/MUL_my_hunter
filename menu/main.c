/*
** EPITECH PROJECT, 2019
** csfml
** File description:
** csflm rtfm
*/

#include "my.h"
#include "duck_hunth.h"
#include "launcher.h"

int launcher(int *play, int *bot);

int error(char **env)
{
    char *display = "DISPLAY";
    int i = -1;

    if (env[0] == NULL)
        return (84);
    while (env[++i] != NULL)
        if (my_strcmp(env[i], display) == 0)
            return (0);
    return (84);
}

void print_rules(void)
{
    my_putstr("\nUSAGE: ./my_hunter\n\n");
    my_putstr("Welcome to DUCKY DUCKY FEEDER\n\n");
    my_putstr("\t/!\\/!\\/!\\ RULES /!\\/!\\/!\\:\n");
    my_putstr("\t-Hit ducks with carrots to feed them\n");
    my_putstr("\t-Hit birds with seeds to feed them\n");
    my_putstr("\t-You have a limited amount of ammo, take care\n");
    my_putstr("\t-Hit entity with corresponding ammo refill it\n\n");
    my_putstr("\tCOMMANDS:\n");
    my_putstr("\t\tPlayer 1:\n");
    my_putstr("\t\t\tRotate Cannon -> Left / Right\n");
    my_putstr("\t\t\tPower Cannon  -> Up   / Down\n");
    my_putstr("\t\t\tFire Carrot   -> Num1 / NumPad1\n");
    my_putstr("\t\t\tFire Seed     -> Num2 / NumPad2\n");
    my_putstr("\t\tPlayer 2 (only duo):\n");
    my_putstr("\t\t\tMove Cursor   -> A / W\n");
    my_putstr("\t\t\tSide Cursor   -> D\n");
    my_putstr("\t\t\tMode Cursor   -> S\n");
    my_putstr("\t\t\tFire Cursor   -> Q\n\n");
}

int launch_game(void)
{
    int play = 0;
    int bot = 0;

    if (launcher(&play, &bot) == 84)
        return (84);
    if (play == 1)
        if (start_game(bot) == 84)
            return (84);
    return (0);
}

int main(int ac, char **av, char **env)
{
    if (error(env) == 84)
        return (84);

    if (ac == 1)
        return (launch_game());
    else if (ac == 2 && my_strcmp(av[1], "-h") == 0)
        print_rules();
    return (0);
}
