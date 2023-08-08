/*
** EPITECH PROJECT, 2023
** generate.c
** File description:
** generate
*/

#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "my.h"

void display_word_array(char **tab, int line, int col);

void display_perfect(char **tab, int line, int col)
{
    int lenght = 0;
    while (lenght <= line) {
        write(1, tab[lenght], col + 1);
        if (lenght != line)
            my_putchar('\n');
        lenght++;
    }
}

char **perfect_maze_carver(char **map, int y, int x, int col)
{
    int line = 0;
    int random = 0;
    while (line < y) {
        random = rand() % 8;
        if (random >= 0 && random <= 4 && col < x && line % 2 == 0 &&
            col % 2 == 1 && map[line][col + 1] != '*' && col + 1 < x)
            map[line][col + 1] = '*';
        if (random > 4 && random < 8 && line % 2 == 0 && col % 2 == 1
            && line < y && map[line + 1][col] != '*')
            map[line + 1][col] = '*';
        line++;
    }
    return map;
}

char **put_line_perfect(char **map, int y, int x, int col)
{
    map[y] = malloc(sizeof(char) * (col + 1));
    for (int i = 0; i <= col; i++) {
        if (y == 1 || x == 0 || (x % 2 == 0 && y % 2 == 1))
            map[y][x] = '*';
        else
            map[y][x] = 'X';
        x++;
    }
    return map;
}

char **generate_perfect_maze(int col, int line)
{
    int x = 0;
    int y = 0;
    srand(time(NULL));
    char **map = malloc(sizeof(char *) * line + 1);
    while (y <= line) {
        put_line_perfect(map, y, x, col);
        x = 0;
        y++;
    }
    while (x <= col) {
        if (x % 2 == 1)
            map = perfect_maze_carver(map, line, col, x);
        x++;
    }
    map[line - 1][col] = '*';
    display_perfect(map, line - 1, col);
    return map;
}
