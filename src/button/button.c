/*
** EPITECH PROJECT, 2021
** button.c
** File description:
** button.c
*/

#include "my_rpg.h"

void display_menu_button(game_button button, game_set *setting, scene_t *scene)
{
    sfVector2i pos_mouse = sfMouse_getPositionRenderWindow(setting->wndw);

    if (button_is_select(button, pos_mouse) == 1 &&
        setting->buttonpress == 1) {
        sfRectangleShape_setFillColor(button.rect, sfGreen);
        button.callback(setting, scene);
        setting->buttonpress = 0;
    }
    else if (button_is_select(button, pos_mouse) == 1)
        sfRectangleShape_setFillColor(button.rect, button.color);
    else
        sfRectangleShape_setFillColor(button.rect, sfWhite);
    sfRenderWindow_drawRectangleShape(setting->wndw, button.rect, NULL);
}

int button_is_select(game_button button, sfVector2i click_position)
{
    int width = button.pos.x + button.size.x;
    int heigth = button.pos.y + button.size.y;

    if (click_position.x >= button.pos.x && click_position.x <= width
        && click_position.y >= button.pos.y && click_position.y <= heigth)
        return (1);
    return (0);
}
