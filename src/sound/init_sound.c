/*
** EPITECH PROJECT, 2021
** sound
** File description:
** init_sound
*/

#include "my_rpg.h"

sound_t *create_entity_sound(void)
{
    sound_t *entity_sound = malloc(sizeof(sound_t) * 9);

    for (int i = 0; i < 9; i++)
        entity_sound[i] = init_sound(sound_fix[i]);
    return entity_sound;
}

sound_t init_sound(sound_t sound)
{
    sound.soundbuffer = sfSoundBuffer_createFromFile(sound.ps);
    sound.sound = sfSound_create();
    sfSound_setBuffer(sound.sound, sound.soundbuffer);
    sfSound_setVolume(sound.sound, sound.volume);

    return sound;
}