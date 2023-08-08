/*
** EPITECH PROJECT, 2023
** dante
** File description:
** to replace c
*/

#include "map.h"
#include "my.h"

void replace(map_t *map, int x, int y);

int is_replacable(map_t *map, int x, int y)
{
    if (x < 0 || x >= map->height)
        return 0;
    if (y < 0 || y >= map->width)
        return 0;
    if (map -> map[x][y] == 1)
        return 0;
    if (map -> map[x][y] == 0)
        return 0;
    if (map -> map[x][y] == -1)
        return 0;
    return 1;
}

int get_nbr_rep(map_t *map, int x, int y)
{
    if (is_replacable(map, x, y))
        return map -> map[x][y];
    return -1;
}

int is_min(map_t *map, int x, int y, int nbr)
{
    int actu = get_nbr_rep(map, x, y);
    if (actu == -1)
        return 0;
    if (map -> map[x][y] < nbr)
        return 1;
    return 0;
}

int run_replace(map_t *map, int x, int y)
{
    int min = map -> map[x][y];
    int xf = x;
    int yf = y;

    if (is_min(map, x + 1, y, min)) {
        min = map -> map[x + 1][y], xf = x + 1, yf = y;
    }
    if (is_min(map, x, y + 1, min)) {
        min = map -> map[x][y + 1], xf = x, yf = y + 1;
    }
    if (is_min(map, x - 1, y, min)) {
        min = map -> map[x - 1][y], xf = x - 1, yf = y;
    }
    if (is_min(map, x, y - 1, min)) {
        min = map -> map[x][y - 1], xf = x, yf = y - 1;
    }
    replace(map, xf, yf);
}

void replace(map_t *map, int x, int y)
{
    if (map -> map[x][y] == 2)
        return;
    map -> map[x][y] = 99999;
    run_replace(map, x, y);
    map -> map[x][y] = -1;
}
