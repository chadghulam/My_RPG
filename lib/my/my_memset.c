/*
** EPITECH PROJECT, 2021
** my_memset
** File description:
** remplissage d'une string
*/

char *my_memset(char *str, int a, int n)
{
    int i = 0;

    while (i < n) {
        str[i] = a;
        i++;
    }
    return (str);
}
