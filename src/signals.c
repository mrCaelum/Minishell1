/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2018
** File description:
** Signal
*/

#include "minishell1.h"

void signal_exit(void)
{
    write(1, "\n", 1);
}
