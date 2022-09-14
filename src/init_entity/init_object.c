/*
** EPITECH PROJECT, 2021
** sprite
** File description:
** create sprite
*/

#include "my_rpg.h"

//mob == ennemie

static game_obj obj_fix[] = {
    {"sprite/main_menu2.png", {0, 0}, {1, 1}, {0, 0, 1920, 1080}, 0, 0},
    {"sprite/volumemus.png", {320, 140}, {0.7, 0.7}, {0, 0, 1920, 1080}, 0, 0},
    {"sprite/howtoplayfix.png", {320, 140}, {0.7, 0.7},
    {0, 0, 1920, 1080}, 0, 0},
    {"sprite/maprpg.png", {0, 0}, {2, 2}, {0, 0, 16, 16}, 0, 0},
    {"sprite/mob1.png", {0, 180}, {0.39, 0.39}, {0, 0, 256, 207}, 0, 0},
    {"sprite/mob2.png", {0, 180}, {0.39, 0.39}, {0, 0, 296, 277}, 0, 0},
    {"sprite/mob3.png", {0, 180}, {0.35, 0.35}, {0, 0, 345, 350}, 0, 0},
    {"sprite/my_rpg.png", {180, -215}, {0.7, 0.7}, {0, 0, 1920, 1080}, 0, 0},
    {"sprite/lvl_icon.png", {1850, 30}, {0.1, 0.1}, {0, 0, 512, 512}, 0, 0},
    {"sprite/stats.png", {0, 0}, {0.25, 0.25}, {0, 0, 1920, 1080}, 0, 0},
    {"sprite/heart_life.png", {1420, 30}, {0.07, 0.07},
    {0, 0, 508, 491}, 0, 0},
    {"sprite/defeat.jpg", {0, 0}, {1, 1}, {0, 0, 1920, 1080}, 0, 0},
    {"sprite/victory.jpg", {0, 0}, {1, 1}, {0, 0, 1920, 1080}, 0, 0},
    {"sprite/player.png", {29*32, 31*32}, {2, 2}, {16, 16, 16, 16}, 0, 0},
    {"sprite/mapboss.png", {0, 0}, {2, 2}, {16*9, 16*12, 16*1, 16*1}, 0, 0},
    {"sprite/inventory.png", {200, 100}, {2, 2}, {0, 0, 749, 422}, 0, 0},
    {"sprite/Weapon.png", {610, 310}, {2.6, 2.6}, {0, 0, 113, 114}, 0, 0},
    {"sprite/elexir.png", {960, 550}, {0.1, 0.1}, {230, 0, 225, 198}, 0, 0}
};

game_obj **create_entity_object(void)
{
    game_obj **entity_obj = malloc(sizeof(game_obj*) * 18);

    for (int i = 0; i < 18; i++)
        entity_obj[i] = init_object(&obj_fix[i]);
    return entity_obj;
}

game_obj *init_object(game_obj *obj)
{
    sfTexture *texture = sfTexture_createFromFile(obj->ps, NULL);

    obj->sprite = sfSprite_create();
    sfSprite_setTexture(obj->sprite, texture, sfFalse);
    sfSprite_setPosition(obj->sprite, obj->pos);
    sfSprite_setScale(obj->sprite, obj->scale);
    sfSprite_setTextureRect(obj->sprite, obj->rect);
    return obj;
}