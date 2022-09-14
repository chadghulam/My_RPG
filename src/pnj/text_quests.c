/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-2-myrpg-laetitia.bousch
** File description:
** text_quests
*/

#include "my_rpg.h"
static void display_texte(char *text, game_pnj_t *pnj, sfRenderWindow *wndw)
{
    (void) wndw;
    sfFont *Texture = sfFont_createFromFile("sprite/game_over.ttf");

    pnj->quests = sfText_create();
    pnj->status = sfTrue;
    sfText_setString(pnj->quests, text);
    sfText_setFont(pnj->quests, Texture);
    sfText_setScale(pnj->quests, (sfVector2f){0.5, 0.5});
    sfText_setPosition(pnj->quests, pnj->pos_texte);
}

static void global_quete(game_pnj_t *pnj, game_set *setting)
{
    if (pnj->quete == QUETE) {
        if (pnj->status == sfFalse) {
            display_texte(pnj->texte[0], pnj, setting->wndw);
        }
    }
    else if (pnj->quete == PROGRESS) {
        if (pnj->status == sfFalse) {
            display_texte(pnj->texte[1], pnj, setting->wndw);
        }
    }
    else if (pnj->quete == FINISH) {
        if (pnj->status == sfFalse) {
            display_texte(pnj->texte[2], pnj, setting->wndw);
        }
    }
}

void texte_quete(game_pnj_t *pnj, game_set *setting, game_obj *player)
{
    if ((pnj->pos.x > player->pos.x - 10 && pnj->pos.x < player->pos.x + 10) &&
        (pnj->pos.y > player->pos.y - 10 && pnj->pos.y < player->pos.y + 10)) {
        global_quete(pnj, setting);
    } else {
        if (pnj->status == sfTrue && pnj->quete == QUETE) {
            pnj->quete = PROGRESS;
        }
        pnj->status = sfFalse;
    }
}