/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** scene.c
*/

#include "my_rpg.h"

scene_t *init_scene(void)
{
    scene_t *scene = malloc(sizeof(scene_t));

    if (scene == NULL)
        return (NULL);
    scene->button = create_entity_button();
    scene->type_ennemy = create_type_ennemy();
    scene->type_pnj = create_type_pnj();
    scene->impact = create_struct_impact();
    scene->obj = create_entity_object();
    scene->text = create_entity_text();
    scene->map = create_map((char *[])
    {"map/map0.txt", "map/map1.txt", "map/map2.txt", "map/map3.txt", NULL});
    scene->direction_player = 0;
    init_player(scene->obj[13],
    (game_player) {100, 112, 10, 0, 1, 1, 1, 5, {0, 0, 0, 0}, 0});
    init_view(scene->obj);
    scene->action = DAMAGE;
    return (scene);
}

void score(game_set *setting, scene_t *scene)
{
    game_obj *player = scene->obj[13];
    int life = ((game_player *) player->stats)->life;
    int lvl = ((game_player *) player->stats)->level;

    draw_life(scene->text[3], scene->obj[10], setting, life);
    draw_lvl(scene->text[1], scene->obj[8], setting, lvl);
}

static void display_scene_bis(game_set *setting, scene_t *scene)
{
    if (setting->state == 3)
        draw_help(setting, scene);
    if (setting->state == 4)
        draw_lose(setting, scene);
    if (setting->state == 5)
        draw_win(setting, scene);
    if (setting->option == 1)
        draw_option(setting, scene);
}

void display_scene(game_set *setting, scene_t *scene)
{
    if (sfKeyboard_isKeyPressed(sfKeyDelete) == sfTrue)
        closing(setting, scene);
    if (setting->state == 1)
        menu(setting, scene);
    if (setting->state == 2)
        draw_game(setting, scene);
    display_scene_bis(setting, scene);
}