/*
** EPITECH PROJECT, 2021
** inventory
** File description:
** init inventory
*/

#include "my_rpg.h"

void draw_inventory(game_set *setting, scene_t *scene)
{
    sfRenderWindow_setView(setting->wndw,
    ((game_view *) scene->obj[15]->stats)->view);
    sfRenderWindow_drawSprite(setting->wndw, scene->obj[15]->sprite, NULL);
    display_menu_button(scene->button[9], setting, scene);
    draw_weapon(setting, scene);
}

void draw_weapon(game_set *setting, scene_t *scene)
{
    sfSprite_setScale(scene->obj[16]->sprite, (sfVector2f){2.6, 2.6});
    for (int i = 0; i <
    ((game_player *)scene->obj[13]->stats)->state -setting->inventory; i++)
        for (int j = 0; j < 3; j++) {
            scene->obj[16]->rect = (sfIntRect) {37*i, 37*j, 37, 37};
            scene->obj[16]->pos = (sfVector2f) {610 + j*145, 320 + i*150};
            sfSprite_setPosition(scene->obj[16]->sprite, scene->obj[16]->pos);
            sfSprite_setTextureRect(scene->obj[16]->sprite,
            scene->obj[16]->rect);
            sfRenderWindow_drawSprite(setting->wndw,
                                        scene->obj[16]->sprite, 0);
        }
}

void delet(game_set *setting, scene_t *scene)
{
    setting->inventory++;
    if (setting->inventory < 0)
        setting->inventory = 0;
    ((game_player *) scene->obj[13]->stats)->life -= 2 * 10;
    ((game_player *) scene->obj[13]->stats)->damage -= 2 * 10;
    ((game_player *) scene->obj[13]->stats)->speed -= 10 * 10;
}

void drop_item(scene_t *scene, game_set *setting, int quete1, int quete2)
{
    if (scene->type_pnj.type_2->quete == FINISH && quete1 == 0) {
        dop_item_quests_one(scene, setting);
    }
    if (scene->type_pnj.type_3->quete == FINISH && quete2 == 0) {
        dop_item_quests_two(scene, setting);
    }
}

void recup_item(scene_t *scene, game_set *setting)
{
    static int quete1 = 0;
    static int quete2 = 0;

    sfSprite_setScale(scene->obj[16]->sprite, (sfVector2f){0.8, 0.8});
    drop_item(scene, setting, quete1, quete2);
    if (scene->type_pnj.type_2->quete == FINISH && quete1 == 0 &&
    scene->obj[13]->pos.x > 940 && scene->obj[13]->pos.x < 980
    && scene->obj[13]->pos.y > 540 && scene->obj[13]->pos.y < 580)
        quete1 = equip_item(scene);
    if (scene->type_pnj.type_3->quete == FINISH && quete2 == 0 &&
    scene->obj[13]->pos.x > 940 && scene->obj[13]->pos.x < 980 &&
    scene->obj[13]->pos.y > 540 && scene->obj[13]->pos.y < 580)
        quete2 = equip_item(scene);
    if (scene->type_pnj.type_1->quete == FINISH &&
        scene->type_ennemy.type_3->life <= 0)
        setting->state = 5;
}