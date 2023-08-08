/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main for sokoban
*/

#include "my.h"

char **generate_maze(int col, int line);
char **generate_perfect_maze(int col, int line);

int letter_in_arg(char *arg)
{
    int i = 0;
    while (arg[i] != '\0') {
        if (arg[i] < '0' || arg[i] > '9')
            return - 1;
        i++;
    }
    return 0;
}

int error_handling(int ac, char **av)
{
    int i = 1;
    int j = 1;
    int k = 0;
    while (j < 3) {
        if (letter_in_arg(av[j]) != 0)
            return -1;
        j++;
    }
    if (ac < 3 || ac > 4)
        return 1;
    if (ac == 4 && my_strcmp(av[3], "perfect") != 0)
        return 1;
    while (i <= ac - 1) {
        if (my_str_to_int(av[i]) < 0)
            return 1;
        i++;
    }
    return 0;
}

int main(int ac, char **av)
{
    if (ac == 1)
        return 84;
    if (error_handling(ac,av) != 0)
        return 84;
    if (ac == 3)
        generate_maze(my_str_to_int(av[1]) - 1, my_str_to_int(av[2]));
    if (ac == 4 && my_strcmp(av[3], "perfect") == 0)
        generate_perfect_maze(my_str_to_int(av[1]) - 1, my_str_to_int(av[2]));
    return 0;
}
