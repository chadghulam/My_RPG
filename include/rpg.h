/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-2-myrpg-laetitia.bousch
** File description:
** rpg
*/

#ifndef RPG_H_
#define RPG_H_

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <SFML/Audio.h>

#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <stdbool.h>

enum states {
    DAMAGE,
    ATTACK,
    DEFENSE,
};

typedef struct perso_tempo_s {
    int life;
    enum states fight;
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f post;
    sfIntRect rect;
} perso_tempo_t;

void fighting_game();

#endif /* !RPG_H_ */