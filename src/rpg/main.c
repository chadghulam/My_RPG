/*
** EPITECH PROJECT, 2021
** main
** File description:
** main runner
*/

#include "my_rpg.h"

int main(int ac, char **av, char **env)
{
    if (ac == 2 && my_strcmp(av[1], "-h") == 0)
        return 0;
    if (handle_error(ac, env) == 84)
        return 84;
    srand(time(NULL));
    return rpg();
}
