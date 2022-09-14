/*
** EPITECH PROJECT, 2021
** error
** File description:
** handle errror of my_runner
*/

#include "my_rpg.h"

int handle_error(int ac, char **env)
{
    if (ac != 1 || env[0] == NULL)
        return 84;
    return 0;
}
