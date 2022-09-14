/*
** EPITECH PROJECT, 2021
** load_file_in_mem
** File description:
** load_file_in_mem
*/

#include "my_rpg.h"

char **load_file_in_mem(char const *filepath)
{
    char **buffer = malloc(sizeof(char *) * 38);
    size_t line_buf_size = 0;
    FILE *fd = fopen(filepath, "r");
    int i = 0;

    if (!fd)
        return NULL;
    buffer[i] = NULL;
    for (; getline(&buffer[i], &line_buf_size, fd) >= 0; buffer[++i] = NULL);
    buffer[i] = NULL;
    fclose(fd);

    return buffer;
}
