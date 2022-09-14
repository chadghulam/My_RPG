/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** menu.c
*/

#include "my_rpg.h"

void menu(game_set *setting, scene_t *scene)
{
    sfRenderWindow_drawSprite(setting->wndw, scene->obj[0]->sprite, NULL);
    particle_generator(setting);
    sfRenderWindow_drawSprite(setting->wndw, scene->obj[7]->sprite, NULL);

    if (setting->option != 1)
        for (int i = 0; i < 4; i++)
            display_menu_button(scene->button[i], setting, scene);
}