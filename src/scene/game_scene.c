/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** game scene
*/

#include "my_rpg.h"

static void action_map(game_set *setting, scene_t *scene)
{
    if (scene->map->i == 0) {
        quests_finish(scene->type_pnj);
        pnj(scene->obj[13], scene->type_pnj, setting, scene->obj[7]);
    }
    if (scene->map->i == 1) {
        ennemy(scene, setting, scene->type_ennemy.type_1);
        status_map_ennemy(scene->type_ennemy.type_1, scene->type_pnj.type_2);
    }
    if (scene->map->i == 2) {
        ennemy(scene, setting, scene->type_ennemy.type_2);
        status_map_ennemy(scene->type_ennemy.type_2, scene->type_pnj.type_3);
    }
    if (scene->map->i == 3) {
        boss(scene, setting, scene->type_ennemy.type_3);
    }
}

void draw_game(game_set *setting, scene_t *scene)
{
    sfRenderWindow_clear(setting->wndw, sfBlack);
    move_view(setting, scene->obj[13]);
    init_map(setting->wndw, scene);
    if (setting->is_pressed == 1)
        draw_stats(setting, scene);
    if (setting->is_pressed == 2)
        draw_inventory(setting, scene);
    if (setting->option == 1 || setting->is_pressed > 0)
        return ;
    action_map(setting, scene);
    player(scene->obj[13], setting, scene->map, scene);
    recup_item(scene, setting);
    score(setting, scene);
    hud_view(setting, scene);
}

void draw_option(game_set *setting, scene_t *scene)
{
    sfRenderWindow_setView(setting->wndw,
    ((game_view *)scene->obj[1]->stats)->view);
    sfRenderWindow_drawSprite(setting->wndw, scene->obj[1]->sprite, NULL);
    display_menu_button(scene->button[2], setting, scene);
    for (int i = 4; i < 9; i++)
        display_menu_button(scene->button[i], setting, scene);
}

void draw_help(game_set *setting, scene_t *scene)
{
    sfRenderWindow_drawSprite(setting->wndw, scene->obj[2]->sprite, NULL);
    display_menu_button(scene->button[3], setting, scene);
}

void draw_stats(game_set *setting, scene_t *scene)
{
    game_obj *player = scene->obj[13];
    int speed = ((game_player *) player->stats)->speed;
    int damage = ((game_player *) player->stats)->damage;
    int armor = ((game_player *) player->stats)->armor;

    sfRenderWindow_drawSprite(setting->wndw, scene->obj[9]->sprite, NULL);
    draw_speed(scene->text[6], setting, speed);
    draw_damage(scene->text[8], setting, damage);
    draw_armor(scene->text[7], setting, armor);
}