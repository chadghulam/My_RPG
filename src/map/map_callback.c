/*
** EPITECH PROJECT, 2021
** callback
** File description:
** callback
*/

#include "my_rpg.h"

void empty(game_map *map, sfVector2i vector, game_obj *obj)
{
    (void) map;
    (void) vector;
    (void) obj;
    return ;
}

void minor_collision(game_map *map, sfVector2i vector, game_obj *obj)
{
    (void) map;
    obj->rect = tab[(vector.y * vector.x + map->i +map->random) % 11].rect;
}

void empty_collision(game_map *map, sfVector2i vector, game_obj *obj)
{
    (void) map;
    obj->rect = tab[(vector.y * vector.x + map->i +map->random) % 8 + 11].rect;
}

void side_path(game_map *maps, sfVector2i vector, game_obj *obj)
{
    char **map = maps->map[maps->i];

    if (map[vector.y -1][vector.x] == 'P')
        obj->rect = (sfIntRect) {16*6, 16*1, 16*1, 16*1};
    if (map[vector.y +1][vector.x] == 'P')
        obj->rect = (sfIntRect) {16*1, 16*1, 16*1, 16*1};
    if (map[vector.y][vector.x +1] == 'P')
        obj->rect = (sfIntRect) {16*3, 16*1, 16*1, 16*1};
    if (map[vector.y][vector.x - 1] == 'P')
        obj->rect = (sfIntRect) {16*4, 16*1, 16*1, 16*1};
    if (map[vector.y -1][vector.x] == 'P' && map[vector.y][vector.x +1] == 'P')
        obj->rect = (sfIntRect) {16*5, 16*1, 16*1, 16*1};
    if (map[vector.y -1][vector.x] == 'P' && map[vector.y][vector.x -1] == 'P')
        obj->rect = (sfIntRect) {16*7, 16*1, 16*1, 16*1};
    if (map[vector.y +1][vector.x] == 'P' && map[vector.y][vector.x +1] == 'P')
        obj->rect = (sfIntRect) {16*0, 16*1, 16*1, 16*1};
    if (map[vector.y +1][vector.x] == 'P' && map[vector.y][vector.x -1] == 'P')
        obj->rect = (sfIntRect) {16*2, 16*1, 16*1, 16*1};
}