/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-2-myrpg-laetitia.bousch
** File description:
** init_circle_ennemy
*/

#include "my_rpg.h"

struct_zone_attack_t init_circle_post(ennemy_t *ennemy)
{
    struct_zone_attack_t circle;

    circle.texture = sfTexture_createFromFile(zone_attack.texture, NULL);
    circle.sprite = sfSprite_create();
    sfSprite_setTexture(circle.sprite, circle.texture, sfTrue);
    sfSprite_setScale(circle.sprite, zone_attack.size);
    sfSprite_setPosition(circle.sprite, ennemy->post);
    sfSprite_setTextureRect(circle.sprite, zone_attack.rect);
    circle.post.x = ennemy->post.x - 200;
    circle.post.y = ennemy->post.y - 195;
    return circle;
}