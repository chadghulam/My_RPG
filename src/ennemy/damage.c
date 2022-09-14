/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-2-myrpg-laetitia.bousch
** File description:
** damage
*/

#include "my_rpg.h"

static void four_damage_ennemy(scene_t *scene, game_set *setting,
                                ennemy_t *type)
{
    int tmp = 0;

    if (((int)type->post.y >= type->last_post_y - 2 &&
    (int)type->post.y <= type->last_post_y + 2) &&
    (int)type->post.x < type->last_post_x) {
        scene->obj[13]->rect.left = 256;
        scene->obj[13]->rect.top = 40;
        ((game_player *) scene->obj[13]->stats)->life -= type->damage;
        while (tmp < 100) {
            tmp += four_damage_ennemy_bis(scene, setting, type);
        }
        scene->obj[13]->rect.height = 16;
        scene->obj[13]->rect.width = 16;
        scene->obj[13]->rect.left = 16;
        scene->obj[13]->rect.top = 48;
    }
}

static void three_damage_ennemy(scene_t *scene, game_set *setting,
                                ennemy_t *type)
{
    int tmp = 0;

    if (((int)type->post.y >= type->last_post_y - 2 &&
    (int)type->post.y <= type->last_post_y + 2) &&
    (int)type->post.x > type->last_post_x) {
        scene->obj[13]->rect.left = 256;
        scene->obj[13]->rect.top = 32;
        ((game_player *) scene->obj[13]->stats)->life -= type->damage;
        while (tmp < 100) {
            tmp += three_damage_ennemy_bis(scene, setting, type);
        }
        scene->obj[13]->rect.height = 16;
        scene->obj[13]->rect.width = 16;
        scene->obj[13]->rect.left = 16;
        scene->obj[13]->rect.top = 32;
    } else {
        four_damage_ennemy(scene, setting, type);
    }
}

static void two_damage_ennemy(scene_t *scene, game_set *setting,
                                ennemy_t *type)
{
    int tmp = 0;

    if (((int)type->post.x >= type->last_post_x - 2 &&
        (int)type->post.x <= type->last_post_x + 2) &&
        (int)type->post.y < type->last_post_y) {
        scene->obj[13]->rect.left = 256;
        scene->obj[13]->rect.top = 16;
        ((game_player *) scene->obj[13]->stats)->life -= type->damage;
        while (tmp < 100) {
            tmp += two_damage_ennemy_bis(scene, setting, type);
        }
        scene->obj[13]->rect.height = 16;
        scene->obj[13]->rect.width = 16;
        scene->obj[13]->rect.left = 16;
        scene->obj[13]->rect.top = 16;
    } else {
        three_damage_ennemy(scene, setting, type);
    }
}

void damage_ennemy(scene_t *scene, game_set *setting, ennemy_t *type)
{
    int tmp = 0;

    if (((int)type->post.x >= type->last_post_x - 2 &&
        (int)type->post.x <= type->last_post_x + 2) &&
        type->post.y > type->last_post_y) {
        scene->obj[13]->rect.left = 256;
        scene->obj[13]->rect.top = 64;
        ((game_player *) scene->obj[13]->stats)->life -= type->damage;
        while (tmp < 100) {
            tmp += one_damage_ennemy_bis(scene, setting, type);
        }
        scene->obj[13]->rect.height = 16;
        scene->obj[13]->rect.width = 16;
        scene->obj[13]->rect.left = 16;
        scene->obj[13]->rect.top = 64;
    } else {
        two_damage_ennemy(scene, setting, type);
    }
}