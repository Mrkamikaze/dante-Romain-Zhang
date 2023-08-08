/*
** EPITECH PROJECT, 2022
** strings.c
** File description:
** all apend beg
*/

#include <stdlib.h>

#include "strings.h"
#include "../my/my.h"

void append_beg(strings **list, char data)
{
    strings *new_list;

    new_list = malloc(sizeof(strings));
    new_list->car = data;
    new_list->next = *list;
    new_list -> last_car = new_list;
    if (*list != NULL)
        new_list -> last_car = (*list) -> last_car;
    *list = new_list;
}

void append(strings **list, char c)
{
    if (*list == NULL) {
        append_beg(list, c);
        return;
    }
    strings *tmp = (*list) -> last_car;
    strings *new;
    new = malloc(sizeof(strings));
    new -> car = c;
    new -> next = NULL;
    tmp -> next = new;
    (*list) -> last_car = new;
}

void append_str(strings **list, char *str)
{
    strings *str2;
    strings *tmp = *list;

    if (*list == NULL) {
        egal(list, str);
        return;
    }
    egal(&str2, str);
    tmp = (*list) -> last_car;
    tmp->next = str2;
    (*list) -> last_car = str2 -> last_car;
}

void append_beg_str(strings **list, char *str)
{
    strings *new_str = NULL;
    egal(&new_str, str);
    new_str -> last_car -> next = (*list);
    new_str -> last_car = (*list) -> last_car;
    (*list) = new_str;
}
