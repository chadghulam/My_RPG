/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-2-myrpg-laetitia.bousch
** File description:
** attack
*/

#include "my_rpg.h"

static void draw_attack_ennemy(game_set *setting, ennemy_t *type)
{
    sfSprite_setPosition(type->sprite, type->post);
    sfSprite_setPosition(type->circle.sprite, type->circle.post);
    sfRenderWindow_drawSprite(setting->wndw, type->sprite, NULL);
}

static void four_attack_ennemy(game_set *setting,
                                ennemy_t *type, scene_t *scene)
{
    int tmp = 0;

    if (((int)type->post.y >= type->last_post_y - 2 &&
    (int)type->post.y <= type->last_post_y + 2) &&
    (int)type->post.x < type->last_post_x) {
        type->life -= ((game_player *) scene->obj[13]->stats)->damage;
        while (tmp < 100 && type->life > 0) {
            tmp += 1;
            type->post.x += 1;
            type->circle.post.x += 1;
            draw_attack_ennemy(setting, type);
        }
        if (type->life <= 0) {
            ((game_player *) scene->obj[13]->stats)->xp += 125;
            type->rect.left = 0;
        }
    }
}

static void three_attack_ennemy(game_set *setting,
                                ennemy_t *type, scene_t *scene)
{
    int tmp = 0;

    if (((int)type->post.y >= type->last_post_y - 2 &&
    (int)type->post.y <= type->last_post_y + 2) &&
    (int)type->post.x > type->last_post_x) {
        type->life -= ((game_player *) scene->obj[13]->stats)->damage;
        while (tmp < 100 && type->life > 0) {
            tmp += 1;
            type->post.x -= 1;
            type->circle.post.x -= 1;
            draw_attack_ennemy(setting, type);
        }
        if (type->life <= 0) {
            ((game_player *) scene->obj[13]->stats)->xp += 125;
            type->rect.left = 0;
        }
    } else {
        four_attack_ennemy(setting, type, scene);
    }
}

static void two_attack_ennemy(game_set *setting,
                                ennemy_t *type, scene_t *scene)
{
    int tmp = 0;

    if (((int)type->post.x >= type->last_post_x - 2 &&
    (int)type->post.x <= type->last_post_x + 2) &&
    (int)type->post.y < type->last_post_y) {
        type->life -= ((game_player *) scene->obj[13]->stats)->damage;
        while (tmp < 100 && type->life > 0) {
            tmp += 1;
            type->post.y += 1;
            type->circle.post.y += 1;
            draw_attack_ennemy(setting, type);
        }
        if (type->life <= 0) {
            ((game_player *) scene->obj[13]->stats)->xp += 125;
            type->rect.left = 0;
        }
    } else {
        three_attack_ennemy(setting, type, scene);
    }
}

void attack_ennemy(scene_t *scene, game_set *setting, ennemy_t *type)
{
    int tmp = 0;

    if (((int)type->post.x >= type->last_post_x - 2 &&
    (int)type->post.x <= type->last_post_x + 2) &&
    (int)type->post.y > type->last_post_y) {
        type->life -= ((game_player *) scene->obj[13]->stats)->damage;
        while (tmp < 100 && type->life > 0) {
            tmp += 1;
            type->post.y -= 1;
            type->circle.post.y -= 1;
            draw_attack_ennemy(setting, type);
        }
        if (type->life <= 0) {
            ((game_player *) scene->obj[13]->stats)->xp += 125;
            type->rect.left = 0;
        }
    } else {
        two_attack_ennemy(setting, type, scene);
    }
}