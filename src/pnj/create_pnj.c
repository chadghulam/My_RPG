/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-2-myrpg-laetitia.bousch
** File description:
** create_pnj
*/

#include "my_rpg.h"

static const char *quete_pnj_1[] = {
    "Ezreal’s sword is in the right sector.\n"
    "You have to kill all the vahia\n"
    "minions for it to appear.",
    "What ?! You still haven’t managed to recover\n"
    "Ezreal’s weapons ?",
    "You found it !",
    NULL
};

static const char *quete_pnj_2[] = {
    "Ezreal’s shield is in the left sector.\n"
    "You must kill all Vahia minions\n"
    "for it to appear",
    "Where is it ? Leave now or the\n"
    "village will disappear !",
    "You found it !",
    NULL
};

static const char *quete_pnj_3[] = {
    "You must save the village ! It was stormed by the Vahia\n"
    "demon. To defeat him, you must recover the\n"
    "sword and shield created by the angel Ezreal.\n"
    "Only the wise know where these relics\n"
    "are located.",
    "How do you want to fight Vahia\n"
    "without the two relics ?",
    "Good luck ! Vahia is at the top.\n"
    "You are our last chance !!",
    NULL
};

type_pnj_t create_type_pnj(void)
{
    type_pnj_t type_pnj;

    type_pnj.type_1 = init_type_pnj_pr(&pnj_fix[0], quete_pnj_3);
    type_pnj.type_2 = init_type_pnj_pr(&pnj_fix[1], quete_pnj_2);
    type_pnj.type_3 = init_type_pnj_pr(&pnj_fix[2], quete_pnj_1);
    return type_pnj;
}