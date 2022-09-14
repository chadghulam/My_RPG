/*
** EPITECH PROJECT, 2021
** map boss
** File description:
** map boss
*/

#include "my_rpg.h"

void collision_square(game_map *map, sfVector2i vector, game_obj *obj)
{
    (void) map;
    obj->rect = tab[(vector.y * vector.x +map->random) % 3 + 45].rect;
}

void empty_square(game_map *map, sfVector2i vector, game_obj *obj)
{
    (void) map;
    obj->rect = tab[(vector.y * vector.x + map->i +map->random) % 9 + 37].rect;
}