/*
** EPITECH PROJECT, 2021
** text
** File description:
** text
*/

#include "my_rpg.h"

game_text *create_entity_text(void)
{
    game_text *entity_text = malloc(sizeof(game_text) * 10);

    for (int i = 0; i < 10; i++) {
        entity_text[i] = create_text(txt_fix[i]);
    }
    return entity_text;
}

game_text create_text(game_text text)
{
    sfFont *font = sfFont_createFromFile(text.fontps);

    text.text = sfText_create();
    sfText_setFont(text.text, font);
    sfText_setString(text.text, text.textps);
    sfText_setScale(text.text, text.scale);
    sfText_setPosition(text.text, text.pos);
    return text;
}