/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-2-myrpg-laetitia.bousch
** File description:
** quests
*/

#include "my_rpg.h"

void quests_finish(type_pnj_t type_pnj)
{
    if (type_pnj.type_3->quete == FINISH && type_pnj.type_2->quete == FINISH) {
        type_pnj.type_1->quete = FINISH;
    }
}

void status_map_ennemy(ennemy_t *ennemy, game_pnj_t *pnj)
{
    int compt = 0;

    for (int i = 0; i < 10; i++) {
        if (ennemy[i].life <= 0) {
            compt++;
        }
    }
    if (compt >= 10) {
        pnj->quete = FINISH;
    }
}