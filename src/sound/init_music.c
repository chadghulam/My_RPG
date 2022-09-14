/*
** EPITECH PROJECT, 2021
** music
** File description:
** music
*/

#include "my_rpg.h"

void menu_music(game_set *setting, char *ps)
{
    setting->music = sfMusic_createFromFile(ps);

    if (!setting->music)
        return;
    sfMusic_play(setting->music);
    sfMusic_setLoop(setting->music, sfTrue);
}