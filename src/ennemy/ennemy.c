/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-2-myrpg-laetitia.bousch
** File description:
** ennemy
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <SFML/Audio.h>

#include "my_rpg.h"

void impact_game(ennemy_t *type, game_obj *player,
                impact_t *impact, int i)
{
    impact->player_post = sfSprite_getGlobalBounds(player->sprite);
    impact->circle_post = sfSprite_getGlobalBounds( type[i].circle.sprite);
    impact->ennemy_post = sfSprite_getGlobalBounds(type[i].sprite);
    impact->inter = sfFloatRect_intersects(&impact->player_post,
    &impact->circle_post, NULL);
    impact->fight = sfFloatRect_intersects(&impact->player_post,
    &impact->ennemy_post, NULL);
}

void zone_ennemy(scene_t *scene, game_set *setting,
                int i, ennemy_t *type)
{
    if (scene->impact.inter == sfTrue && (type[i].post_rand_x !=
    scene->obj[13]->pos.x && type[i].post_rand_y != scene->obj[13]->pos.y)) {
        type[i].post_rand_x = scene->obj[13]->pos.x;
        type[i].post_rand_y = scene->obj[13]->pos.y;
    }
    if (scene->impact.fight == sfTrue) {
        if (scene->action == DAMAGE) {
            damage_ennemy(scene, setting, &type[i]);
            sfSound_play(setting->sound[7].sound);
        }
        if (scene->action == ATTACK) {
            attack_ennemy(scene, setting, &type[i]);
            sfSound_play(setting->sound[5].sound);
            sfSound_play(setting->sound[6].sound);
        }
        if (scene->action == DEFENSE) {
            bouclier_ennemy(scene, setting, &type[i]);
            sfSound_play(setting->sound[8].sound);
        }
    }
}

void display_ennemy(ennemy_t *type, int i, game_set *setting)
{
    sfSprite_setTextureRect(type[i].sprite, type[i].rect);
    sfSprite_setPosition(type[i].circle.sprite,
                        type[i].circle.post);
    sfSprite_setPosition(type[i].sprite, type[i].post);
    sfRenderWindow_drawSprite(setting->wndw,
                        type[i].sprite, NULL);
}

void game_fight(ennemy_t *type, int i, scene_t *scene,
                        game_set *setting)
{
    if (type[i].direction == 1) {
        if (type[i].rect.left < 80 || type[i].rect.left >= 160) {
            type[i].rect.left = 80;
        } else if (type[i].rect.left < 160) {
            type[i].rect.left += 16;
        }
    } else {
        if (type[i].rect.left >= 80) {
            type[i].rect.left = 0;
        } else if (type[i].rect.left < 80) {
            type[i].rect.left += 16;
        }
    }
    display_ennemy(type, i, setting);
    scene->impact.inter = sfFalse;
    scene->impact.fight = sfFalse;
}

void ennemy(scene_t *scene, game_set *setting, ennemy_t *type)
{
    for (int i = 0; i < 10; i++) {
        impact_game(type, scene->obj[13], &scene->impact, i);
        if (setting->time->time - setting->time->temp_ennemy > 1.0) {
            if (type[i].life > 0) {
                zone_ennemy(scene, setting, i, type);
                mouv_ennemy(i, type);
                game_fight(type, i, scene, setting);
            } else if (type[i].dead != 0) {
                type[i].rect.top = 32;
                if (type[i].rect.left >= 128) {
                    type[i].dead = 0;
                } else if (type[i].rect.left < 128) {
                    type[i].rect.left += 16;
                }
                display_ennemy(type, i, setting);
            }
        }
    }
}