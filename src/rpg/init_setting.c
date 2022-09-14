/*
** EPITECH PROJECT, 2021
** init_setting
** File description:
** setting
*/

#include "my_rpg.h"

game_set *init_setting(void)
{
    game_set *setting = malloc(sizeof(game_set));

    create_wndw(1920, 1080, "my_rpg", setting);
    menu_music(setting, "sprite/[One Piece]The_Fight_Continues.ogg");
    setting->sound = create_entity_sound();
    setting->pixelbuff = pixelbuffer_create(1920, 1080);
    setting->time = init_time();
    setting->state = 1;
    setting->option = 0;
    setting->buttonpress = 0;
    setting->is_pressed = 0;
    setting->inventory = 0;

    return setting;
}