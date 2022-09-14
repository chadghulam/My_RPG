/*
** EPITECH PROJECT, 2021
** entity
** File description:
** entity
*/

#ifndef ENTITY_H_
#define ENTITY_H_

#include "struct.h"

void play(game_set *obj, scene_t *);
void option(game_set *obj, scene_t *);
void closing(game_set *obj, scene_t *);
void home(game_set *obj, scene_t *);
void sound_up(game_set *setting, scene_t *);
void reduce_sound(game_set *setting, scene_t *);
void sound_on(game_set *setting, scene_t *);
void sound_off(game_set *setting, scene_t *);
void help(game_set *setting, scene_t *);
void delet(game_set *setting, scene_t *scene);
void minor_collision(game_map *map, sfVector2i vector, game_obj *obj);
void empty_collision(game_map *map, sfVector2i vector, game_obj *obj);
void empty(game_map *map, sfVector2i vector, game_obj *obj);
void side_path(game_map *map, sfVector2i vector, game_obj *obj);
void collision_square(game_map *map, sfVector2i vector, game_obj *obj);
void empty_square(game_map *map, sfVector2i vector, game_obj *obj);

static const game_button btn_fix[] = {
    {"sprite/play_green.png", {800, 500}, {350, 150}, &play,
    {255, 0, 0, 255}, 0},
    {"sprite/exit_red.png",  {812, 700}, {325, 150}, &closing,
    {255, 0, 0, 255}, 0},
    {"sprite/reglages_green.png", {25, 25}, {150, 150}, &option,
    {255, 0, 0, 255}, 0},
    {"sprite/instructions_green.png", {1750, 25}, {145, 145}, &help,
    {255, 0, 0, 255}, 0},
    {"sprite/plus_gris.png", {900, 640}, {150, 150}, &sound_up,
    {255, 0, 0, 255}, 0},
    {"sprite/moins_gris.png", {1120, 640}, {150, 150}, &reduce_sound,
    {255, 0, 0, 255}, 0},
    {"sprite/son_on.png", {900, 440}, {150, 150}, &sound_on,
    {255, 0, 0, 255}, 0},
    {"sprite/button_muted.png", {1120, 440}, {150, 150}, &sound_off,
    {255, 0, 0, 255}, 0},
    {"sprite/fermer_green.png", {1450, 200}, {150, 150}, &home,
    {255, 0, 0, 255}, 0},
    {"sprite/croix.png", {1450, 200}, {150, 150}, &delet,
    {255, 0, 0, 255}, 0},
};

static const init_ennemy_t ennemy_fix[] = {
    {"sprite/ennemie1.png",
    {0, 0, 15, 15}, {400, 470}, {2, 2}},
    {"sprite/ennemie2.png",
    {0, 0, 15, 15}, {400, 470}, {2, 2}},
    {"sprite/boss.png",
    {0, 0, 15, 15}, {400, 470}, {4, 4}},
};

static const init_pnj_t pnj_fix[] = {
    {"sprite/PNJ1.png",
    {0, 0, 16, 16}, {935, 570}, {1.5, 1.5}},
    {"sprite/PNJ2.png",
    {0, 0, 16, 16}, {860, 515}, {1.5, 1.5}},
    {"sprite/PNJ3.png",
    {0, 0, 16, 16}, {1010, 515}, {1.5, 1.5}},
};

static const struct_zone_attack_init_t zone_attack = {
    "sprite/circle.png", {0, 0, 400, 400}, {0, 0}, {1, 1}
};

static const game_text txt_fix[] = {
    {"sprite/font.ttf", "GAME", {800, 400}, {5, 5}, 0},
    {"sprite/font.ttf", "1", {1750, 20}, {1.5, 1.5}, 0},
    {"sprite/font.ttf", "30", {1520, 20}, {1.2, 1.2}, 0},
    {"sprite/font.ttf", "1000", {1300, 20}, {1.2, 1.2}, 0},
    {"sprite/font.ttf", "You Lose !", {700, 450}, {3, 3}, 0},
    {"sprite/font.ttf", "You Win !", {700, 450}, {3, 3}, 0},
    {"sprite/font.ttf", "Speed", {700, 450}, {0.8, 0.8}, 0},
    {"sprite/font.ttf", "Armor", {700, 450}, {0.8, 0.8}, 0},
    {"sprite/font.ttf", "Damage", {700, 450}, {0.8, 0.8}, 0},
    {"sprite/font.ttf", "Health", {700, 450}, {0.8, 0.8}, 0},
};

static const sound_t sound_fix[] = {
    {"sprite/click.ogg", 100, 0, 0},
    {"sprite/buy.ogg", 100, 0, 0},
    {"sprite/tower.ogg", 100, 0, 0},
    {"sprite/game_over.ogg", 100, 0, 0},
    {"sprite/win.ogg", 100, 0, 0},
    {"sprite/hit_mob1.ogg", 100, 0, 0},
    {"sprite/saber_cut.ogg", 100, 0, 0},
    {"sprite/hit_char.wav", 100, 0, 0},
    {"sprite/shield.ogg", 100, 0, 0},
};

static const square_map tab[] =
{
    {'r', {16*0, 16*5, 16*1, 16*1}, &empty},
    {'r', {16*15, 16*5, 16*1, 16*1}, &empty},
    {'r', {16*16, 16*5, 16*1, 16*1}, &empty},
    {'r', {16*17, 16*5, 16*1, 16*1}, &empty},
    {'b', {16*3, 16*5, 16*1, 16*1}, &empty},
    {'b', {16*13, 16*5, 16*1, 16*1}, &empty},
    {'t', {16*14, 16*5, 16*1, 16*1}, &empty},
    {'t', {16*2, 16*6, 16*1, 16*1}, &empty},
    {'j', {16*4, 16*5, 16*1, 16*1}, &empty},
    {'b', {16*1, 16*6, 16*1, 16*1}, &empty},
    {'h', {16*17, 16*0, 16*1, 16*1}, &empty},
    {'g', {16*0, 16*0, 16*1, 16*1}, &empty},
    {'g', {16*0, 16*0, 16*1, 16*1}, &empty},
    {'g', {16*0, 16*0, 16*1, 16*1}, &empty},
    {'w', {16*1, 16*5, 16*1, 16*1}, &empty},
    {'w', {16*2, 16*5, 16*1, 16*1}, &empty},
    {'f', {16*9, 16*5, 16*1, 16*1}, &empty},
    {'f', {16*10, 16*5, 16*1, 16*1}, &empty},
    {'f', {16*11, 16*5, 16*1, 16*1}, &empty},
    {'f', {16*12, 16*5, 16*1, 16*1}, &empty},
    {'C', {0, 0, 0, 0}, &minor_collision},
    {'G', {0, 0, 0, 0}, &empty_collision},
    {'D', {16*2, 16*0, 16*1, 16*1}, &empty},
    {'P', {16*1, 16*0, 16*1, 16*1}, &empty},
    {'p', {16*2, 16*0, 16*1, 16*1}, &side_path},
    {'S', {16*0, 16*6, 16*1, 16*1}, &empty},
    {'0', {16*17, 16*0, 16*1, 16*1}, &empty},
    {'1', {16*17, 16*0, 16*1, 16*1}, &empty},
    {'2', {16*17, 16*0, 16*1, 16*1}, &empty},
    {'3', {16*17, 16*0, 16*1, 16*1}, &empty},
    {'i', {16*6, 16*5, 16*1, 16*1}, &empty},
    {'j', {16*7, 16*5, 16*1, 16*1}, &empty},
    {'k', {16*8, 16*5, 16*1, 16*1}, &empty},
    {'M', {16*1 - 4, 16*4, 16*1, 16*1}, &empty},
    {'N', {16*0, 16*4, 16*1, 16*1}, &empty},
    {'U', {16*9, 16*12, 16*1, 16*1}, &empty_square},
    {'R', {16*9, 16*6, 16, 16}, &collision_square},
    {'U', {16*9, 16*12, 16*1, 16*1}, &empty},
    {'U', {16*9, 16*12, 16*1, 16*1}, &empty},
    {'U', {16*9, 16*12, 16*1, 16*1}, &empty},
    {'V', {16*9, 16*11, 16, 16}, &empty},
    {'W', {16*8, 16*11, 16, 16}, &empty},
    {'X', {16*8, 16*12, 16, 16}, &empty},
    {'Y', {16*7, 16*11, 16, 16}, &empty},
    {'Y', {16*7, 16*11, 16, 16}, &empty},
    {'Y', {16*7, 16*11, 16, 16}, &empty},
    {'R', {16*9, 16*6, 16, 16}, &empty},
    {'T', {16*10, 16*6, 16, 16}, &empty},
};

#endif
