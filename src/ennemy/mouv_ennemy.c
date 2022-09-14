/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-2-myrpg-laetitia.bousch
** File description:
** mouv_ennemy
*/

#include "my_rpg.h"

static void four_mouv_ennemy(int i, ennemy_t *type)
{
    if (type[i].post.x < type[i].post_rand_x) {
        type[i].post.x += 2;
        type[i].circle.post.x += 2;
        type[i].direction = 1;
    }
    if (type[i].post.y < type[i].post_rand_y) {
        type[i].post.y += 2;
        type[i].circle.post.y += 2;
    }
}

static void three_mouv_ennemy(int i, ennemy_t *type)
{
    type[i].last_post_y = type[i].post.y;
    type[i].last_post_x = type[i].post.x;
    if (type[i].post.x > type[i].post_rand_x) {
        type[i].post.x -= 2;
        type[i].circle.post.x -= 2;
        type[i].direction = 0;
    }
    if (type[i].post.y > type[i].post_rand_y) {
        type[i].post.y -= 2;
        type[i].circle.post.y -= 2;
    }
    four_mouv_ennemy(i, type);
}

static void two_mouv_ennemy(int i, ennemy_t *type)
{
    type[i].post_rand_x = (rand() % 1850);
    if (type[i].post_rand_x == 0) {
        type[i].post_rand_x = (rand() % 1850);
    }
    type[i].post_rand_y = (rand() % 1000);
    if (type[i].post_rand_y == 0) {
        type[i].post_rand_y = (rand() % 1000);
    }
}

void mouv_ennemy(int i, ennemy_t *type)
{
    if ((type[i].post.x <= (type[i].post_rand_x + 10) &&
        type[i].post.x >= (type[i].post_rand_x - 10))
    && (type[i].post.y <= (type[i].post_rand_y + 10) &&
    type[i].post.y >= (type[i].post_rand_y - 10))) {
        two_mouv_ennemy(i, type);
    } else {
        three_mouv_ennemy(i, type);
    }
}