/*
** EPITECH PROJECT, 2021
** leveling.c
** File description:
** all xp and levels related stuff
*/

#include "my_rpg.h"

void power_up(game_obj *player)
{
    ((game_player *) player->stats)->life += 5;
    ((game_player *) player->stats)->damage += 1;
    ((game_player *) player->stats)->armor += 1;
    ((game_player *) player->stats)->speed += 5;
}

void level_up(game_obj *player)
{
    int lvl = ((game_player *) player->stats)->level;
    int xp = ((game_player *) player->stats)->xp;

    if (sfKeyboard_isKeyPressed(sfKeyEnter) == sfTrue) {
        if (xp < 100 && lvl < 100)
            xp += 5;
    }
    if (xp >= 100 && lvl < 100) {
        xp = xp - 100;
        lvl += 1;
        power_up(player);
    }
    ((game_player *) player->stats)->xp = xp;
    ((game_player *) player->stats)->level = lvl;
}