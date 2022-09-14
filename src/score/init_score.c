/*
** EPITECH PROJECT, 2021
** score
** File description:
** score
*/

#include "my_rpg.h"

void init_score(void)
{
    game_score *score = malloc(sizeof(game_score));

    score->score = 0;
    score->tmp = 0;
}

void draw_lvl(game_text text, game_obj *obj, game_set *setting, int lvl)
{
    if (setting->state == 2) {
        sfText_setString(text.text, my_nbrtostr(lvl));
        sfRenderWindow_drawText(setting->wndw, text.text, NULL);
        sfRenderWindow_drawSprite(setting->wndw, obj->sprite, NULL);
    }
    if (setting->state == 1)
        lvl = 1;
}

void draw_speed(game_text text, game_set *setting, int speed)
{
    if (setting->state == 2) {
        sfText_setString(text.text, my_nbrtostr(speed));
        sfRenderWindow_drawText(setting->wndw, text.text, NULL);
    }
    if (setting->state == 1)
        speed = 100;
}

void draw_damage(game_text text, game_set *setting, int damage)
{
    if (setting->state == 2) {
        sfText_setString(text.text, my_nbrtostr(damage));
        sfRenderWindow_drawText(setting->wndw, text.text, NULL);
    }
    if (setting->state == 1)
        damage = 1;
}

void draw_life(game_text text, game_obj *obj, game_set *setting, int life)
{
    if (setting->state == 2) {
        sfText_setString(text.text, my_nbrtostr(life));
        sfRenderWindow_drawText(setting->wndw, text.text, NULL);
        sfRenderWindow_drawSprite(setting->wndw, obj->sprite, NULL);
    }
    if (setting->state == 1)
        life = 100;
    if (life <= 0) {
        if (setting->state != 4)
            sfSound_play(setting->sound[3].sound);
        setting->state = 4;
    }
}