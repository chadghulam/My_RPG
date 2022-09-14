/*
** EPITECH PROJECT, 2021
** end game
** File description:
** end
*/

#include "my_rpg.h"

void draw_lose(game_set *setting, scene_t *scene)
{
    sfRenderWindow_setView(setting->wndw,
    ((game_view *)scene->obj[11]->stats)->view);
    sfRenderWindow_clear(setting->wndw, sfBlack);
    sfRenderWindow_drawSprite(setting->wndw, scene->obj[11]->sprite, NULL);
    sfRenderWindow_drawText(setting->wndw, scene->text[4].text, NULL);
    display_menu_button(scene->button[2], setting, scene);
}

void draw_win(game_set *setting, scene_t *scene)
{
    sfRenderWindow_setView(setting->wndw,
    ((game_view *)scene->obj[12]->stats)->view);
    sfRenderWindow_clear(setting->wndw, sfBlack);
    sfRenderWindow_drawSprite(setting->wndw, scene->obj[12]->sprite, NULL);
    sfRenderWindow_drawText(setting->wndw, scene->text[5].text, NULL);
    display_menu_button(scene->button[2], setting, scene);
}