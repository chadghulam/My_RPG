/*
** EPITECH PROJECT, 2021
** collision
** File description:
** collision
*/

#include "my_rpg.h"

static void door_map(game_obj *player, game_map *maps, char map)
{
    if (maps->i == 1 && map - 48 == 0)
        player->pos = maps->door[1];
    if (maps->i == 2 && map - 48 == 0)
        player->pos = maps->door[0];
    if (maps->i == 3 && map - 48 == 0)
        player->pos = maps->door[3];
}

int collision_player(game_map *maps, game_obj *player, float d, sfVector2f pos)
{
    char **map = maps->map[maps->i];
    int y = round((player->pos.y + pos.y * d) / (16 * 2));
    int x = round((player->pos.x + pos.x * d) / (16 * 2));

    if (map[y] && (map[y][x] == 'C' || map[y][x] == 'i' ||
    map[y][x] == 'j' || map[y][x] == 'k' ||
    map[y][x] == 'M' || map[y][x] == 'D' || map[y][x] == 'R'))
        return 1;
    door_map(player, maps, map[y][x]);
    for (int i = 1; i <= ((game_player *)player->stats)->state; i++)
        if (maps->i == 0 && map[y][x] - 48 == i)
            player->pos = maps->door[i - 1];
    if (map[y][x] >= '0' && map[y][x] < ((game_player*)player->stats)->state+49)
        maps->i = map[y][x] - 48;
    return 0;
}