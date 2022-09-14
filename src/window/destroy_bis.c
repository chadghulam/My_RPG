/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-2-myrpg-laetitia.bousch
** File description:
** destroy_bis
*/

#include "my_rpg.h"

void destroy_ennemy(type_ennemy_t *type_ennemy)
{
    for (int i = 0; i < 10; i++) {
        sfSprite_destroy(type_ennemy->type_1[i].sprite);
        sfSprite_destroy(type_ennemy->type_2[i].sprite);
        sfTexture_destroy(type_ennemy->type_1[i].texture);
        sfTexture_destroy(type_ennemy->type_2[i].texture);
        sfSprite_destroy(type_ennemy->type_1[i].circle.sprite);
        sfSprite_destroy(type_ennemy->type_2[i].circle.sprite);
        sfTexture_destroy(type_ennemy->type_1[i].circle.texture);
        sfTexture_destroy(type_ennemy->type_2[i].circle.texture);
    }
    sfSprite_destroy(type_ennemy->type_3[0].sprite);
    sfTexture_destroy(type_ennemy->type_3[0].texture);
    sfSprite_destroy(type_ennemy->type_3[0].circle.sprite);
    sfTexture_destroy(type_ennemy->type_3[0].circle.texture);
    free(type_ennemy->type_1);
    free(type_ennemy->type_2);
    free(type_ennemy->type_3);
}

void destroy_setting(game_set *setting)
{
    sfMusic_destroy(setting->music);
    sfRenderWindow_destroy(setting->wndw);
    sfClock_destroy(setting->time->clock);
    for (int i = 0; i < 9; i++) {
        sfSound_destroy(setting->sound[i].sound);
        sfSoundBuffer_destroy(setting->sound[i].soundbuffer);
    }
    free(setting->time);
}

void destroy_pnj(type_pnj_t *type_pnj)
{
    sfSprite_destroy(type_pnj->type_1->sprite);
    sfSprite_destroy(type_pnj->type_2->sprite);
    sfSprite_destroy(type_pnj->type_3->sprite);
    sfTexture_destroy(type_pnj->type_1->texture);
    sfTexture_destroy(type_pnj->type_2->texture);
    sfTexture_destroy(type_pnj->type_3->texture);
    for (int i = 0; i < 3; i++) {
        free(type_pnj->type_1->texte[i]);
        free(type_pnj->type_2->texte[i]);
        free(type_pnj->type_3->texte[i]);
    }
    free(type_pnj->type_1->texte);
    free(type_pnj->type_2->texte);
    free(type_pnj->type_3->texte);
    free(type_pnj->type_1);
    free(type_pnj->type_2);
    free(type_pnj->type_3);
}