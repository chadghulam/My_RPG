/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-2-myrpg-laetitia.bousch
** File description:
** move_pnj
*/

#include "my_rpg.h"

static void direction_pnj_one(game_pnj_t *pnj)
{
    if (pnj->rect.top <= 96) {
        pnj->rect.left = 32;
        pnj->rect.top += 16;
    } else {
        pnj->rect.top = 0;
    }
    pnj->pos.x -= 5;
}

static void direction_pnj_two(game_pnj_t *pnj)
{
    if (pnj->rect.top <= 96) {
        pnj->rect.left = 16;
        pnj->rect.top += 16;
    } else {
        pnj->rect.top = 0;
    }
    pnj->pos.y -= 5;
}

static void direction_pnj_three(game_pnj_t *pnj)
{
    if (pnj->rect.top <= 96) {
        pnj->rect.left = 48;
        pnj->rect.top += 16;
    } else {
        pnj->rect.top = 0;
    }
    pnj->pos.x += 5;
}

static void display_pnj(game_pnj_t *pnj, int i)
{
    sfSprite_setTextureRect(pnj->sprite, pnj->rect);
    sfSprite_setPosition(pnj->sprite, pnj->pos);
    if (i == 1) {
        direction_pnj_one(pnj);
    }
    if (i == 2) {
        direction_pnj_two(pnj);
    }
    if (i == 3) {
        direction_pnj_three(pnj);
    }
}

void move_pnj(game_pnj_t *pnj, game_set *setting)
{
    if (setting->time->time - setting->time->temp_pnj > 1.0) {
        if (pnj->pos.x >= 885 && pnj->pos.y == 570) {
            display_pnj(pnj, 1);
        } else if (pnj->pos.x == 880 && pnj->pos.y >= 465) {
            display_pnj(pnj, 2);
        } else if (pnj->pos.x <= 935 && pnj->pos.y == 460) {
            display_pnj(pnj, 3);
        } else if (pnj->pos.x >= 940 && pnj->pos.y == 460) {
            pnj->rect.top = 0;
            pnj->rect.left = 0;
            sfSprite_setTextureRect(pnj->sprite, pnj->rect);
        }
    }
}