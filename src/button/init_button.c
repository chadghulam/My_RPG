/*
** EPITECH PROJECT, 2021
** init button
** File description:
** init
*/

#include "my_rpg.h"

game_button *create_entity_button(void)
{
    game_button *entity_btn = malloc(sizeof(game_button) * 10);

    for (int i = 0; i < 10; i++)
        entity_btn[i] = init_button(btn_fix[i]);
    return entity_btn;
}

game_button init_button(game_button button)
{
    sfTexture *texture = sfTexture_createFromFile(button.ps, NULL);

    button.rect = sfRectangleShape_create();
    sfRectangleShape_setTexture(button.rect, texture, sfTrue);
    sfRectangleShape_setPosition(button.rect, button.pos);
    sfRectangleShape_setSize(button.rect, button.size);
    return button;
}