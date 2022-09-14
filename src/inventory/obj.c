/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-2-myrpg-laetitia.bousch
** File description:
** obj
*/

#include "my_rpg.h"

void dop_item_quests_one(scene_t *scene, game_set *setting)
{
    for (int i = 0; i < 3; i++) {
        sfSprite_setPosition(scene->obj[16]->sprite,
        (sfVector2f){950 + i * 10, 540 + i * 10});
        sfSprite_setTextureRect(scene->obj[16]->sprite,
        (sfIntRect){37, 37 * i, 37, 37});
        sfRenderWindow_drawSprite(setting->wndw,
        scene->obj[16]->sprite, 0);
    }
    sfRenderWindow_drawSprite(setting->wndw, scene->obj[17]->sprite, 0);
}

void dop_item_quests_two(scene_t *scene, game_set *setting)
{
    for (int i = 0; i < 3; i++) {
        sfSprite_setPosition(scene->obj[16]->sprite,
        (sfVector2f){950 +i * 10, 540 + i * 10});
        sfSprite_setTextureRect(scene->obj[16]->sprite,
        (sfIntRect){37 * 2, 37 * i, 37, 37});
        sfRenderWindow_drawSprite(setting->wndw,
        scene->obj[16]->sprite, 0);
    }
    sfRenderWindow_drawSprite(setting->wndw, scene->obj[17]->sprite, 0);
}

int equip_item(scene_t *scene)
{
    ((game_player *)scene->obj[13]->stats)->life += 40;
    ((game_player *)scene->obj[13]->stats)->state += 1;
    return 1;
}