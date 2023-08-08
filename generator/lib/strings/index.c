/*
** EPITECH PROJECT, 2022
** index.c
** File description:
** index manadgement for strings lib
*/

#include <stddef.h>

#include "strings.h"
#include "../my/my.h"

char get(strings *string, int index)
{
    strings *temp = string;
    if (string == NULL || len(string) <= index || index < 0) {
        return 0;
    }
    for (int i = 0; i != index; i++) {
        temp = temp -> next;
    }
    return temp -> car;
}

int set(strings *string, int index, char car)
{
    strings *temp = string;
    if (string == NULL || len(string) <= index || index < 0) {
        return 0;
    }
    for (int i = 0; i != index; i++) {
        temp = temp -> next;
    }
    temp -> car = car;
    return 1;
}

char get_last(strings *string)
{
    while (string -> next != NULL) {
        string = string -> next;
    }
    return string -> car;
}

int remove_s(strings **string, int index)
{
    strings *temp = *string;
    int nbr = 0;
    if (*string == NULL || len(*string) <= index || index < 0)
        return 0;
    if (index == 0) {
        *string = temp->next;
    }
    nbr = len(*string) - 1;
    if (index == nbr) {
        for (int i = 0; i < nbr - 1; i++) {
            temp = temp -> next;
        }
        temp -> next = NULL;
        return 1;
    }
    for (int i = 0; i < index - 1; i++) {
        temp = temp -> next;
    }
    temp -> next = temp -> next -> next;
    return 1;
}
