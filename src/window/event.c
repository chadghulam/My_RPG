/*
** EPITECH PROJECT, 2021
** event
** File description:
** event
*/

#include "my_rpg.h"

static void game_event_four(game_set *setting, scene_t *scene)
{
    if (setting->event.key.code == sfKeyA &&
    setting->event.type == sfEvtKeyPressed)
        scene->action = ATTACK;
    if (setting->event.key.code == sfKeyZ &&
    setting->event.type == sfEvtKeyPressed)
        scene->action = DEFENSE;
}

static void game_event_three(game_set *setting, scene_t *scene)
{
    if (setting->event.key.code == sfKeyT &&
    setting->event.type == sfEvtKeyPressed) {
        texte_quete(scene->type_pnj.type_1, setting, scene->obj[13]);
        texte_quete(scene->type_pnj.type_2, setting, scene->obj[13]);
        texte_quete(scene->type_pnj.type_3, setting, scene->obj[13]);
    }
    if (setting->event.type == sfEvtKeyPressed &&
        setting->event.key.code == sfKeyI) {
        if (setting->is_pressed == 0)
            setting->is_pressed = 2;
        else
            setting->is_pressed = 0;
    }
    if (setting->event.key.code == sfKeyEscape &&
    setting->event.type == sfEvtKeyPressed)
        option(setting, scene);
}

static void game_event_bis(game_set *setting)
{
    if (setting->event.type == sfEvtClosed) {
            sfRenderWindow_close(setting->wndw);
    }
    if (setting->event.type == sfEvtMouseButtonPressed) {
        setting->buttonpress = 1;
        sfSound_play(setting->sound[0].sound);
    }
    if (setting->event.type == sfEvtKeyPressed &&
        setting->event.key.code == sfKeyJ) {
        if (setting->is_pressed == 0)
            setting->is_pressed = 1;
        else
            setting->is_pressed = 0;
    }
}

void game_event(game_set *setting, scene_t *scene)
{
    while (sfRenderWindow_pollEvent(setting->wndw, &setting->event)) {
        game_event_bis(setting);
        game_event_three(setting, scene);
        game_event_four(setting, scene);
    }
}