/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-2-myrpg-laetitia.bousch
** File description:
** boss
*/

#include "my_rpg.h"

void boss(scene_t *scene, game_set *setting, ennemy_t *type)
{
    for (int i = 0; i < 1; i++) {
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