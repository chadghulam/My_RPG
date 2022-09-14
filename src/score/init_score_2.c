/*
** EPITECH PROJECT, 2021
** init_score 2
** File description:
** init_score_2.c
*/

#include "my_rpg.h"

void draw_armor(game_text text, game_set *setting, int armor)
{
    if (setting->state == 2) {
        sfText_setString(text.text, my_nbrtostr(armor));
        sfRenderWindow_drawText(setting->wndw, text.text, NULL);
    }
    if (setting->state == 1)
        armor = 5;
}