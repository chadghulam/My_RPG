/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-2-myrpg-laetitia.bousch
** File description:
** pnj
*/

#include "my_rpg.h"

static void display_pnj(type_pnj_t type_pnj, game_set *setting)
{
    sfRenderWindow_drawSprite(setting->wndw, type_pnj.type_1->sprite, NULL);
    sfRenderWindow_drawSprite(setting->wndw, type_pnj.type_2->sprite, NULL);
    sfRenderWindow_drawSprite(setting->wndw, type_pnj.type_3->sprite, NULL);
}

static void funct_texte(type_pnj_t *type_pnj, game_set *setting,
                        game_obj *player, game_obj *menu)
{
    (void) player;
    if (type_pnj->type_1->status == sfTrue) {
        sfSprite_setPosition(menu->sprite, type_pnj->type_1->pos_menu);
        sfRenderWindow_drawSprite(setting->wndw, menu->sprite, NULL);
        sfRenderWindow_drawText(setting->wndw, type_pnj->type_1->quests, NULL);
    }
    if (type_pnj->type_2->status == sfTrue) {
        sfSprite_setPosition(menu->sprite, type_pnj->type_2->pos_menu);
        sfRenderWindow_drawSprite(setting->wndw, menu->sprite, NULL);
        sfRenderWindow_drawText(setting->wndw, type_pnj->type_2->quests, NULL);
    }
    if (type_pnj->type_3->status == sfTrue) {
        sfSprite_setPosition(menu->sprite, type_pnj->type_3->pos_menu);
        sfRenderWindow_drawSprite(setting->wndw, menu->sprite, NULL);
        sfRenderWindow_drawText(setting->wndw, type_pnj->type_3->quests, NULL);
    }
}

void pnj(game_obj *player, type_pnj_t type_pnj, game_set *setting,
        game_obj *menu)
{
    (void) player;
    if (type_pnj.type_1->status == sfFalse &&
        type_pnj.type_1->quete == PROGRESS) {
        move_pnj(type_pnj.type_1, setting);
    }
    display_pnj(type_pnj, setting);
    funct_texte(&type_pnj, setting, player, menu);
}