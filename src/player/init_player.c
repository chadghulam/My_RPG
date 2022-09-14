/*
** EPITECH PROJECT, 2021
** player
** File description:
** init player
*/

#include "my_rpg.h"

void init_player(game_obj *obj, game_player player_stats)
{
    game_player *player = malloc(sizeof(game_player));

    *player = player_stats;
    obj->stats = player;
}