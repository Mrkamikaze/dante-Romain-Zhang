/*
** EPITECH PROJECT, 2023
** to test lib
** File description:
** aze
*/

#include <stddef.h>
#include <stdio.h>

#include "my.h"
#include "map.h"
#include "strings.h"

map_t *parse_map(char *path);
int solve_lab(map_t *map);
void replace_map(map_t *map);
void replace(map_t *map, int x, int y);

void show_map(map_t *map)
{
    for (int i = 0; i < map -> height; i++) {
        for (int y = 0; y < map -> width; y++) {
            my_put_nbr(map -> map[i][y]);
            putchar('\t');
        }
        putchar('\n');
    }
}

char get_char(int car)
{
    if (car == 0)
        return 'X';
    if (car == -1)
        return 'o';
    return '*';
}

void show_solved_map(map_t *map)
{
    for (int i = 0; i < map -> height; i++) {
        for (int y = 0; y < map -> width; y++) {
            putchar(get_char(map -> map[i][y]));
        }
        if (i != map -> height - 1)
            putchar('\n');
    }
}

void replace_map(map_t *map)
{
    replace(map, map -> height - 1, map -> width - 1);
    map -> map[0][0] = -1;
}

int main(int ac, char **av)
{
    map_t *map = NULL;

    if (ac != 2)
        return 84;

    map = parse_map(av[1]);

    if (map == NULL)
        return 84;

    if (!solve_lab(map)) {
        my_putstr("no solution found");
        return 84;
    }
    replace_map(map);
    show_solved_map(map);
    fflush(0);
    return 0;
}
