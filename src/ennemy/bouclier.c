/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-2-myrpg-laetitia.bousch
** File description:
** bouclier
*/

#include "my_rpg.h"

static void draw_bouclier_ennemy(scene_t *scene, game_set *setting,
                                ennemy_t *type)
{
    (void) scene;
    sfSprite_setPosition(type->sprite, type->post);
    sfSprite_setPosition(type->circle.sprite, type->circle.post);
    sfRenderWindow_drawSprite(setting->wndw, type->sprite, NULL);
}

static void four_bouclier_ennemy(scene_t *scene, game_set *setting,
                                ennemy_t *type)
{
    int tmp = 0;

    if (((int)type->post.y >= type->last_post_y - 2 &&
    (int)type->post.y <= type->last_post_y + 2) &&
    (int)type->post.x < type->last_post_x) {
        while (tmp < 100) {
            tmp += 1;
            type->post.x += 1;
            type->circle.post.x += 1;
            draw_bouclier_ennemy(scene, setting, type);
        }
    }
}

static void three_bouclier_ennemy(scene_t *scene, game_set *setting,
                                    ennemy_t *type)
{
    int tmp = 0;

    if (((int)type->post.y >= type->last_post_y - 2 &&
    (int)type->post.y <= type->last_post_y + 2) &&
    (int)type->post.x > type->last_post_x) {
        while (tmp < 100) {
            tmp += 1;
            type->post.x -= 1;
            type->circle.post.x -= 1;
            draw_bouclier_ennemy(scene, setting, type);
        }
    } else {
        four_bouclier_ennemy(scene, setting, type);
    }
}

static void two_bouclier_ennemy(scene_t *scene, game_set *setting,
                                ennemy_t *type)
{
    int tmp = 0;

    if (((int)type->post.x >= type->last_post_x - 2 &&
    (int)type->post.x <= type->last_post_x + 2) &&
    (int)type->post.y < type->last_post_y) {
        while (tmp < 100) {
            tmp += 1;
            type->post.y += 1;
            type->circle.post.y += 1;
            draw_bouclier_ennemy(scene, setting, type);
        }
    } else {
        three_bouclier_ennemy(scene, setting, type);
    }
}

void bouclier_ennemy(scene_t *scene, game_set *setting, ennemy_t *type)
{
    int tmp = 0;

    if (((int)type->post.x >= type->last_post_x - 2 &&
    (int)type->post.x <= type->last_post_x + 2) &&
    (int)type->post.y > type->last_post_y) {
        while (tmp < 100) {
            tmp += 1;
            type->post.y -= 1;
            type->circle.post.y -= 1;
            draw_bouclier_ennemy(scene, setting, type);
        }
    } else {
        two_bouclier_ennemy(scene, setting, type);
    }
}