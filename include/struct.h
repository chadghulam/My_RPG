/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** rpg h
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/Network.h>
#include <SFML/System.h>

#ifndef STRUCT_H_
#define STRUCT_H_

typedef enum object_type {
    PLAYER,
    BACKGROUND,
    OBSTACLE,
} object_type;

struct scene_t;
typedef struct scene_t scene_t;

typedef struct particle {
    unsigned int width;
    unsigned int height;
    int x[80];
    int y[80];
    int tmp;
    sfTexture *texture;
    sfSprite *sprite;
    sfUint8 *pixels;
}particle_t;

typedef struct sound_s {
    char const *ps;
    int volume;
    sfSoundBuffer *soundbuffer;
    sfSound *sound;
} sound_t;

typedef struct game_time
{
    sfClock *clock;
    float time;
    float delta;
    float prev;
    float *temp_mob;
    float temp_player;
    float temp_ennemy;
    float temp_pnj;
} game_time;

typedef struct game_set_t
{
    sfRenderWindow *wndw;
    sfEvent event;
    sfMusic *music;
    sound_t *sound;
    game_time *time;
    particle_t *pixelbuff;
    int state;
    int set_menu;
    int buttonpress;
    int option;
    int is_pressed;
    int inventory;
} game_set;

typedef struct game_button_t
{
    char *ps;
    sfVector2f pos;
    sfVector2f size;
    void (*callback)(game_set *, scene_t *);
    sfColor color;
    sfRectangleShape *rect;
} game_button;

typedef struct game_obj_t
{
    char *ps;
    sfVector2f pos;
    sfVector2f scale;
    sfIntRect rect;
    sfSprite *sprite;
    void *stats;
} game_obj;

enum states {
    QUETE,
    PROGRESS,
    FINISH,
};

typedef struct game_pnj_s {
    sfVector2f pos;
    sfVector2f pos_menu;
    sfVector2f pos_texte;
    sfTexture *texture;
    sfSprite *sprite;
    sfIntRect rect;
    sfText *quests;
    sfBool status;
    enum states quete;
    char **texte;
} game_pnj_t;

typedef struct type_pnj_s {
    game_pnj_t *type_1;
    game_pnj_t *type_2;
    game_pnj_t *type_3;
} type_pnj_t;

typedef struct init_pnj_s {
    const char *texture;
    sfIntRect rect;
    sfVector2f pos;
    sfVector2f size;
} init_pnj_t;

typedef struct game_text_t
{
    char *fontps;
    char *textps;
    sfVector2f pos;
    sfVector2f scale;
    sfText *text;
} game_text;

typedef struct game_map_t
{
    char ***map;
    int i;
    int *temp;
    sfVector2f *door;
    int random;
} game_map;

typedef struct square_map
{
    char c;
    sfIntRect rect;
    void (*select)(game_map *, sfVector2i, game_obj *);
} square_map;

typedef struct game_score_t
{
    int score;
    int tmp;
} game_score;

enum action {
    DAMAGE,
    ATTACK,
    DEFENSE,
};

typedef struct game_player_t {
    int life;
    int speed;
    int damage;
    int xp;
    int level;
    int state;
    int attack;
    int armor;
    sfIntRect rect_last;
    sfView *view;
} game_player;

// destroy
typedef struct game_view {
    sfView *view;
    sfFloatRect rect;
}game_view;

typedef struct struct_zone_attack_s {
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f post;
    sfIntRect rect;
} struct_zone_attack_t;

typedef struct struct_zone_attack_init_s {
    const char *texture;
    sfIntRect rect;
    sfVector2f post;
    sfVector2f size;
} struct_zone_attack_init_t;

typedef struct ennemy_s {
    int life;
    int post_rand_x;
    int post_rand_y;
    int last_post_x;
    int last_post_y;
    int damage;
    int direction;
    int dead;
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f post;
    sfIntRect rect;
    struct_zone_attack_t circle;
} ennemy_t;

typedef struct type_ennemy_s {
    ennemy_t *type_1;
    ennemy_t *type_2;
    ennemy_t *type_3;
} type_ennemy_t;

typedef struct init_ennemy_s {
    const char *texture;
    sfIntRect rect;
    sfVector2f post;
    sfVector2f size;
} init_ennemy_t;

typedef struct impact_s {
    int tmp;
    int mouv;
    sfFloatRect player_post;
    sfFloatRect circle_post;
    sfFloatRect ennemy_post;
    sfBool inter;
    sfBool fight;
} impact_t;

typedef struct scene_t {
    game_button *button;
    game_obj **obj;
    game_player *player;
    game_text *text;
    game_map *map;
    impact_t impact;
    type_ennemy_t type_ennemy;
    type_pnj_t type_pnj;
    int num_tow;
    int direction_player;
    bool create;
    enum action action;
} scene_t;

#endif