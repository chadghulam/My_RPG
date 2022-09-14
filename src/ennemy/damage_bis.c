/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-2-myrpg-laetitia.bousch
** File description:
** damage_bis
*/

#include "my_rpg.h"

int four_damage_ennemy_bis(scene_t *scene, game_set *setting,
                                ennemy_t *type)
{
    if (collision_player(scene->map, scene->obj[13],
    setting->time->delta, (sfVector2f) {0, 0}) == 1) {
        for (int i = 0; i < 100; i++) {
            type->post.x += 0.2;
            sfSprite_setPosition(type->sprite, type->post);
            sfRenderWindow_drawSprite(setting->wndw, type->sprite, NULL);
        }
        return 100;
    } else {
        scene->obj[13]->pos.x -= 0.2;
        sfSprite_setTextureRect(scene->obj[13]->sprite, scene->obj[13]->rect);
        sfSprite_setPosition(scene->obj[13]->sprite, scene->obj[13]->pos);
        sfRenderWindow_drawSprite(setting->wndw, scene->obj[13]->sprite, NULL);
    }
    return 1;
}

int three_damage_ennemy_bis(scene_t *scene, game_set *setting,
                                ennemy_t *type)
{
    if (collision_player(scene->map, scene->obj[13],
        setting->time->delta, (sfVector2f) {0, 0}) == 1) {
        for (int i = 0; i < 100; i++) {
            type->post.x -= 0.2;
            sfSprite_setPosition(type->sprite, type->post);
            sfRenderWindow_drawSprite(setting->wndw, type->sprite, NULL);
        }
        return 100;
    } else {
        scene->obj[13]->pos.x += 0.2;
        sfSprite_setTextureRect(scene->obj[13]->sprite, scene->obj[13]->rect);
        sfSprite_setPosition(scene->obj[13]->sprite, scene->obj[13]->pos);
        sfRenderWindow_drawSprite(setting->wndw, scene->obj[13]->sprite, NULL);
    }
    return 1;
}

int two_damage_ennemy_bis(scene_t *scene, game_set *setting,
                                ennemy_t *type)
{
    if (collision_player(scene->map, scene->obj[13],
        setting->time->delta, (sfVector2f) {0, 0}) == 1) {
        for (int i = 0; i < 100; i++) {
            type->post.y += 0.2;
            sfSprite_setPosition(type->sprite, type->post);
            sfRenderWindow_drawSprite(setting->wndw, type->sprite, NULL);
        }
        return 100;
    } else {
        scene->obj[13]->pos.y -= 0.2;
        sfSprite_setTextureRect(scene->obj[13]->sprite, scene->obj[13]->rect);
        sfSprite_setPosition(scene->obj[13]->sprite, scene->obj[13]->pos);
        sfRenderWindow_drawSprite(setting->wndw, scene->obj[13]->sprite, NULL);
    }
    return 1;
}

int one_damage_ennemy_bis(scene_t *scene, game_set *setting,
                                ennemy_t *type)
{
    if (collision_player(scene->map, scene->obj[13],
        setting->time->delta, (sfVector2f) {0, 0}) == 1) {
        for (int i = 0; i < 100; i++) {
            type[i].post.y -= 0.2;
            sfSprite_setPosition(type->sprite, type->post);
            sfRenderWindow_drawSprite(setting->wndw, type->sprite, NULL);
        }
        return 100;
    } else {
        scene->obj[13]->pos.y += 0.2;
        sfSprite_setTextureRect(scene->obj[13]->sprite, scene->obj[13]->rect);
        sfSprite_setPosition(scene->obj[13]->sprite, scene->obj[13]->pos);
        sfRenderWindow_drawSprite(setting->wndw, scene->obj[13]->sprite, NULL);
    }
    return 1;
}