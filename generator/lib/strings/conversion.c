/*
** EPITECH PROJECT, 2022
** strings.h
** File description:
** file for conversion
*/

#include <stdlib.h>
#include "strings.h"
#include "../my/my.h"

int is_digit(char *str);
char *to_string(strings *list)
{
    int i = 0;
    char *end_string = malloc(sizeof(char) * len(list));
    strings *tmp = list;
    while (tmp != NULL) {
        end_string[i] = tmp->car;
        tmp = tmp -> next;
        i++;
    }
    end_string[i] = '\0';
    return end_string;
}

int to_int(strings *list)
{
    int is_neg = 0;
    char *str = to_string(list);

    if (!(my_str_isnum(str)))
        return -1;
    return my_str_to_int(str);
}

char *my_int_to_str(int nbr)
{
    strings *string;
    int is_neg = 0;
    egal(&string, "");
    if (nbr < 0) {
        is_neg = 1;
        nbr = nbr * -1;
    }
    while (nbr > 9) {
        append_beg(&string, (nbr % 10) + 48);
        nbr = nbr / 10;
    }
    append_beg(&string, nbr + 48);
    if (is_neg)
        append_beg(&string, '-');
    return to_string(string);
}

char *my_unsignedint_to_str(unsigned int nbr)
{
    strings *string;
    egal(&string, "");
    while (nbr > 9) {
        append_beg(&string, (nbr % 10) + 48);
        nbr = nbr / 10;
    }
    append_beg(&string, nbr + 48);
    return to_string(string);
}
