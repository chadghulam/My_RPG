/*
** EPITECH PROJECT, 2021
** particle
** File description:
** particle
*/

#include "my_rpg.h"

void particle_rain(game_set *set)
{
    for (int i = 0; i < 80; i++) {
        if (set->pixelbuff->y[i] < (int)set->pixelbuff->height) {
            draw_disque(set->pixelbuff,
            (sfVector2i){set->pixelbuff->x[i], set->pixelbuff->y[i]},
            (rand() % 4 + 3), sfBlue);
            set->pixelbuff->y[i] += rand() % 100;
        }
        else {
            set->pixelbuff->y[i] = 0;
            set->pixelbuff->x[i] = rand() % set->pixelbuff->width;
        }
    }
}

void clear_pixel(game_set *set)
{
    for (unsigned int i = 0; i < set->pixelbuff->height; i++)
        for (unsigned int j = 0; j < set->pixelbuff->width; j++)
            my_put_pixel(set->pixelbuff, j, i, sfTransparent);
}