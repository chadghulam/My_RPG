/*
** EPITECH PROJECT, 2021
** my_runner
** File description:
** runner
*/

#include "my_rpg.h"

int rpg(void)
{
    game_set *setting = init_setting();
    scene_t *scene = init_scene();

    while (sfRenderWindow_isOpen(setting->wndw)) {
        sfRenderWindow_display(setting->wndw);
        game_event(setting, scene);
        global_time(setting->time);
        display_scene(setting, scene);
        setting->buttonpress = 0;
    }
    destroy_setting(setting);
    destroy_scene(scene);
    return 0;
}
