/*
** EPITECH PROJECT, 2023
** dante
** File description:
** to parse map
*/

#include "map.h"
#include "my.h"

#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

int add_line(int **map, char *line, int *line_n)
{
    map[*line_n] = malloc(sizeof(int) * my_strlen(line));
    for (int i = 0; line[i] != '\0' && line[i] != '\r'; i++) {
        if (line[i] == 'X') {
            map[*line_n][i] = 0;
            continue;
        }
        if (line[i] == '*') {
            map[*line_n][i] = 1;
            continue;
        }
        return 0;
    }
    return 1;
}

void remake_char(char *str)
{
    int len = my_strlen(str);
    if (str[len - 1] == '\n')
        str[len - 1] = '\0';
}

map_t *parse(FILE *file, int number_line)
{
    map_t *map_f = malloc(sizeof(map_t));
    int **map = malloc(sizeof(int *) * number_line);
    char *str = NULL;
    size_t len = 0;
    int line_len = -1;
    int line = 0;
    while (getline(&str, &len, file) != -1) {
        remake_char(str);
        if (line_len == -1)
            line_len = my_strlen(str);
        if (line_len != my_strlen(str) && number_line - 1 != line)
            return NULL;
        if (!add_line(map, str, &line))
            return NULL;
        line++;
    }
    map_f -> map = map;
    map_f -> height = number_line;
    map_f -> width = line_len;
    return map_f;
}

int get_number_line(FILE *file)
{
    int number = 0;
    char *str = NULL;
    size_t len = 0;
    while (getline(&str, &len, file) != -1)
        number++;
    return number;
}

map_t *parse_map(char *path)
{
    FILE *file = fopen(path, "r");
    int number_line;

    if (!file)
        return NULL;
    number_line = get_number_line(file);
    if (number_line == 0)
        return NULL;
    rewind(file);
    return parse(file, number_line);
}
