/*
** EPITECH PROJECT, 2023
** generate.c
** File description:
** generate
*/

#include <stdlib.h>
#include <time.h>

#include "my.h"

void display_word_array(char **tab, int line, int col);

char **maze_carver(char **map, int y, int x, int col)
{
    int line = 0;
    int random = 0;
    while (line <= y) {
        random = rand() % 8;
        if (random >= 0 && random <= 2 && col < x)
            map[line][col + 1] = '*';
        if (random > 2 && random <= 8 && line % 2 != 0 && line < y)
            map[line + 1][col] = '*';
        line++;
    }
    return map;
}

char **put_line(char **map, int y, int x, int col)
{
    map[y] = malloc(sizeof(char) * (col) + 1);
    while (x <= col) {
        if (x % 2 == 1 && y % 2 == 0)
            map[y][x] = '*';
        else
            map[y][x] = 'X';
        if (y == 1)
            map[y][x] = '*';
        if (x == 0)
            map[y][x] = '*';
        x++;
    }
    return map;
}

char **generate_maze(int col, int line)
{
    int x = 0;
    int y = 0;
    srand(time(NULL));
    char **map = malloc(sizeof(char *) * line);
    while (y <= line) {
        put_line(map, y, x, col);
        x = 0;
        y++;
    }
    while (x <= col) {
        y = 1;
        map = maze_carver(map, line, col, x);
        x++;
    }
    map[line][col] = '*';
    display_word_array(map, line, col);
    return map;
}
