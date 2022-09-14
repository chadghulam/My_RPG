/*
** EPITECH PROJECT, 2021
** time global
** File description:
** init time
*/

#include "my_rpg.h"

game_time *init_time(void)
{
    game_time *time = malloc(sizeof(game_time));

    time->clock = sfClock_create();
    time->time = 0;
    time->prev = 0;
    time->delta = 0;
    time->temp_ennemy = 0;
    time->temp_player = 0;
    time->temp_pnj = 0;
    return time;
}

void global_time(game_time *time)
{
    time->time = sfTime_asSeconds(sfClock_getElapsedTime(time->clock));
    time->delta = time->time - time->prev;
    time->temp_ennemy = time->delta;
    time->temp_pnj = time->delta;
    time->prev = time->time;
}
