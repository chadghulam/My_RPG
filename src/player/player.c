/*
** EPITECH PROJECT, 2021
** player
** File description:
** player
*/

#include "my_rpg.h"

static void stade_event(game_obj *player, game_time *time,
                        int direction, scene_t *scene)
{
    (void) scene;
    if (scene->action == DAMAGE) {
        player->rect.top = 16 * direction;
        player->rect.left += 16;
        if (player->rect.left == 16*6)
            player->rect.left = 16;
        sfSprite_setTextureRect(player->sprite, player->rect);
        player->rect.height = 16;
        player->rect.width = 16;
    } else {
        if (scene->action == ATTACK) {
            event_attack(player, time, scene);
        } else {
            event_defense(player, time, scene);
        }
    }
    time->temp_player = 0;
}

static void animation_player(game_obj *player, game_time *time,
                        int direction, scene_t *scene)
{
    int speed = ((game_player *) player->stats)->speed;

    if (time->temp_player > 10/speed) {
        stade_event(player, time, direction, scene);
    }
    else
        time->temp_player += time->delta;
}

static int post_animation(scene_t *scene, sfVector2f pos_last,
                        int tmp, game_obj *player)
{
    if (scene->action != DAMAGE && tmp == 0) {
        pos_last = player->pos;
        tmp++;
    }
    (void) pos_last;
    return tmp;
}

static void move_player(game_obj *player, game_time *time,
                        game_map *map, scene_t *scene)
{
    int speed = ((game_player *) player->stats)->speed;
    sfKeyCode key[] = {sfKeyDown, sfKeyLeft, sfKeyRight, sfKeyUp};
    sfVector2f pos[] = {{0, speed}, {-speed, 0}, {speed, 0}, {0, -speed}};
    sfVector2f pos_last = player->pos;
    int tmp = 0;

    for (int i = 0; i < 4; i++) {
        if (sfKeyboard_isKeyPressed(key[i]) == sfTrue &&
        collision_player(map, player, time->delta, pos[i]) == 0) {
            player->pos.x += pos[i].x * time->delta;
            player->pos.y += pos[i].y * time->delta;
            scene->direction_player = i;
            animation_player(player, time, i + 1, scene);
            if (scene->action == DAMAGE) {
                ((game_player *)player->stats)->rect_last = player->rect;
            }
        }
        tmp = post_animation(scene, pos_last, tmp, player);
    }
    display_player(player, pos_last, time, scene);
}

void player(game_obj *player, game_set *setting, game_map *map, scene_t *scene)
{
    move_player(player, setting->time, map, scene);
    level_up(player);
    sfRenderWindow_drawSprite(setting->wndw, player->sprite, NULL);
}