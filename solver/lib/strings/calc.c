/*
** EPITECH PROJECT, 2022
** strings
** File description:
** for all logique operator
*/

#include "strings.h"
#include <stddef.h>

int contain(strings *str, char car)
{
    strings *tmp = str;
    while (tmp != NULL) {
        if (tmp->car == car) {
            return 1;
        }
        tmp = tmp->next;
    }
    return 0;
}
