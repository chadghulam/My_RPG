/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-2-myrpg-laetitia.bousch
** File description:
** init_pnj
*/

#include "my_rpg.h"

static void post_menu_and_texte(game_pnj_t *pnj)
{
    pnj->pos_menu.y = pnj->pos.y + 50;
    pnj->pos_menu.x = pnj->pos.x - 20;
    pnj->pos_texte.x = pnj->pos_menu.x + 5;
    pnj->pos_texte.y = pnj->pos_menu.y + 10;
}

game_pnj_t *init_type_pnj_pr(init_pnj_t const *pnj_fix,
                            const char **text)
{
    game_pnj_t *pnj = malloc(sizeof(game_pnj_t) * 1);
    int i = 0;

    pnj->texture = sfTexture_createFromFile(pnj_fix->texture, NULL);
    pnj->sprite = sfSprite_create();
    sfSprite_setTexture(pnj->sprite, pnj->texture, sfTrue);
    sfSprite_setScale(pnj->sprite, pnj_fix->size);
    sfSprite_setPosition(pnj->sprite, pnj_fix->pos);
    sfSprite_setTextureRect(pnj->sprite, pnj_fix->rect);
    pnj->pos = pnj_fix->pos;
    pnj->quete = QUETE;
    pnj->rect = pnj_fix->rect;
    pnj->status = sfFalse;
    post_menu_and_texte(pnj);
    pnj->texte = malloc(sizeof(char *) * 4);
    for (; i < 3; i++) {
        pnj->texte[i] = my_strdup(text[i]);
    }
    pnj->texte[i] = NULL;
    return pnj;
}