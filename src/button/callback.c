/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** callback.c
*/

#include "my_rpg.h"

void closing(game_set *setting, scene_t *scene)
{
    (void) scene;
    sfRenderWindow_close(setting->wndw);
}

void play(game_set *setting, scene_t *scene)
{
    (void) scene;
    setting->state = 2;
}

void option(game_set *setting, scene_t *scene)
{
    (void) scene;
    if (setting->option == 1)
        setting->option = 0;
    else
        setting->option = 1;
}

void home(game_set *setting, scene_t *scene)
{
    (void) scene;
    setting->state = 1;
    setting->option = 0;
    scene->map->i = 0;
    scene = init_scene();
    scene->obj[13]->pos = (sfVector2f) {29*32, 31*32};
}

void help(game_set *setting, scene_t *scene)
{
    (void) scene;
    if (setting->state == 3)
        setting->state = 1;
    else
        setting->state = 3;
}