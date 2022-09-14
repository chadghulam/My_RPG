/*
** EPITECH PROJECT, 2021
** framebuffer.h
** File description:
** framebuffer
*/

#ifndef MY_RPG_H_
#define MY_RPG_H_

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <fcntl.h>
#include <time.h>
#include <math.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/Network.h>
#include <SFML/System.h>
#include "my.h"
#include "struct.h"
#include "entity.h"

void destroy_object(game_obj *obj);
bool check_colls_tower(sfVector2f pos1, sfVector2f pos2, int r1);

//rpg
game_set *init_setting(void);
int rpg(void);

//man
int man(void);

//error
int handle_error(int ac, char **env);

//event
void create_wndw(unsigned width, unsigned height, char *titl, game_set *obj);
void game_event(game_set *obj, scene_t *scene);

//end
void draw_lose(game_set *setting, scene_t *scene);
void draw_win(game_set *setting, scene_t *scene);

//sound
sound_t *create_entity_sound(void);
sound_t init_sound(sound_t sound);
void menu_music(game_set *obj, char *ps);
void destroy_sound(game_set *setting);

//text
game_text *create_entity_text();
game_text create_text(game_text text);
void intro_text(game_set *setting, scene_t *scene);

//score
void score(game_set *setting, scene_t *scene);
void draw_gold(game_text text, game_obj *obj, game_set *setting, int gold);
void draw_life(game_text text, game_obj *obj, game_set *setting, int life);
void draw_lvl(game_text text, game_obj *obj, game_set *setting, int lvl);
void draw_speed(game_text text, game_set *setting, int speed);
void draw_damage(game_text text, game_set *setting, int damage);
void draw_armor(game_text text, game_set *setting, int armor);

//object
game_obj **create_entity_object();
game_obj *init_object(game_obj *obj);
void draw_banderole(game_set *setting, scene_t *scene);

//button
game_button *create_entity_button();
game_button init_button(game_button button);
void display_menu_button(game_button button, game_set *obj, scene_t *);
void button_event(game_set *obj, game_button button);
int button_is_select(game_button button, sfVector2i click_position);

//map
void init_map(sfRenderWindow *wndw, scene_t *scene);
char **load_file_in_mem(char const *filepath);
game_map *create_map(char **buffer);

//time
game_time *init_time(void);
void global_time(game_time *time);

//player
void init_player(game_obj *obj, game_player stats_player);
void player(game_obj *player, game_set *setting, game_map *map,
            scene_t *scene);
int collision_player(game_map *map, game_obj *player, float time_delta,
sfVector2f pos);
void event_player(game_obj *player, game_time *time, scene_t *scene);
void display_player(game_obj *player, sfVector2f pos_last,
game_time *time, scene_t *scene);
void level_up(game_obj *player);

//mob
void display_mob(sfRenderWindow *wndw, scene_t *scene);
void speed_mob(scene_t *scene, int count);
void path_move(game_map *map, int i);
void reset_mob(scene_t *scene, int i);
void kill_mob(scene_t *scene, int i);

//scene
scene_t *init_scene(void);
void display_scene(game_set *obj, scene_t *scene);
void draw_game(game_set *setting, scene_t *scene);
void draw_option(game_set *obj, scene_t *scene);
void draw_help(game_set *setting, scene_t *scene);
void draw_stats(game_set *setting, scene_t *scene);
void draw_stage(game_set *setting, scene_t *scene);
void menu(game_set *obj, scene_t *scene);
void menu_game(game_obj *entity, game_text **text, game_set *obj);
void start_game(game_obj *entity, game_text *text, game_set *obj);
void end_game(game_obj *entity, game_text *text, game_set *obj);

// callback function
void play(game_set *obj, scene_t *);
void option(game_set *obj, scene_t *);
void closing(game_set *obj, scene_t *);
void home(game_set *obj, scene_t *);
void sound_up(game_set *setting, scene_t *);
void reduce_sound(game_set *setting, scene_t *);
void sound_on(game_set *setting, scene_t *);
void sound_off(game_set *setting, scene_t *);
void help(game_set *setting, scene_t *);

//free
void destroy_scene(scene_t *scene);
void destroy_pnj(type_pnj_t *type_pnj);
void destroy_setting(game_set *setting);
void destroy_ennemy(type_ennemy_t *type_ennemy);

int click_event(game_set *obj);

// camera
void init_view(game_obj **obj);
void move_view(game_set *settings, game_obj *player);
void hud_view(game_set *setting, scene_t *scene);

//inventory
void draw_inventory(game_set *setting, scene_t *scene);
void draw_weapon(game_set *setting, scene_t *scene);
void recup_item(scene_t *scene, game_set *setting);
void dop_item_quests_one(scene_t *scene, game_set *setting);
void dop_item_quests_two(scene_t *scene, game_set *setting);
int equip_item(scene_t *scene);


//particle_generator
particle_t *pixelbuffer_create(unsigned int width, unsigned int height);
void particle_generator(game_set *setting);
void particle_rain(game_set *set);
void clear_pixel(game_set *set);
void draw_disque(particle_t *pixelbuff, sfVector2i C, int radius, sfColor clr);
void draw_line(particle_t *pixelbuff, sfVector2i a, sfVector2i b, sfColor clr);
void my_put_pixel(particle_t *pixelbuff, unsigned int x, unsigned int y,
sfColor color);

// attack
void attack_ennemy(scene_t *scene, game_set *setting, ennemy_t *type);

// bouclier
void bouclier_ennemy(scene_t *scene, game_set *setting, ennemy_t *type);

// mouv_ennemy
void mouv_ennemy(int i, ennemy_t *type);

// init_ennemy
impact_t create_struct_impact(void);
type_ennemy_t create_type_ennemy(void);

// ennemy
void ennemy(scene_t *scene, game_set *setting, ennemy_t *type);
void boss(scene_t *scene, game_set *setting, ennemy_t *type);
void impact_game(ennemy_t *type, game_obj *player,
                impact_t *impact, int i);
void zone_ennemy(scene_t *scene, game_set *setting,
                int i, ennemy_t *type);
void display_ennemy(ennemy_t *type, int i, game_set *setting);
void game_fight(ennemy_t *type, int i, scene_t *scene,
                        game_set *setting);

// init_circle_ennemy
struct_zone_attack_t init_circle_post(ennemy_t *ennemy);

// damage
void damage_ennemy(scene_t *scene, game_set *setting, ennemy_t *type);
int one_damage_ennemy_bis(scene_t *scene, game_set *setting,
                                ennemy_t *type);
int two_damage_ennemy_bis(scene_t *scene, game_set *setting,
                                ennemy_t *type);
int three_damage_ennemy_bis(scene_t *scene, game_set *setting,
                                ennemy_t *type);
int four_damage_ennemy_bis(scene_t *scene, game_set *setting,
                                ennemy_t *type);

// init_pnj
type_pnj_t create_type_pnj(void);
game_pnj_t *init_type_pnj_pr(init_pnj_t const *pnj_fix,
                            const char **text);

// pnj
void texte_quete(game_pnj_t *pnj, game_set *setting, game_obj *player);
void texte_quete_pnj(game_pnj_t *pnj, game_set *setting, game_obj *player);
void pnj(game_obj *player, type_pnj_t type_pnj, game_set *setting,
game_obj *menu);
void move_pnj(game_pnj_t *pnj, game_set *setting);

// quests
void quests_finish(type_pnj_t type_pnj);
void status_map_ennemy(ennemy_t *ennemy, game_pnj_t *pnj);

// player_event
void event_attack(game_obj *player, game_time *time, scene_t *scene);
void event_defense(game_obj *player, game_time *time, scene_t *scene);


#endif