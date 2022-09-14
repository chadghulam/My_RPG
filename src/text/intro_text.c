/*
** EPITECH PROJECT, 2021
** CH
** File description:
** GH
*/

#include "my_rpg.h"

void intro_text(game_set *setting, scene_t *scene)
{
    char *str = 0;
    sfSprite *sprite = 0;
    sfText *text = 0;

    sfText_setString(text, str);
    sfRenderWindow_drawText(setting->wndw, text, NULL);
    sfRenderWindow_drawSprite(setting->wndw, sprite, NULL);
}