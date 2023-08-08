/*
** EPITECH PROJECT, 2023
** dante
** File description:
** to solve lab
*/

#include "map.h"
#include "my.h"

int get_nbr(map_t *map, int x, int y)
{
    if (x < 0 || x >= map->height)
        return -1;
    if (y < 0 || y >= map->width)
        return -1;
    if (map -> map[x][y] == 0)
        return -1;
    if (map -> map[x][y] == 1)
        return -1;
    return map -> map[x][y];
}

int get_min_arround(map_t *map, int x, int y)
{
    int min = -1;
    int actu = -1;
    actu = get_nbr(map, x - 1, y);
    if (actu != -1 && actu < min || min == -1 && actu != -1)
        min = actu;
    actu = get_nbr(map, x + 1, y);
    if (actu != -1 && actu < min || min == -1 && actu != -1)
        min = actu;
    actu = get_nbr(map, x, y + 1);
    if (actu != -1 && actu < min || min == -1 && actu != -1)
        min = actu;
    actu = get_nbr(map, x, y - 1);
    if (actu != -1 && actu < min || min == -1 && actu != -1)
        min = actu;
    return min;
}

int is_position(map_t *map, int x, int y, int nbr)
{
    if (x < 0 || x >= map->height)
        return 0;
    if (y < 0 || y >= map->width)
        return 0;
    if (nbr > map -> map[x][y] && map -> map[x][y] != 0) {
        return 1;
    }
    if (map -> map[x][y] != 1)
        return 0;
    return 1;
}

void solve(map_t *map, int x, int y)
{
    int nbr;
    nbr = get_min_arround(map, x, y);
    if (map -> map[map->height - 1][map->width - 1] != 1)
        return;
    if (nbr == -1)
        return;
    if (x == map->width - 1 && y == map->height - 1) {
        map -> map[x][y] = nbr;
        return;
    }
    map -> map[x][y] = nbr + 1;
    if (is_position(map, x, y + 1, nbr))
        solve(map, x, y + 1);
    if (is_position(map, x + 1, y, nbr))
        solve(map, x + 1, y);
    if (is_position(map, x - 1, y, nbr))
        solve(map, x - 1, y);
    if (is_position(map, x, y - 1, nbr))
        solve(map, x, y - 1);
}

int solve_lab(map_t *map)
{
    if (!map -> map[0][0] || !map -> map[map->height - 1][map->width - 1])
        return 0;
    map -> map[0][0] = 2;
    solve(map, 0, 1);
    solve(map, map->height - 1, map->width - 1);
    if (map -> map[map -> height - 1][map -> width - 1] == 1)
        return 0;
    return 1;
}
