/*
** EPITECH PROJECT, 2022
** display_word_array.c
** File description:
** display_word_array
*/

#include "my.h"
#include <stddef.h>
#include <unistd.h>

void display_word_array(char **tab, int line, int col)
{
    int lenght = 1;
    while (lenght <= line) {
        write(1, tab[lenght], col + 1);
        if (lenght != line)
            my_putchar('\n');
        lenght++;
    }
}
