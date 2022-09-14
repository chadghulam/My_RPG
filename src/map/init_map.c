/*
** EPITECH PROJECT, 2021
** init map
** File description:
** init map
*/

#include "my_rpg.h"

game_map *create_map(char **buffer)
{
    game_map *map = malloc(sizeof(game_map));
    map->map = malloc(sizeof(char **) * 4);

    for (int i = 0; i < 4; i++)
        map->map[i] = load_file_in_mem(buffer[i]);
    map->i = 0;
    map->door = malloc(sizeof(sfVector2f) * 4);
    map->door[0] = (sfVector2f) {56 * 16*2, 16 * 16*2};
    map->door[1] = (sfVector2f) {2* 16*2, 16 * 16*2};
    map->door[2] = (sfVector2f) {29 * 16*2, 31 * 16*2};
    map->door[3] = (sfVector2f) {29 * 16*2, 2 * 16*2};
    map->temp = malloc(sizeof(int) * 4);
    map->random = rand() % 10;
    return map;
}

static void map_base(scene_t *scene, sfVector2i vector, int k)
{
    for (int i = 20; i < 37; i++)
        if (tab[i].c == scene->map->map[scene->map->i][vector.y][vector.x]) {
            scene->obj[k]->rect = tab[i].rect;
            tab[i].select(scene->map, vector, scene->obj[k]);
        }
}

void init_map(sfRenderWindow *wndw, scene_t *scene)
{
    int k = scene->map->i == 3 ? 14 : 3;

    for (int i = 0; scene->map->map[scene->map->i][i] != NULL; i++)
        for (int j = 0; scene->map->map[scene->map->i][i][j] &&
        scene->map->map[scene->map->i][i][j] != '\n'; j++) {
            map_base(scene, (sfVector2i) {j, i}, k);
            scene->obj[k]->pos = (sfVector2f) {j * 16*2, i * 16*2};
            sfSprite_setTextureRect(scene->obj[k]->sprite, scene->obj[k]->rect);
            sfSprite_setPosition(scene->obj[k]->sprite, scene->obj[k]->pos);
            sfRenderWindow_drawSprite(wndw, scene->obj[k]->sprite, NULL);
        }
}