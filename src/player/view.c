/*
** EPITECH PROJECT, 2021
** view.c
** File description:
** view
*/

#include "my_rpg.h"

void hud_view(game_set *setting, scene_t *scene)
{
    (void) setting;
    sfVector2f pos = {scene->obj[13]->pos.x, scene->obj[13]->pos.y - 215};
    sfVector2f pos_text_life = {pos.x + 275, pos.y + 7};
    sfVector2f pos_sprite_life = {pos.x + 240, pos.y + 15};
    sfVector2f pos_text_lvl = {pos.x - 290, pos.y + 370};
    sfVector2f pos_sprite_lvl = {pos.x - 360, pos.y + 375};
    sfVector2f pos_sprite_stats = {pos.x - 230, pos.y + 80};
    sfVector2f pos_text_speed = {pos.x - 50, pos.y + 204};
    sfVector2f pos_text_damage = {pos.x - 50, pos.y + 142};
    sfVector2f pos_text_armor = {pos.x + 45, pos.y + 142};

    sfSprite_setPosition(scene->obj[8]->sprite, pos_sprite_lvl);
    sfText_setPosition(scene->text[1].text, pos_text_lvl);
    sfSprite_setPosition(scene->obj[10]->sprite, pos_sprite_life);
    sfText_setPosition(scene->text[3].text, pos_text_life);
    sfSprite_setPosition(scene->obj[9]->sprite, pos_sprite_stats);
    sfText_setPosition(scene->text[6].text, pos_text_speed);
    sfText_setPosition(scene->text[7].text, pos_text_armor);
    sfText_setPosition(scene->text[8].text, pos_text_damage);
}

void move_view(game_set *setting, game_obj *player)
{
    sfVector2f center = {player->pos.x, player->pos.y};

    sfView_setCenter(((game_player *) player->stats)->view, center);
    sfRenderWindow_setView(setting->wndw,
    ((game_player *) player->stats)->view);
}

void init_view(game_obj **obj)
{
    static game_view view = {0, {0, 0, 1920, 1080}};
    sfFloatRect rectangle = {0, 0, 755, 425};
    int count[] = {1, 11, 12, 15, 0};

    ((game_player *)obj[13]->stats)->view = sfView_createFromRect(rectangle);
    for (int i = 0; count[i] != 0; i++) {
        obj[count[i]]->stats = &view;
        ((game_view *)obj[1]->stats)->view = sfView_createFromRect(view.rect);
    }
}