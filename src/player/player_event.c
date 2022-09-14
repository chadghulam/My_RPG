/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-2-myrpg-laetitia.bousch
** File description:
** player_event
*/

#include "my_rpg.h"

static void event_redirection_defense(game_obj *player,
                        game_time *time, scene_t *scene)
{
    (void) time;
    if (scene->direction_player > 0) {
        if (scene->direction_player == 1) {
            player->rect.top = 113;
        }
        if (scene->direction_player == 2) {
            player->rect.top = 128;
        }
        if (scene->direction_player == 3) {
            player->rect.top = 144;
        }
    }
}

void event_defense(game_obj *player, game_time *time, scene_t *scene)
{
    if (player->rect.top < 95) {
        player->rect.left = 190;
    }
    if (player->rect.left < 270) {
        player->rect.top = 95;
        event_redirection_defense(player, time, scene);
        player->rect.left += 17;
        sfSprite_setTextureRect(player->sprite, player->rect);
        time->temp_player = 0;
    } else {
        scene->action = DAMAGE;
        player->rect = ((game_player *) player->stats)->rect_last;
        sfSprite_setTextureRect(player->sprite, player->rect);
    }
}

static void event_redirection_attack(game_obj *player,
game_time *time, scene_t *scene)
{
    (void) time;
    if (scene->direction_player > 0) {
        if (scene->direction_player == 1) {
            player->rect.top = 280;
        }
        if (scene->direction_player == 2) {
            player->rect.top = 330;
        }
        if (scene->direction_player == 3) {
            player->rect.top = 240;
        }
    }
}

void event_attack(game_obj *player, game_time *time, scene_t *scene)
{
    if (player->rect.top < 200) {
        player->rect.left = 0;
    }
    if (player->rect.left < 310) {
        player->rect.top = 200;
        event_redirection_attack(player, time, scene);
        player->rect.left += 50;
        player->rect.height = 40;
        player->rect.width = 48;
        sfSprite_setTextureRect(player->sprite, player->rect);
        time->temp_player = 0;
    } else {
        player->rect = ((game_player *) player->stats)->rect_last;
        scene->action = DAMAGE;
        sfSprite_setTextureRect(player->sprite, player->rect);
    }
}

void event_player(game_obj *player, game_time *time, scene_t *scene)
{
    int speed = ((game_player *) player->stats)->speed;

    if (time->temp_player > 10/speed) {
        if (scene->action == ATTACK) {
            event_attack(player, time, scene);
        } else if (scene->action == DEFENSE) {
            event_defense(player, time, scene);
        }
    } else {
        time->temp_player += time->delta;
    }
}