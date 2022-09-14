/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-2-myrpg-laetitia.bousch
** File description:
** display_player
*/

#include "my_rpg.h"

void display_player(game_obj *player, sfVector2f pos_last,
                game_time *time, scene_t *scene)
{
    if (scene->action == DAMAGE) {
            sfSprite_setPosition(player->sprite, player->pos);
    } else if (scene->action != DAMAGE) {
        event_player(player, time, scene);
        if (scene->action == ATTACK) {
            pos_last.x -= 10;
            pos_last.y -= 10;
            sfSprite_setPosition(player->sprite, pos_last);
        } else {
            sfSprite_setPosition(player->sprite, player->pos);
        }
    }
}