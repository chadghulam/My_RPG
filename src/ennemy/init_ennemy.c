/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-2-myrpg-laetitia.bousch
** File description:
** init_ennemy
*/

#include "my_rpg.h"

static void init_values(ennemy_t *ennemy, int life, sfVector2f pos_ennemy,
                        sfIntRect rect)
{
    ennemy->life = life;
    ennemy->post.x = pos_ennemy.x;
    ennemy->post.y = pos_ennemy.y;
    ennemy->rect = rect;
    ennemy->post_rand_x = pos_ennemy.x;
    ennemy->post_rand_y = pos_ennemy.y;
    ennemy->last_post_x = 0;
    ennemy->last_post_y = 0;
    ennemy->direction = 0;
    ennemy->dead = 1;
}

static ennemy_t *init_type_ennemy(init_ennemy_t const *ennemy_fix, int life)
{
    ennemy_t *ennemy = malloc(sizeof(ennemy_t) * 30);
    sfVector2f pos_ennemy = ennemy_fix->post;
    sfVector2f origin = {8, 8};

    for (int i = 0; i < 10; i++) {
        ennemy[i].texture = sfTexture_createFromFile(ennemy_fix->texture,
                                                    NULL);
        ennemy[i].sprite = sfSprite_create();
        sfSprite_setTexture(ennemy[i].sprite, ennemy[i].texture, sfTrue);
        sfSprite_setScale(ennemy[i].sprite, ennemy_fix->size);
        sfSprite_setOrigin(ennemy[i].sprite, origin);
        sfSprite_setPosition(ennemy[i].sprite, pos_ennemy);
        sfSprite_setTextureRect(ennemy[i].sprite, ennemy_fix->rect);
        init_values(&ennemy[i], life, pos_ennemy, ennemy_fix->rect);
        ennemy[i].damage = 10;
        ennemy[i].circle = init_circle_post(&ennemy[i]);
        pos_ennemy.x += 2;
        pos_ennemy.y += 2;
    }
    return ennemy;
}

static ennemy_t *init_type_boss(init_ennemy_t const *ennemy_fix, int life)
{
    ennemy_t *ennemy = malloc(sizeof(ennemy_t) * 1);
    sfVector2f pos_ennemy = ennemy_fix->post;

    ennemy[0].texture = sfTexture_createFromFile(ennemy_fix->texture, NULL);
    ennemy[0].sprite = sfSprite_create();
    sfSprite_setTexture(ennemy[0].sprite, ennemy[0].texture, sfTrue);
    sfSprite_setScale(ennemy[0].sprite, ennemy_fix->size);
    sfSprite_setPosition(ennemy[0].sprite, pos_ennemy);
    sfSprite_setTextureRect(ennemy[0].sprite, ennemy_fix->rect);
    init_values(&ennemy[0], life, pos_ennemy, ennemy_fix->rect);
    ennemy[0].damage = 40;
    ennemy[0].circle = init_circle_post(&ennemy[0]);
    pos_ennemy.x += 2;
    pos_ennemy.y += 2;
    return ennemy;
}

type_ennemy_t create_type_ennemy(void)
{
    type_ennemy_t type_ennemy;

    type_ennemy.type_1 = init_type_ennemy(&ennemy_fix[0], 35);
    type_ennemy.type_2 = init_type_ennemy(&ennemy_fix[1], 50);
    type_ennemy.type_3 = init_type_boss(&ennemy_fix[2], 500);
    return type_ennemy;
}

impact_t create_struct_impact(void)
{
    impact_t impact;

    impact.tmp = 0;
    impact.mouv = 0;
    return impact;
}