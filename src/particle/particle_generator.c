/*
** EPITECH PROJECT, 2021
** particle
** File description:
** particle
*/

#include "my_rpg.h"

particle_t *pixelbuffer_create(unsigned int width, unsigned int height)
{
    particle_t *pixelbuff = malloc(sizeof(particle_t));

    if (pixelbuff == NULL)
        return (NULL);
    pixelbuff->pixels = malloc(sizeof(sfUint8) * width * height * 32/4);
    pixelbuff->width = width;
    pixelbuff->height = height;
    for (int i = 0; i < 80; i++) {
        pixelbuff->x[i] = rand() % pixelbuff->width;
        pixelbuff->y[i] = rand() % 20;
    }
    pixelbuff->texture = sfTexture_create(width, height);
    pixelbuff->sprite = sfSprite_create();
    sfSprite_setTexture(pixelbuff->sprite, pixelbuff->texture, sfTrue);

    return (pixelbuff);
}

void my_put_pixel(particle_t *pixelbuff, unsigned int x, unsigned int y,
sfColor color)
{
    if (x > pixelbuff->width || y > pixelbuff->height)
        return ;
    pixelbuff->pixels[(pixelbuff->width * y + x) * 4 + 0] = color.r;
    pixelbuff->pixels[(pixelbuff->width * y + x) * 4 + 1] = color.g;
    pixelbuff->pixels[(pixelbuff->width * y + x) * 4 + 2] = color.b;
    pixelbuff->pixels[(pixelbuff->width * y + x) * 4 + 3] = color.a;
}

void draw_line(particle_t *pixelbuff, sfVector2i a, sfVector2i b, sfColor color)
{
    double coeff_a = (b.y - a.y)/(b.x - a.x);
    double origin_b = a.y - coeff_a * a.x;

    if (a.x == b.x) {
        for (; a.y <= b.y; a.y++)
            my_put_pixel(pixelbuff, a.x, a.y, color);
        for (; a.y >= b.y; a.y--)
            my_put_pixel(pixelbuff, a.x, a.y, color);
        return ;
    }
    for (; a.x <= b.x; a.x++, a.y = coeff_a * a.x + origin_b)
        my_put_pixel(pixelbuff, a.x, a.y, color);
    for (; a.x >= b.x; a.x--, a.y = coeff_a * a.x + origin_b)
        my_put_pixel(pixelbuff, a.x, a.y, color);
}

void draw_disque(particle_t *pixelbuff, sfVector2i C, int radius, sfColor color)
{
    for (int y = C.y - radius; y < C.y + radius; y++)
        for (int x = C.x - radius; x < C.x + radius; x++)
            if (pow(y - C.y, 2) + pow(x - C.x, 2) <= pow(radius, 2))
                my_put_pixel(pixelbuff, x, y, color);
}

void particle_generator(game_set *set)
{
    particle_rain(set);
    sfTexture_updateFromPixels(set->pixelbuff->texture, set->pixelbuff->pixels,
    set->pixelbuff->width, set->pixelbuff->height, 0, 0);
    sfRenderWindow_drawSprite(set->wndw, set->pixelbuff->sprite, NULL);
    clear_pixel(set);
}
