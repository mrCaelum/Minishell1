/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2018
** File description:
** Exit
*/

#include "minishell1.h"

static const char const *invalid_exit = "exit: Expression Syntax.\n";

static int get_nbr(char const *str)
{
    int result = 0;

    for (int i = 0; str[i]; i++) {
        if (str[i] < '0' || str[i] > '9' || result > 99)
            return (0);
        result = result * 10 + str[i] - '0';
    }
    return (result);
}

static unsigned char is_only_num(char const *str)
{
    for (unsigned char i = 0; str[i]; i++)
        if (str[i] < '0' || str[i] > '9')
            return (0);
    return (str ? 1 : 0);
}

int func_exit(char **entery)
{
    if (entery[1]) {
        if (!entery[2] && is_only_num(entery[1]))
            return (get_nbr(entery[1]));
        write(2, invalid_exit, str_length(invalid_exit));
        return (-1);
    }
    return (0);
}
