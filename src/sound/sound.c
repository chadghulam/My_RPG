/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** sound.c
*/

#include "my_rpg.h"

void reduce_sound(game_set *setting, scene_t *scene)
{
    float volume = sfMusic_getVolume(setting->music);

    (void) scene;
    if (volume >= 10 && sfMusic_getStatus(setting->music) == sfPlaying)
        sfMusic_setVolume(setting->music, volume - 10);
}

void sound_up(game_set *setting, scene_t *scene)
{
    float volume = sfMusic_getVolume(setting->music);

    (void) scene;
    if (volume < 90 && sfMusic_getStatus(setting->music) == sfPlaying)
        sfMusic_setVolume(setting->music, volume + 10);
}

void sound_on(game_set *setting, scene_t *scene)
{
    (void) scene;
    if (sfMusic_getStatus(setting->music) == sfStopped)
        sfMusic_play(setting->music);
}

void sound_off(game_set *setting, scene_t *scene)
{
    (void) scene;
    if (sfMusic_getStatus(setting->music) == sfPlaying)
        sfMusic_stop(setting->music);
}

void destroy_sound(game_set *setting)
{
    for (int i = 0; i < 9; i++) {
        sfSound_destroy(setting->sound[i].sound);
        sfSoundBuffer_destroy(setting->sound[i].soundbuffer);
    }
}