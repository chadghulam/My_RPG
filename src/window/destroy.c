/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** free structure
*/

#include "my_rpg.h"

static void destroy_map(game_map *map)
{
    for (int i = 0; i < 4; i++) {
        for (int j = 0; map->map[i][j] != NULL; j++) {
            free(map->map[i][j]);
        }
        free(map->map[i]);
    }
    free(map->map);
    free(map);
}

void destroy_scene(scene_t *scene)
{
    destroy_map(scene->map);
    destroy_ennemy(&(scene->type_ennemy));
    destroy_pnj(&(scene->type_pnj));
    free(scene->button);
    free(scene);
}