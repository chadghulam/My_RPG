/*
** EPITECH PROJECT, 2021
** window event
** File description:
** wdw event and create sprite
*/

#include "my_rpg.h"

void create_wndw(unsigned width, unsigned height,
                char *titl, game_set *setting)
{
    sfVideoMode video_mode = {width, height, 32};

    setting->wndw = sfRenderWindow_create(video_mode, titl,
    sfResize | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(setting->wndw, 60);
}